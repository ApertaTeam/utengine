#include "Sprite.h"

namespace UT
{
    Sprite::Sprite()
    {
    }

    void Sprite::Render()
    {
    }

    GLuint Sprite::GetTexture()
    {
        return this->texture;
    }

    Transform Sprite::GetTransform()
    {
        return this->transform;
    }

    void Sprite::SetTexture(GLuint texture)
    {
        this->texture = texture;
    }

    void Sprite::SetTransform(Transform transform)
    {
        this->transform = transform;
    }
}