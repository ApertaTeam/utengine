#ifndef UT_SPRITE_H
#define UT_SPRITE_H

#include <GL/glew.h>

#include "Common.h"
#include "Object.h"
#include "Texture.h"

namespace UT
{
    // A type of object which has a sprite.
    class Sprite : Object
    {
    public:
        Sprite();

        virtual void Render();

        // Getters
        TextureEntry GetFrame(int idx);
        Transform GetTransform();
        bool GetIsStatic();

        // Setters
        void SetFrame(int idx, TextureEntry entry);
        void SetTransform(Transform transform);
        void SetIsStatic(bool isStatic);

    private:
        uint32_t id;
        Transform transform;
        std::vector<TextureEntry> frames;
        glm::ivec2 origin;
        glm::ivec4 mask;
        //GLuint texture; // TODO: work with texture pages
        int depth;
        bool isStatic;
    };
}

#endif