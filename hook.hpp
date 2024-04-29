#pragma once

#include <cstdint>
#include <string>
#include "client.h"

uintptr_t get_func_address(std::string_view lib, std::string_view func);
int hook_mpv_command_node(mpv_handle* ctx, mpv_node* args, mpv_node* result);
void hook();
