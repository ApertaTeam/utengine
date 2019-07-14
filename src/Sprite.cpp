#include "Sprite.h"

namespace UT
{
    Sprite::Sprite()
    {
        this->transform = Transform();
        this->frames = {};
        this->depth = 0;
        this->isStatic = true;
    }

    void Sprite::Render()
    {
        
    }

    // Getters
    TextureEntry Sprite::GetFrame(int idx)
    {
        // TODO: Check for out of bounds
        return this->frames[idx];
    }

    Transform Sprite::GetTransform()
    {
        return this->transform;
    }

    // Setters
    void Sprite::SetFrame(int idx, TextureEntry entry)
    {
        this->frames[idx] = entry;
    }

    void Sprite::SetTransform(Transform transform)
    {
        this->transform = transform;
    }
}