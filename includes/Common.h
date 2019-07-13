#ifndef UT_COMMON_H
#define UT_COMMON_H

#include <vector>
#include <string>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include <stdint.h>

namespace UT
{
    class Object; // Forward declare

    struct Transform
    {
        glm::vec2 position;
        glm::vec2 size;
    };

    // Represents a game room, containing game objects and tiles, etc.
    struct Room
    {
        glm::vec2 size;
        std::vector<Object*> objects;
    };

    // Represents the base values needed to render one point of a polygon
    struct Vertex
    {
        glm::vec3 position;
        glm::vec3 color;
        glm::vec2 texcoord;
        float alpha;
    };
}

uint16_t swapbits(uint16_t src);
uint32_t swapbits(uint32_t src);
uint64_t swapbits(uint64_t src);

std::string GetExecutableDirectory();

#endif