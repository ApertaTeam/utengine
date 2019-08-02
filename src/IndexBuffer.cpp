#include "IndexBuffer.h"


namespace UT
{
    IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
        : count(count)
    {
    }

    IndexBuffer::~IndexBuffer()
    {
    }

    void IndexBuffer::Bind() const
    {
    }

    void IndexBuffer::Unbind() const
    {
    }
}