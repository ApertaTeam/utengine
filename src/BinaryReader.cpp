#include "BinaryReader.h"

namespace UT
{
    uint8_t BinaryReader::ReadUInt8()
    {
        uint8_t data = 0;
        Read(&data, 1, 1);
        return data;
    }

    uint16_t BinaryReader::ReadUInt16()
    {
        uint16_t data = 0;
        Read(&data, 2, 1);
        return data;
    }

    uint32_t BinaryReader::ReadUInt32()
    {
        uint32_t data = 0;
        Read(&data, 4, 1);
        return data;
    }

    uint64_t BinaryReader::ReadUInt64()
    {
        uint64_t data = 0;
        Read(&data, 8, 1);
        return data;
    }

    int8_t BinaryReader::ReadInt8()
    {
        int8_t data = 0;
        Read(&data, 1, 1);
        return data;
    }

    int16_t BinaryReader::ReadInt16()
    {
        int16_t data = 0;
        Read(&data, 2, 1);
        return data;
    }

    int32_t BinaryReader::ReadInt32()
    {
        int32_t data = 0;
        Read(&data, 4, 1);
        return data;
    }

    int64_t BinaryReader::ReadInt64()
    {
        int64_t data = 0;
        Read(&data, 8, 1);
        return data;
    }

    float BinaryReader::ReadFloat()
    {
        float data = 0;
        Read(&data, sizeof(data), 1);
        return data;
    }

    double BinaryReader::ReadDouble()
    {
        double data = 0;
        Read(&data, sizeof(data), 1);
        return data;
    }

    std::string BinaryReader::ReadString()
    {
        std::string string;
        int ch = 0;
        Read(&ch, 1, 1);
        while (ch != '\0' && ch != EOF)
        {
            string.push_back(ch);
            Read(&ch, 1, 1);
        }
        string.push_back('\0');
        return string;
    }

    BinaryFileReader::BinaryFileReader(std::string filePath)
    {
        this->fd = fopen(filePath.c_str(), "rb");
    }

    BinaryFileReader::~BinaryFileReader()
    {
        fclose(fd);
    }

    int BinaryFileReader::Read(void* ptr, size_t size, size_t n)
    {
        return fread(ptr, size, n, fd);
    }
}