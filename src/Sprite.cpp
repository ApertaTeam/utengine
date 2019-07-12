#include "Sprite.h"

namespace UT
{
    Sprite::Sprite()
    {
        this->transform = Transform();
        this->texture = 0;
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

    // Setters
    void Sprite::SetTexture(GLuint texture)
    {
        this->texture = texture;
    }

    void Sprite::SetTransform(Transform transform)
    {
        this->transform = transform;
    }
}