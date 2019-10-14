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

        virtual void Update(float delta) override;

        void MoveTo(sf::Vector2i position);

        inline void SetPosition(sf::Vector2i position) { this->position = position; };
        inline sf::Vector2i GetPosition() { return position; };

        inline void SetSprite(AnimatedSprite* sprite) { this->sprite = sprite; };
        inline AnimatedSprite* GetSprite() { return sprite; };

        inline void SetCollisionBox(sf::IntRect collisionBox) { this->collisionBox = collisionBox; };
        inline sf::IntRect GetCollisionBox() { return collisionBox; };

        inline void SetSpeed(int speed) { this->speed = speed; };
        inline int GetSpeed() { return speed; };

    protected:
        sf::Vector2i position;
        AnimatedSprite* sprite;
        sf::IntRect collisionBox;
        int speed;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}
#endif