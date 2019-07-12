#include "Object.h"

namespace UT
{
    Object::Object()
    {
        this->depth = 0;
    }

    void Object::Render()
    {

    }

    // Getters
    int Object::GetDepth()
    {
        return this->depth;
    }

    // Setters
    void Object::SetDepth(int depth)
    {
        this->depth = depth;
    }
}