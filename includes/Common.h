#ifndef UT_COMMON_H
#define UT_COMMON_H

#include <vector>
#include <glm/vec2.hpp>

#include <stdint.h>

namespace UT
{
    class Object; // Forward declare

    struct Transform
    {
        glm::vec2 position;
        glm::vec2 size;
    };

    struct Room
    {
        glm::vec2 size;
        std::vector<Object*> objects;
    };
}

uint16_t swapbits(uint16_t src);
uint32_t swapbits(uint32_t src);
uint64_t swapbits(uint64_t src);

#endif