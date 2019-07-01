#ifndef UT_SPRITE_H
#define UT_SPRITE_H

#include <GL/glew.h>

#include "Common.h"
#include "Object.h"

namespace UT
{
    class Sprite : Object
    {
    public:
        Sprite();

        virtual void Render();

        // Getters
        GLuint GetTexture();
        Transform GetTransform();
        bool GetIsStatic();

        // Setters
        void SetTexture(GLuint texture);
        void SetTransform(Transform transform);
        void SetIsStatic(bool isStatic);

    private:
        Transform transform;
        GLuint texture;
        int depth;
        bool isStatic;
    };
}

#endif