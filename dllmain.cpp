#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "proxy.hpp"
#include "hook.hpp"

BOOL APIENTRY DllMain([[maybe_unused]] HMODULE hModule, DWORD ul_reason_for_call, [[maybe_unused]] LPVOID lpReserved)
{
    if(ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        hook();
    }

    return TRUE;
}

