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

        inline void SetDepth(int depth) { this->depth = depth; };
        inline int GetDepth() const { return depth; };

        inline void SetCollisionBox(sf::IntRect collisionBox) { this->collisionBox = collisionBox; };
        inline sf::IntRect GetCollisionBox() { return collisionBox; };

    protected:
        int depth = 0;
        sf::IntRect collisionBox;
    };
}

#endif