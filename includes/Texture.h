#ifndef UT_TEXTURE_H
#define UT_TEXTURE_H

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include <stdint.h>
#include <vector>

namespace UT
{
    struct TextureEntry
    {
        glm::ivec2 pos;
        glm::ivec2 size;
        glm::ivec4 padding;
        uint16_t   pageId;
    };
}

#endif