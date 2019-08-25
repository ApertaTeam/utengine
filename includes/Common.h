#ifndef UT_COMMON_H
#define UT_COMMON_H

#include <vector>
#include <string>

#include <stdint.h>

namespace UT
{
    class Object; // Forward declare
    class Sprite;

    // Vector 2
    struct Vector2
    {
        int x;
        int y;

        Vector2() : x(0), y(0) {};
        Vector2(int x, int y) : x(x), y(y) {};
    };

    // Vector 4
    struct Vector4
    {
        int x;
        int y;
        int z;
        int w;

        Vector4() : x(0), y(0), z(0), w(0) {};
        Vector4(int x, int y, int z, int w) : x(x), y(y), z(z), w(w) {};
    };

    // Transform
    struct Transform
    {
        Vector2 position;
        int rotation;

        Transform() : position({ 0, 0 }), rotation(0) {};
        Transform(Vector2 position, int rotation) : position(position), rotation(rotation) {};
    };

    // Represents a game room, containing game objects and tiles, etc.
    struct Room
    {
        Vector2 size;
        std::vector<Object*> objects;
        std::vector<Sprite*> sprites;

        Room() : size({ 0, 0 }), objects({}) {};
        Room(Vector2 size) : size(size), objects({}) {};
    };
}

uint16_t swapbits(uint16_t src);
uint32_t swapbits(uint32_t src);
uint64_t swapbits(uint64_t src);

std::string GetExecutableDirectory();

#endif