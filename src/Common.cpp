#include "Common.h"

#include <limits.h>

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