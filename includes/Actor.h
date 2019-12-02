#ifndef UT_ACTOR_H
#define UT_ACTOR_H

#include "AnimatedSprite.h"
#include "Interactable.h"
#include "Object.h"

namespace UT
{
    class Actor : public Interactable
    {
    public:
        Actor();

        virtual void Update(float delta) override;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void MoveTo(sf::Vector2i position);

        virtual void OnUpdate(float delta);
        virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const;


        sf::Vector2i position;
        AnimatedSprite sprite;
        sf::IntRect collisionBox;
        int speed;
        
    protected:
        sf::Vector2i newPosition;
        sf::Vector2f newCalculations;
        sf::Vector2f newSum;

    };
}
#endif
