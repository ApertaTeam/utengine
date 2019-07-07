#include "BinaryReader.h"

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
#elif defined(__GNUC__)
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

namespace UT
{
    uint8_t BinaryReader::ReadUInt8()
    {
        uint8_t data = 0;
        Read(&data, 1);
        return data;
    }

    uint16_t BinaryReader::ReadUInt16()
    {
        uint16_t data = 0;
        Read(&data, 2);
        return data;
    }

    uint32_t BinaryReader::ReadUInt32()
    {
        uint32_t data = 0;
        Read(&data, 4);
        return data;
    }

    uint64_t BinaryReader::ReadUInt64()
    {
        uint64_t data = 0;
        Read(&data, 8);
        return data;
    }

    int8_t BinaryReader::ReadInt8()
    {
        int8_t data = 0;
        Read(&data, 1);
        return data;
    }

    int16_t BinaryReader::ReadInt16()
    {
        int16_t data = 0;
        Read(&data, 2);
        return data;
    }

    int32_t BinaryReader::ReadInt32()
    {
        int32_t data = 0;
        Read(&data, 4);
        return data;
    }

    int64_t BinaryReader::ReadInt64()
    {
        int64_t data = 0;
        Read(&data, 8);
        return data;
    }

    float BinaryReader::ReadFloat()
    {
        float data = 0;
        Read(&data, sizeof(data));
        return data;
    }

    double BinaryReader::ReadDouble()
    {
        double data = 0;
        Read(&data, sizeof(data));
        return data;
    }

    std::string BinaryReader::ReadString()
    {
        std::string string;
        int ch = 0;
        Read(&ch, 1);
        while (ch != '\0' && ch != EOF)
        {
            string.push_back(ch);
            Read(&ch, 1);
        }
        string.push_back('\0');
        return string;
    }

    void BinaryReader::CheckMagic(uint32_t magic)
    {
        uint32_t magic_chk = ReadUInt32();
        if (magic_chk == magic)
        {
            this->endian = BIG_ENDIAN;
            return;
        }
        else if (swapbits(magic_chk) == magic)
        {
            this->endian = LITTLE_ENDIAN;
            return;
        }

        // Throw error or something because
        // the bits grabbed doesn't actually
        // equal the magic
    }

    BinaryFileReader::BinaryFileReader(std::string filePath)
    {
        this->fd = fopen(filePath.c_str(), "rb");
    }

    BinaryFileReader::~BinaryFileReader()
    {
        fclose(fd);
    }

    int BinaryFileReader::Read(void* ptr, size_t size)
    {
        if (this->endian == BIG_ENDIAN)
        {
            switch (size)
            {
                case 1:
                    return fread(ptr, size, 1, fd);
                case 2:
                {
                    uint16_t res = 0;
                    int result = fread(&res, size, 1, fd);
                    *((uint16_t*)ptr) = swapbits(res);
                    return result;
                }
                case 4:
                {
                    uint32_t res = 0;
                    int result = fread(&res, size, 1, fd);
                    *((uint32_t*)ptr) = swapbits(res);
                    return result;
                }
                case 8:
                {
                    uint64_t res = 0;
                    int result = fread(&res, size, 1, fd);
                    *((uint64_t*)ptr) = swapbits(res);
                    return result;
                }
            }
        }
        return fread(ptr, size, 1, fd);
    }
}