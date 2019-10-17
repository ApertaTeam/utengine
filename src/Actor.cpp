#include "Actor.h"
#include <iostream>
namespace UT
{
    Actor::Actor()
        : position({ 0, 0 }), sprite(AnimatedSprite()), collisionBox({ 0, 0, 0, 0 }), speed(0), newPosition({ 0, 0 }), newCalculations({ 0, 0 }), newSum({ 0, 0 })
    {

    }

    void Actor::Update(float delta)
    {
        OnUpdate(delta);


        if (position.x != newPosition.x)
        {
            newSum.x -= newCalculations.x * (1000 * delta);
            position.x = newSum.x;
            if (newCalculations.x >= 0 && position.x < newPosition.x) position.x = newPosition.x;
            else if (newCalculations.x < 0 && position.x > newPosition.x) position.x = newPosition.x;
        }

        if (position.y != newPosition.y)
        {
            newSum.y -= newCalculations.y * (1000 * delta);
            position.y = newSum.y;
            if (newCalculations.y >= 0 && position.y < newPosition.y) position.y = newPosition.y;
            else if (newCalculations.y < 0 && position.y > newPosition.y) position.y = newPosition.y;
        }
    }

    void Actor::MoveTo(sf::Vector2i position)
    {
        newPosition = position;

        newCalculations = {
            ((float)this->position.x - (float)position.x) / (float)speed,
            ((float)this->position.y - (float)position.y) / (float)speed,
        };

        newSum = { (float)this->position.x, (float)this->position.y };
    }

    void Actor::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
    {

    }

    void Actor::OnUpdate(float delta)
    {

    }

    void Actor::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        OnDraw(target, states);
    }
}