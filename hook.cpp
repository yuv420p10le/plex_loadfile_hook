#include "hook.hpp"

#include <MinHook.h>
#include <format>
#include <regex>

#if _DEBUG
#include <print>
#endif

decltype(&mpv_command_node) _mpv_command_node;
decltype(&mpv_command_string) _mpv_command_string;

uintptr_t get_func_address(std::string_view lib, std::string_view func)
{
	auto mod = GetModuleHandleA(lib.data());

	if(mod == nullptr)
	{
		mod = LoadLibraryA(lib.data());
	}

	return reinterpret_cast<uintptr_t>(GetProcAddress(mod, func.data()));
}

#if _DEBUG
void print_node_list(mpv_node_list* list)
{
	std::println("num_args: {}", list->num);

	for(std::size_t i = 0; i < list->num; i++)
	{
		if(list->values[i].format == MPV_FORMAT_STRING)
		{
			std::println("{} {} -> {}", i, (list->keys != nullptr && list->keys[i] != nullptr) ? list->keys[i] : "(null)", list->values[i].u.string);
		}

		else if(list->values[i].format == MPV_FORMAT_NODE_MAP || list->values[i].format == MPV_FORMAT_NODE_ARRAY)
		{
			print_node_list(list->values[i].u.list);
		}

		else
		{
			std::println("{}: {} -> {}", i, list->keys[i], static_cast<int>(list->values[i].format));
		}
	}
}
#endif

int hook_mpv_command_node(mpv_handle* ctx, mpv_node* args, mpv_node* result)
{
	// Plex calls `loadfile <url> replace <some byte array>` and that is unnecessary & doesn't work. We only need the first argument; which is the playback URL with access tokens.
	const auto& list = args->u.list;

#if _DEBUG
	std::println("mpv_command_node({:08X}, {}, {});", reinterpret_cast<uintptr_t>(ctx), static_cast<int>(args->format), reinterpret_cast<uintptr_t>(result));

	if(args->format == MPV_FORMAT_NODE_ARRAY)
	{
		print_node_list(list);
	}
#endif

	if(args->format == MPV_FORMAT_NODE_ARRAY && list->num == 4 && list->values[0].format == MPV_FORMAT_STRING && std::string_view(list->values[0].u.string) == "loadfile")
	{
		auto url = std::string(list->values[1].u.string);

		// Required for <ip>.<hash>.plex.direct support
		if(url.contains(".plex.direct"))
		{
			std::regex regex("(https?://)([^:/]+)(:[0-9]+)?(.*)");
			std::smatch match;

			if(std::regex_match(url, match, regex))
			{
				std::string new_url = match.str(1);
				std::string hostname = match.str(2);
				std::string ip(hostname.substr(0, hostname.find('.')));
				std::replace(ip.begin(), ip.end(), '-', '.');

				new_url += ip;

				// Port
				if(match.str(3).length() > 0)
				{
					new_url += match.str(3);
				}

				// Path/query
				new_url += match.str(4);
				url = new_url;
			}
		}

		return _mpv_command_string(ctx, std::format("loadfile {} replace", url).c_str());
	}

	return _mpv_command_node(ctx, args, result);
}

void hook()
{
	_mpv_command_node = reinterpret_cast<decltype(&mpv_command_node)>(get_func_address("mpv-2.dll", "mpv_command_node"));
	_mpv_command_string = reinterpret_cast<decltype(&mpv_command_string)>(get_func_address("mpv-2.dll", "mpv_command_string"));

#if _DEBUG
	AllocConsole();
	freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);

	std::println("mpv_command_node: {:08X}", reinterpret_cast<uintptr_t>(_mpv_command_node));
#endif

	MH_Initialize();
	MH_CreateHook(reinterpret_cast<void*>(_mpv_command_node), &hook_mpv_command_node, reinterpret_cast<void**>(&_mpv_command_node));
	MH_EnableHook(MH_ALL_HOOKS);
}
