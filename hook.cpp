#include "hook.hpp"

#include <MinHook.h>
#include <format>

#if _DEBUG
#include <iostream>
#endif

decltype(&mpv_command_node) _mpv_command_node;

uintptr_t get_func_address(std::string_view lib, std::string_view func)
{
	auto mod = GetModuleHandleA(lib.data());

	if(mod == nullptr)
	{
		mod = LoadLibraryA(lib.data());
	}

	return reinterpret_cast<uintptr_t>(GetProcAddress(mod, func.data()));
}

int hook_mpv_command_node(mpv_handle* ctx, mpv_node* args, mpv_node* result)
{
	// Plex calls `loadfile <url> replace <some byte array>` and that is unnecessary & doesn't work. We only need the first argument; which is the playback URL with access tokens.
	const auto& list = args->u.list;

	if(args->format == MPV_FORMAT_NODE_ARRAY)
	{
		if(list->values[0].format == MPV_FORMAT_STRING && std::string_view(list->values[0].u.string) == "loadfile")
		{
			list->num = 2;
		}
	}

#if _DEBUG
	std::cout << std::format("mpv_command_node({:08X}, {}, {});\n", reinterpret_cast<uintptr_t>(ctx), static_cast<int>(args->format), reinterpret_cast<uintptr_t>(result));

	if(args->format == MPV_FORMAT_NODE_ARRAY)
	{
		std::cout << std::format("num_args: {}\n", list->num);

		for(std::size_t i = 0; i < list->num; i++)
		{
			if(list->values[i].format == MPV_FORMAT_STRING)
			{
				std::cout << std::format("{}: {}\n", i, list->values[i].u.string);
			}

			else
			{
				std::cout << std::format("{}: {}\n", i, static_cast<int>(list->values[i].format));
			}
		}
	}
#endif

	return _mpv_command_node(ctx, args, result);
}

void hook()
{
	_mpv_command_node = reinterpret_cast<decltype(&mpv_command_node)>(get_func_address("mpv-2.dll", "mpv_command_node"));

#if _DEBUG
	AllocConsole();
	freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);

	std::cout << std::format("mpv_command_node: {:08X}\n", reinterpret_cast<uintptr_t>(_mpv_command_node));
#endif

	MH_Initialize();
	MH_CreateHook(reinterpret_cast<void*>(_mpv_command_node), &hook_mpv_command_node, reinterpret_cast<void**>(&_mpv_command_node));
	MH_EnableHook(MH_ALL_HOOKS);
}
