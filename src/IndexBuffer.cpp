#include "IndexBuffer.h"

#include <GL/glew.h>

namespace UT
{
    IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
        : count(count)
    {
        glGenBuffers(1, &glID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
    }

    IndexBuffer::~IndexBuffer()
    {
        glDeleteBuffers(1, &glID);
    }

    void IndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glID);
    }

    void IndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}