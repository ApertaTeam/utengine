#include "Sprite.h"

namespace UT
{
    Sprite::Sprite()
    {
        this->transform = Transform();
        this->texture = 0;
        this->depth = 0;
        this->isStatic = true;
    }

    void Sprite::Render()
    {
        
    }

    // Getters
    GLuint Sprite::GetTexture()
    {
        return this->texture;
    }

    Transform Sprite::GetTransform()
    {
        return this->transform;
    }

    bool Sprite::GetIsStatic()
    {
        return this->isStatic;
    }

    // Setters
    void Sprite::SetTexture(GLuint texture)
    {
        this->texture = texture;
    }

    void Sprite::SetTransform(Transform transform)
    {
        this->transform = transform;
    }

    void Sprite::SetIsStatic(bool isStatic)
    {
        this->isStatic = isStatic;
    }
}