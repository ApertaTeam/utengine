#include "Player.h"
#include "Input.h"

namespace UT
{
    Player::Player()
        : speed(3), direction(PlayerDirection::South)
    {

    }

    void Player::Init()
    {

    }

    void Player::Update(float delta)
    {
        if (InputHandler::IsInputHeld(InputActions::Up))
        {
            position.y -= speed;
        }
        else if (InputHandler::IsInputHeld(InputActions::Down))
        {
            position.y += speed;
        }

        if (InputHandler::IsInputHeld(InputActions::Left))
        {
            position.x -= speed;
        }
        else if (InputHandler::IsInputHeld(InputActions::Right))
        {
            position.x += speed;
        }

        sprite.Update(delta);
        setPosition(position);
        sprite.setPosition(position - (sprite.GetSize()/2.f));
    }

    void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(sprite);
    }
}