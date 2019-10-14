#ifndef UT_ACTOR_H
#define UT_ACTOR_H

#include "AnimatedSprite.h"
#include "Interactable.h"
#include "Object.h"

namespace UT
{
    class Actor : Interactable, Object
    {
    public:
        Actor();

        void MoveTo(sf::Vector2i position);

        inline void SetSpeed(int speed) { this->speed = speed; };
        inline int GetSpeed() { return speed; };

    protected:
        sf::Vector2i position;
        AnimatedSprite sprite;
        sf::IntRect collisionBox;
        int speed;
    };
}
#endif