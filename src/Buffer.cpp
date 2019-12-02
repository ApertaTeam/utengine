#include "Buffer.h"
#include "Logger.h"

#include <zlib.h>

namespace UT
{
    Buffer::Buffer(uint8_t* buffer, uint32_t length)
    {
        this->buffer = std::vector<uint8_t>();
        this->buffer.assign(buffer, buffer + length);
        this->length = length;
    }

    uint32_t Buffer::GetLength() const
    {
        return length;
    }

    const uint8_t* Buffer::GetData() const
    {
        return buffer.data();
    }

    const char* zlibStatusToString(int status)
    {
        switch (status)
        {
        case Z_STREAM_END:
            return "STREAM_END";
        case Z_NEED_DICT:
            return "NEED_DICT";
        case Z_ERRNO:
            return "ERRNO";
        case Z_STREAM_ERROR:
            return "STREAM_ERROR";
        case Z_DATA_ERROR:
            return "DATA_ERROR";
        case Z_MEM_ERROR:
            return "MEM_ERROR";
        case Z_BUF_ERROR:
            return "BUF_ERROR";
        case Z_VERSION_ERROR:
            return "VERSION_ERROR";
        case Z_OK:
            return "OK";
        default:
            return "UNKNOWN";
        }
    }

    void Buffer::Decompress(uint64_t uncompressedLength)
    {
        uint8_t* newBuffer = new uint8_t[uncompressedLength];
        int res = uncompress(reinterpret_cast<unsigned char*>(newBuffer), reinterpret_cast<unsigned long int*>(&uncompressedLength), reinterpret_cast<unsigned char*>(buffer.data()), length);
        if (res != Z_OK)
        {
            GlobalLogger->Log(Logger::Error, "Zlib decompression error: " + std::string(zlibStatusToString(res)));
            delete[] newBuffer;
            return;
        }
        buffer.assign(newBuffer, newBuffer + uncompressedLength);
        delete[] newBuffer;
        length = (uint32_t)uncompressedLength;
    }

    void Buffer::Compress()
    {
        unsigned long int destLength = compressBound(length);
        uint8_t* newBuffer = new uint8_t[destLength];
        int res = compress2(reinterpret_cast<unsigned char*>(newBuffer), &destLength, reinterpret_cast<unsigned char*>(buffer.data()), length, Z_BEST_COMPRESSION);
        if (res != Z_OK)
        {
            GlobalLogger->Log(Logger::Error, "Zlib compression error: " + std::string(zlibStatusToString(res)));
            delete[] newBuffer;
            return;
        }
        buffer.assign(newBuffer, newBuffer + destLength);
        delete[] newBuffer;
        length = destLength;
    }
}