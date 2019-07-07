#ifndef UT_BINARY_READER_H
#define UT_BINARY_READER_H

#include <stdint.h>
#include <stdio.h>
#include <string>

namespace UT
{
    //class Buffer;
    class BinaryReader
    {
    public:
        uint8_t ReadUInt8();
        uint16_t ReadUInt16();
        uint32_t ReadUInt32();
        uint64_t ReadUInt64();

        int8_t ReadInt8();
        int16_t ReadInt16();
        int32_t ReadInt32();
        int64_t ReadInt64();

        float ReadFloat();
        double ReadDouble();

        std::string ReadString();
        //Buffer ReadBuffer(size_t size);

        void CheckMagic(uint32_t magic);
    private:
        virtual int Read(void* ptr, size_t size) = 0;
    protected:
        int endian = LITTLE_ENDIAN;
    };

    class BinaryFileReader : public BinaryReader
    {
    public:
        BinaryFileReader(std::string filePath);
        ~BinaryFileReader();
    private:
        FILE* fd;
        virtual int Read(void* ptr, size_t size);
    };

    // TODO: BinaryBufferReader
}

#endif