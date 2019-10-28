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
        sprite.SetSpeed(5);
    }

    void Player::AddTextureRect(std::string name, std::vector<sf::IntRect> textureRect)
    {
        this->textureRects.insert(std::pair(name, textureRect));
    }

    void Player::Update(float delta)
    {
        int curFrame = sprite.GetImageIndex();
        Sprite spr = Sprite(texture, textureRects["idleSouth"][0]);

        if ((InputHandler::IsInputHeld(InputActions::Left) && direction != PlayerDirection::West)
            || (InputHandler::IsInputHeld(InputActions::Right) && direction != PlayerDirection::East)
            || (InputHandler::IsInputHeld(InputActions::Up) && direction != PlayerDirection::North)
            || (InputHandler::IsInputHeld(InputActions::Down) && direction != PlayerDirection::South))
        {
            sprite.SetImageIndex(0);
            sprite.Reset();
            
            if (InputHandler::IsInputHeld(InputActions::Up))
            {
                spr.SetTextureRect(textureRects["walkNorth"][0]);
                sprite.PushFrame(spr);
            }
            else if (InputHandler::IsInputHeld(InputActions::Down))
            {
                spr.SetTextureRect(textureRects["walkSouth"][0]);
                sprite.PushFrame(spr);
                spr.SetTextureRect(textureRects["walkSouth"][1]);
                sprite.PushFrame(spr);
                spr.SetTextureRect(textureRects["walkSouth"][2]);
                sprite.PushFrame(spr);
                spr.SetTextureRect(textureRects["walkSouth"][3]);
                sprite.PushFrame(spr);
            }
            else if (InputHandler::IsInputHeld(InputActions::Left))
            {
                spr.SetTextureRect(textureRects["walkWest"][0]);
                sprite.PushFrame(spr);
            }
            else if (InputHandler::IsInputHeld(InputActions::Right))
            {
                spr.SetTextureRect(textureRects["walkEast"][0]);
                sprite.PushFrame(spr);
            }
        }


        if (InputHandler::IsInputHeld(InputActions::Up))
        {
            position.y -= speed;
            direction = PlayerDirection::North;
        }
        else if (InputHandler::IsInputHeld(InputActions::Down))
        {
            position.y += speed;
            direction = PlayerDirection::South;
        }

        if (InputHandler::IsInputHeld(InputActions::Left))
        {
            position.x -= speed;
            direction = PlayerDirection::West;
        }
        else if (InputHandler::IsInputHeld(InputActions::Right))
        {
            position.x += speed;
            direction = PlayerDirection::East;
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