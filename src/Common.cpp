#include "Common.h"

#include <limits.h>

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#elif defined(__linux__)
#include <unistd.h>
#endif

std::string GetExecutableDirectory()
{
    #if defined(_WIN32) || defined(WIN32)
    HMODULE hModule = GetModuleHandle(NULL);
    WCHAR buff[MAX_PATH];
    GetModuleFileName(hModule, buff, MAX_PATH);
    std::wstring temp(buff);
    std::string path(temp.begin(), temp.end());
    return path.substr(0, path.find_last_of("/\\"));
    #elif defined(__linux__)
    char buff[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", buff, sizeof(buff)-1);
    buff[len] = '\0';
    std::string path(buff);
    return path.substr(0, path.find_last_of("/\\"));
    #else
    return "./";
    #endif
}

#if defined(_MSC_VER)
#include <intrin.h>

uint16_t swapbits(uint16_t src)
{
    return _byteswap_ushort(src);
}

uint32_t swapbits(uint32_t src)
{
    return _byteswap_ulong(src);
}

uint64_t swapbits(uint64_t src)
{
    return _byteswap_uint64(src);
}
#elif defined(__GLIBC__)
#include <byteswap.h>
uint16_t swapbits(uint16_t src)
{
    return bswap_16(src);
}

uint32_t swapbits(uint32_t src)
{
    return bswap_32(src);
}

uint64_t swapbits(uint64_t src)
{
    return bswap_64(src);
}
#else
uint16_t swapbits(uint16_t src)
{
    return (((src >> 8) & 0xff) | ((src & 0xff) << 8));
}

uint32_t swapbits(uint32_t src)
{
    return (((src & 0xff000000) >> 24) | ((src & 0x00ff0000) >> 8) | ((src & 0x0000ff00) << 8) | ((src & 0x000000ff) << 24));
}

uint64_t swapbits(uint64_t src)
{
    return ((((src) & 0xff00000000000000ull) >> 56)   
      | (((src) & 0x00ff000000000000ull) >> 40)
      | (((src) & 0x0000ff0000000000ull) >> 24)
      | (((src) & 0x000000ff00000000ull) >> 8)
      | (((src) & 0x00000000ff000000ull) << 8)
      | (((src) & 0x0000000000ff0000ull) << 24)
      | (((src) & 0x000000000000ff00ull) << 40)
      | (((src) & 0x00000000000000ffull) << 56));
}
#endif