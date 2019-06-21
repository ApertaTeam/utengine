#ifndef UT_SPRITE_H
#define UT_SPRITE_H

#include <glm/vec2.hpp>
#include <GL/glew.h>

#include "Object.h"

namespace UT
{
    // Should we move this to it's own file?
    struct Transform
    {
        glm::vec2 position;
        glm::vec2 size;
    };

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
    };
}

#endif