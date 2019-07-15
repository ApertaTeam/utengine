#include "VertexBufferLayout.h"

#include <GL/glew.h>

namespace UT
{
    VertexBufferLayout::VertexBufferLayout()
    {
        stride = 0;
    }

    template<typename T>
    void VertexBufferLayout::Push(unsigned int count)
    {
        // Do nothing
    }

    template<>
    void VertexBufferLayout::Push<float>(unsigned int count)
    {
        elements.push_back({ GL_FLOAT, count, false });
        stride += Element::GetSizeOfType(GL_FLOAT) * count;
    }

    template<>
    void VertexBufferLayout::Push<unsigned int>(unsigned int count)
    {
        elements.push_back({ GL_UNSIGNED_INT, count, false });
        stride += Element::GetSizeOfType(GL_UNSIGNED_INT) * count;
    }

    template<>
    void VertexBufferLayout::Push<unsigned char>(unsigned int count)
    {
        elements.push_back({ GL_UNSIGNED_BYTE, count, true });
        stride += Element::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
    }

    unsigned int VertexBufferLayout::Element::GetSizeOfType(unsigned int type)
    {
        switch (type)
        {
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_UNSIGNED_BYTE:  return 1;
        }
        return 0;
    }
}