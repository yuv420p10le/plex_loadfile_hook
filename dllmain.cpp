#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "proxy.hpp"
#include "hook.hpp"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if(ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        hook();
    }

    return TRUE;
}

