#include "BinaryReader.h"
#include "Common.h"
#include "Logger.h"

#include <cstring>

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

        return string;
    }

    Buffer BinaryReader::ReadBuffer()
    {
        return ReadBuffer(ReadUInt32());
    }

    Buffer BinaryReader::ReadBuffer(uint32_t length)
    {
        uint8_t* buf = new uint8_t[length];
        Read(buf, length);
        return Buffer(buf, length);
    }

    Buffer BinaryReader::ReadCompressedBuffer()
    {
        return ReadCompressedBuffer(ReadUInt32());
    }

    Buffer BinaryReader::ReadCompressedBuffer(uint32_t uncompressedLength)
    {
        return ReadCompressedBuffer(uncompressedLength, ReadUInt32());
    }

    Buffer BinaryReader::ReadCompressedBuffer(uint32_t uncompressedLength, uint32_t length)
    {
        Buffer buffer = ReadBuffer(length);
        buffer.Decompress((uint64_t)uncompressedLength);
        return buffer;
    }

    bool BinaryReader::CheckMagic(uint32_t magic)
    {
        uint32_t magic_chk = ReadUInt32();
        if (magic_chk == magic)
        {
            this->endian = BIG_ENDIAN;
            return true;
        }
        else if (swapbits(magic_chk) == magic)
        {
            this->endian = LITTLE_ENDIAN;
            return true;
        }
        return false;
    }

    BinaryFileReader::BinaryFileReader(std::string filePath)
    {
        fd = fopen(filePath.c_str(), "rb");
        atEOF = false;
        
        if (fd == NULL)
        {
            canRead = false;
            GlobalLogger->Log(Logger::Error, "Failed to open file for reading at path '" + filePath + "', error: " + std::string(strerror(errno)));
        } else
        {
            canRead = true;

            fseek(fd, 0L, SEEK_END);
            fileSize = ftell(fd);
            rewind(fd);
        }        
    }

    BinaryFileReader::~BinaryFileReader()
    {
        if (canRead) fclose(fd);
    }

    bool BinaryFileReader::CanRead()
    {
        return canRead;
    }

    bool BinaryFileReader::IsAtEOF()
    {
        return atEOF;
    }

    int BinaryFileReader::Read(void* ptr, size_t size)
    {
        if (!canRead || atEOF) return 0;
        if (this->endian == BIG_ENDIAN)
        {
            switch (size)
            {
                case 1:
                    return (int)fread(ptr, size, 1, fd);
                case 2:
                {
                    uint16_t res = 0;
                    int result = (int)fread(&res, size, 1, fd);
                    *((uint16_t*)ptr) = swapbits(res);
                    return result;
                }
                case 4:
                {
                    uint32_t res = 0;
                    int result = (int)fread(&res, size, 1, fd);
                    *((uint32_t*)ptr) = swapbits(res);
                    return result;
                }
                case 8:
                {
                    uint64_t res = 0;
                    int result = (int)fread(&res, size, 1, fd);
                    *((uint64_t*)ptr) = swapbits(res);
                    return result;
                }
                default:
                    return (int)fread(ptr, size, 1, fd);
            }
        }


        if (ftell(fd) >= fileSize)
        {
            atEOF = true;
        }


        return (int)fread(ptr, size, 1, fd);
    }

    BinaryBufferReader::BinaryBufferReader(Buffer buffer)
    {
        this->buffer = (char*)buffer.GetData();
        this->bufferPos = 0;
        this->bufferSize = buffer.GetLength();
        this->atEOF = false;
        this->canRead = true;
    }

    BinaryBufferReader::BinaryBufferReader(void* ptr, size_t size)
    {
        this->buffer = (char*)ptr;
        this->bufferPos = 0;
        this->bufferSize = size;
        this->atEOF = false;
        this->canRead = true;
    }

    bool BinaryBufferReader::CanRead()
    {
        return canRead;
    }

    bool BinaryBufferReader::IsAtEOF()
    {
        return atEOF;
    }

    int BinaryBufferReader::Read(void* ptr, size_t size)
    {
        if (!canRead || atEOF) return 0;
        if (bufferPos >= bufferSize)
        {
            canRead = false;
            atEOF = true;
            return 0;
        }

        if (this->endian == BIG_ENDIAN)
        {
            switch (size)
            {
                case 1:
                {
                    *(char*)ptr = *buffer++;
                    bufferPos++;
                    return 1;
                }
                case 2:
                {
                    uint16_t res = 0;
                    char* p = (char*)&res;
                    p[0] = *buffer++;
                    p[1] = *buffer++;
                    bufferPos += 2;
                    *((uint16_t*)ptr) = swapbits(res);
                    return 2;
                }
                case 4:
                {
                    uint32_t res = 0;
                    char* p = (char*)&res;
                    for (int i = 0; i < size; i++)
                    {
                        p[i] = *buffer++;
                        bufferPos++;
                    }
                    *((uint32_t*)ptr) = swapbits(res);
                    return 4;
                }
                case 8:
                {
                    uint64_t res = 0;
                    char* p = (char*)&res;
                    for (int i = 0; i < size; i++)
                    {
                        p[i] = *buffer++;
                        bufferPos++;
                    }
                    *((uint64_t*)ptr) = swapbits(res);
                    return 8;
                }
            }
        }

        int wrote = 0;
        for (int i = 0; i < size && (canRead && !atEOF); i++)
        {
            ((char*)ptr)[i] = *buffer++;
            bufferPos++;
            wrote++;
            if (bufferPos >= bufferSize)
            {
                atEOF = true;
                canRead = false;
            }
        }
        return wrote;
    }
}