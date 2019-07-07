#include "BinaryReader.h"
#include "Common.h"

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
                default:
                    return fread(ptr, size, 1, fd);
            }
        }
        return fread(ptr, size, 1, fd);
    }
}