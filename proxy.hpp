#pragma once

#ifdef _WIN64
#define DLLPATH "\\\\.\\GLOBALROOT\\SystemRoot\\System32\\d3d11.dll"
#else
#define DLLPATH "\\\\.\\GLOBALROOT\\SystemRoot\\SysWOW64\\d3d11.dll"
#endif

#pragma comment(linker, "/EXPORT:CreateDirect3D11DeviceFromDXGIDevice=" DLLPATH ".CreateDirect3D11DeviceFromDXGIDevice")
#pragma comment(linker, "/EXPORT:CreateDirect3D11SurfaceFromDXGISurface=" DLLPATH ".CreateDirect3D11SurfaceFromDXGISurface")
#pragma comment(linker, "/EXPORT:D3D11CoreCreateDevice=" DLLPATH ".D3D11CoreCreateDevice")
#pragma comment(linker, "/EXPORT:D3D11CoreCreateLayeredDevice=" DLLPATH ".D3D11CoreCreateLayeredDevice")
#pragma comment(linker, "/EXPORT:D3D11CoreGetLayeredDeviceSize=" DLLPATH ".D3D11CoreGetLayeredDeviceSize")
#pragma comment(linker, "/EXPORT:D3D11CoreRegisterLayers=" DLLPATH ".D3D11CoreRegisterLayers")
#pragma comment(linker, "/EXPORT:D3D11CreateDevice=" DLLPATH ".D3D11CreateDevice")
#pragma comment(linker, "/EXPORT:D3D11CreateDeviceAndSwapChain=" DLLPATH ".D3D11CreateDeviceAndSwapChain")
#pragma comment(linker, "/EXPORT:D3D11CreateDeviceForD3D12=" DLLPATH ".D3D11CreateDeviceForD3D12")
#pragma comment(linker, "/EXPORT:D3D11On12CreateDevice=" DLLPATH ".D3D11On12CreateDevice")
#pragma comment(linker, "/EXPORT:D3DKMTCloseAdapter=" DLLPATH ".D3DKMTCloseAdapter")
#pragma comment(linker, "/EXPORT:D3DKMTCreateAllocation=" DLLPATH ".D3DKMTCreateAllocation")
#pragma comment(linker, "/EXPORT:D3DKMTCreateContext=" DLLPATH ".D3DKMTCreateContext")
#pragma comment(linker, "/EXPORT:D3DKMTCreateDevice=" DLLPATH ".D3DKMTCreateDevice")
#pragma comment(linker, "/EXPORT:D3DKMTCreateSynchronizationObject=" DLLPATH ".D3DKMTCreateSynchronizationObject")
#pragma comment(linker, "/EXPORT:D3DKMTDestroyAllocation=" DLLPATH ".D3DKMTDestroyAllocation")
#pragma comment(linker, "/EXPORT:D3DKMTDestroyContext=" DLLPATH ".D3DKMTDestroyContext")
#pragma comment(linker, "/EXPORT:D3DKMTDestroyDevice=" DLLPATH ".D3DKMTDestroyDevice")
#pragma comment(linker, "/EXPORT:D3DKMTDestroySynchronizationObject=" DLLPATH ".D3DKMTDestroySynchronizationObject")
#pragma comment(linker, "/EXPORT:D3DKMTEscape=" DLLPATH ".D3DKMTEscape")
#pragma comment(linker, "/EXPORT:D3DKMTGetContextSchedulingPriority=" DLLPATH ".D3DKMTGetContextSchedulingPriority")
#pragma comment(linker, "/EXPORT:D3DKMTGetDeviceState=" DLLPATH ".D3DKMTGetDeviceState")
#pragma comment(linker, "/EXPORT:D3DKMTGetDisplayModeList=" DLLPATH ".D3DKMTGetDisplayModeList")
#pragma comment(linker, "/EXPORT:D3DKMTGetMultisampleMethodList=" DLLPATH ".D3DKMTGetMultisampleMethodList")
#pragma comment(linker, "/EXPORT:D3DKMTGetRuntimeData=" DLLPATH ".D3DKMTGetRuntimeData")
#pragma comment(linker, "/EXPORT:D3DKMTGetSharedPrimaryHandle=" DLLPATH ".D3DKMTGetSharedPrimaryHandle")
#pragma comment(linker, "/EXPORT:D3DKMTLock=" DLLPATH ".D3DKMTLock")
#pragma comment(linker, "/EXPORT:D3DKMTOpenAdapterFromHdc=" DLLPATH ".D3DKMTOpenAdapterFromHdc")
#pragma comment(linker, "/EXPORT:D3DKMTOpenResource=" DLLPATH ".D3DKMTOpenResource")
#pragma comment(linker, "/EXPORT:D3DKMTPresent=" DLLPATH ".D3DKMTPresent")
#pragma comment(linker, "/EXPORT:D3DKMTQueryAdapterInfo=" DLLPATH ".D3DKMTQueryAdapterInfo")
#pragma comment(linker, "/EXPORT:D3DKMTQueryAllocationResidency=" DLLPATH ".D3DKMTQueryAllocationResidency")
#pragma comment(linker, "/EXPORT:D3DKMTQueryResourceInfo=" DLLPATH ".D3DKMTQueryResourceInfo")
#pragma comment(linker, "/EXPORT:D3DKMTRender=" DLLPATH ".D3DKMTRender")
#pragma comment(linker, "/EXPORT:D3DKMTSetAllocationPriority=" DLLPATH ".D3DKMTSetAllocationPriority")
#pragma comment(linker, "/EXPORT:D3DKMTSetContextSchedulingPriority=" DLLPATH ".D3DKMTSetContextSchedulingPriority")
#pragma comment(linker, "/EXPORT:D3DKMTSetDisplayMode=" DLLPATH ".D3DKMTSetDisplayMode")
#pragma comment(linker, "/EXPORT:D3DKMTSetDisplayPrivateDriverFormat=" DLLPATH ".D3DKMTSetDisplayPrivateDriverFormat")
#pragma comment(linker, "/EXPORT:D3DKMTSetGammaRamp=" DLLPATH ".D3DKMTSetGammaRamp")
#pragma comment(linker, "/EXPORT:D3DKMTSetVidPnSourceOwner=" DLLPATH ".D3DKMTSetVidPnSourceOwner")
#pragma comment(linker, "/EXPORT:D3DKMTSignalSynchronizationObject=" DLLPATH ".D3DKMTSignalSynchronizationObject")
#pragma comment(linker, "/EXPORT:D3DKMTUnlock=" DLLPATH ".D3DKMTUnlock")
#pragma comment(linker, "/EXPORT:D3DKMTWaitForSynchronizationObject=" DLLPATH ".D3DKMTWaitForSynchronizationObject")
#pragma comment(linker, "/EXPORT:D3DKMTWaitForVerticalBlankEvent=" DLLPATH ".D3DKMTWaitForVerticalBlankEvent")
#pragma comment(linker, "/EXPORT:D3DPerformance_BeginEvent=" DLLPATH ".D3DPerformance_BeginEvent")
#pragma comment(linker, "/EXPORT:D3DPerformance_EndEvent=" DLLPATH ".D3DPerformance_EndEvent")
#pragma comment(linker, "/EXPORT:D3DPerformance_GetStatus=" DLLPATH ".D3DPerformance_GetStatus")
#pragma comment(linker, "/EXPORT:D3DPerformance_SetMarker=" DLLPATH ".D3DPerformance_SetMarker")
#pragma comment(linker, "/EXPORT:EnableFeatureLevelUpgrade=" DLLPATH ".EnableFeatureLevelUpgrade")
#pragma comment(linker, "/EXPORT:OpenAdapter10=" DLLPATH ".OpenAdapter10")
#pragma comment(linker, "/EXPORT:OpenAdapter10_2=" DLLPATH ".OpenAdapter10_2")
