#ifndef UT_PLAYER_H
#define UT_PLAYER_H

#include "AnimatedSprite.h"
#include "Object.h"

namespace UT
{
    enum PlayerDirection
    {
        North,
        South,
        West,
        East
    };

    class Player : public Object
    {
    public:
        Player();

        void Init() override;
        void Update(float delta) override;

        inline void SetSprite(AnimatedSprite sprite) { this->sprite = sprite; };
        inline AnimatedSprite GetSprite() { return sprite; };

        inline void SetDirection(PlayerDirection direction) { this->direction = direction; };
        inline PlayerDirection GetDirection() { return direction; };

        inline void SetPosition(sf::Vector2f position) { this->position = position; };
        inline sf::Vector2f GetPosition() { return position; };

        inline void SetCollisionBox(sf::IntRect collisionBox) { this->collisionBox = collisionBox; };
        inline sf::IntRect GetCollisionBox() { return collisionBox; };

        inline void SetSpeed(int speed) { this->speed = speed; };
        inline int GetSpeed() { return speed; };

    private:
        AnimatedSprite sprite;
        PlayerDirection direction;
        sf::Vector2f position;

        sf::IntRect collisionBox;
        int speed;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}
#endif