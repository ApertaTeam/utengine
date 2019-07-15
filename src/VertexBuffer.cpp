#include "VertexBuffer.h"

#include <GL/glew.h>

namespace UT
{
    VertexBuffer::VertexBuffer(const void* data, unsigned int size)
    {
        glGenBuffers(1, &glID);
        glBindBuffer(GL_ARRAY_BUFFER, glID);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1, &glID);
    }

    void VertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, glID);
    }

    void VertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}