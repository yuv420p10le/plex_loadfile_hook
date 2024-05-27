#pragma once

#include <string>
#include "client.h"

uintptr_t get_func_address(std::string_view lib, std::string_view func);

#if _DEBUG
void print_node_list(mpv_node_list* list);
#endif

int hook_mpv_command_node(mpv_handle* ctx, mpv_node* args, mpv_node* result);
void hook();
