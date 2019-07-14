#include "Object.h"

namespace UT
{
    Object::Object()
    {
        this->depth = 0;
        this->renderType = RenderTypes::AlphaNull;
    }

    void Object::Init()
    {

    }

    void Object::Update()
    {

    }

    void Object::Render()
    {

    }

    // Getters
    int Object::GetDepth()
    {
        return this->depth;
    }

    RenderTypes Object::GetRenderType()
    {
        return this->renderType;
    }

    // Setters
    void Object::SetDepth(int depth)
    {
        this->depth = depth;
    }

    void Object::SetRenderType(RenderTypes renderType)
    {
        this->renderType = renderType;
    }
}