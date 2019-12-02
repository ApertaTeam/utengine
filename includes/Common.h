#ifndef UT_COMMON_H
#define UT_COMMON_H

#include <vector>
#include <string>
#include <stdint.h>

#include <SFML/Graphics.hpp>

namespace UT
{
    class Object; // Forward declare
    class Sprite;

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

	// Vector 4 Float
	struct Vector4f
	{
		float x;
		float y;
		float z;
		float w;

		Vector4f() : x(0), y(0), z(0), w(0) {};
		Vector4f(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {};
	};

    // Transform
    struct Transform
    {
        sf::Vector2f position;
        int rotation;

        Transform() : position({ 0, 0 }), rotation(0) {};
        Transform(sf::Vector2f position, int rotation) : position(position), rotation(rotation) {};
    };
}

uint16_t swapbits(uint16_t src);
uint32_t swapbits(uint32_t src);
uint64_t swapbits(uint64_t src);

std::string GetExecutableDirectory();

#endif