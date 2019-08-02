#ifndef UT_TEXTURE_H
#define UT_TEXTURE_H

#include <stdint.h>
#include <vector>

namespace UT
{
    struct TextureEntry
    {
        Vector2 pos;
        Vector2 size;
        Vector4 padding;
        uint16_t   pageId;
    };
}

#endif