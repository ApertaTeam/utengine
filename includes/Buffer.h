#ifndef UT_BUFFER_H
#define UT_BUFFER_H

#include <stdint.h>
#include <vector>

namespace UT
{
    // A simple wrapper around buffers
    class Buffer
    {
    public:
        Buffer(uint8_t* buffer, uint32_t length);

        // Getters
        uint32_t GetLength() const;
        const uint8_t* GetData() const;

        // Zlib compression and decompression
        void Decompress(uint64_t uncompressedLength);
        void Compress();
    private:
        std::vector<uint8_t> buffer;
        uint32_t length;
    };
}

#endif