# plex_loadfile_hook

[This commit on mpv](https://github.com/mpv-player/mpv/commit/c678033c1d60b48ae02fbbe4815869b9504a17f6) broke backwards compatibility with how Plex utilizes the `loadfile` command to play video. This release fixes it via a hack, and allows using the latest version of libmpv.

Why is this an issue? Plex uses an incredibly old version of libmpv which lacks many new improvements, most notable one being Dolby Vision tonemapping (either to SDR/HDR) via the `gpu-next` video output driver. Other good reasons include improved support for graphic APIs, ASS performance improvements and the better `high-quality` preset being included.

## How this works

A detour is placed on `mpv_command_node` from `libmpv.dll`, reducing the `loadfile` command to only have 1 argument; the playback URL.
This release makes use of DLL proxying to inject `plex_loadfile_hook` when Plex loads Direct3D 11.

## Installation

Windows only. Binaries provided for x86_64, but it should work for 32-bit as well.

1. Download `d3d11.dll` from [the latest release](https://github.com/yuv420p10le/plex_loadfile_hook/releases/latest) and put it in your Plex installation folder. (e.g. `C:\Program Files\Plex\Plex`)
2. Grab the latest `libmpv` build from [shinchiro's provided builds](https://sourceforge.net/projects/mpv-player-windows/files/libmpv/), rename `libmpv-2.dll` to `mpv-2.dll`, and replace `mpv-2.dll` in the Plex installation folder with it.

## Use new settings

Open `%LOCALAPPDATA%\Plex` and start adding settings to `mpv.conf`.

I recommend the following as a basis:

```conf
# The new video output driver; allowing better color management and support for DV/HDR tonemapping.
vo=gpu-next

# A preset for higher quality playback. Comment out or replace with `profile=fast` if playback performance is unacceptable.
profile=high-quality

# Refer to the manual; too long to elaborate. Replace with your own choice if needed, but this is a good generic option.
hwdec=auto-safe

# Allows for HDR passthrough & automatically setting the display to HDR mode, when using the Vulkan API.
target-colorspace-hint=yes

# Replace with gpu-api=d3d11 if you're having issues.
# vulkan will allow automatic switching to HDR when playing DV content, and will display DV tonemapped to HDR.
gpu-api=vulkan

# Replace with your display's bit depth. Will be 8 for most SDR displays, and 10/12 for most HDR/DV supporting ones.
dither-depth=10

# Uncomment and replace 400 with your display's brightness, in nits.
# target-peak=400
```

Refer to the mpv manual (linked in resources) for additional settings.

### Resources

* [mpv manual](https://mpv.io/manual/stable/)
* [perfect-dll-proxy](https://github.com/mrexodia/perfect-dll-proxy)
* [MinHook](https://github.com/TsudaKageyu/minhook)
