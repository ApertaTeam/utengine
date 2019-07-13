#ifndef UT_SPRITE_H
#define UT_SPRITE_H

#include <GL/glew.h>

#include "Common.h"
#include "Object.h"

namespace UT
{
    // A type of object which has a sprite.
    class Sprite : public Object
    {
    public:
        Sprite();

        virtual void Render() override;

        // Getters
        GLuint GetTexture();
        Transform GetTransform();

        // Setters
        void SetTexture(GLuint texture);
        void SetTransform(Transform transform);

    protected:
        Transform transform;
        GLuint texture; // TODO: work with texture pages
    };
}

#endif