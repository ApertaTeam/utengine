#ifndef UT_COMMON_H
#define UT_COMMON_H

#include <vector>
#include <glm/vec2.hpp>

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

#endif