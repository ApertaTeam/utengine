#include "VertexBufferLayout.h"


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
    }

    template<>
    void VertexBufferLayout::Push<unsigned int>(unsigned int count)
    {
    }

    template<>
    void VertexBufferLayout::Push<unsigned char>(unsigned int count)
    {
    }

    unsigned int VertexBufferLayout::Element::GetSizeOfType(unsigned int type)
    {
        
        return 0;
    }
}