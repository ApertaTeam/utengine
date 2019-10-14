#ifndef UT_OBJECT_H
#define UT_OBJECT_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace UT
{
    // The abstract parent of all game objects
    class Object : public sf::Drawable, public sf::Transformable
    {
    public:
        virtual void Init() = 0;
        virtual void Update(float delta) = 0;
    };
}

#endif