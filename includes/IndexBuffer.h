#ifndef UT_INDEX_BUFFER_H
#define UT_INDEX_BUFFER_H

namespace UT
{
    class IndexBuffer
    {
    public:
        IndexBuffer(const unsigned int* data, unsigned int count);
        ~IndexBuffer();

        void Bind() const;
        void Unbind() const;

        inline unsigned int GetCount() const { return count; }
    private:
        unsigned int glID;
        unsigned int count;
    };
}

#endif