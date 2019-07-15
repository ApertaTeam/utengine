#ifndef UT_VERTEX_BUFFER_H
#define UT_VERTEX_BUFFER_H

namespace UT
{
    class VertexBuffer
    {
    public:
        VertexBuffer(const void* data, unsigned int size);
        ~VertexBuffer();

        void Bind() const;
        void Unbind() const;
    private:
        unsigned int glID;
    };
}

#endif