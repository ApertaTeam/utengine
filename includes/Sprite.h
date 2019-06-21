#ifndef UT_SPRITE_H
#define UT_SPRITE_H

#include <GL/glew.h>

#include "Common.h"
#include "Object.h"

namespace UT
{
    class Sprite : public Object
    {
    public:
        Sprite();

        virtual void Render();

        // Getters
        GLuint GetTexture();
        Transform GetTransform();

        // Setters
        void SetTexture(GLuint texture);
        void SetTransform(Transform transform);

    private:
        Transform transform;
        GLuint texture;
        int depth;
    };
}

#endif