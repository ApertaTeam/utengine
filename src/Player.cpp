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
        sprite.SetSpeed(10);
    }

    void Player::AddTextureRect(std::string name, std::vector<sf::IntRect> textureRect)
    {
        this->textureRects.insert(std::pair(name, textureRect));
    }

    void Player::Update(float delta)
    {
        int curFrame = sprite.GetImageIndex();
        Sprite spr = Sprite(texture, textureRects["idleSouth"][curFrame]);

        if ((InputHandler::IsInputHeld(InputActions::Left) && direction != PlayerDirection::West)
            || (InputHandler::IsInputHeld(InputActions::Right) && direction != PlayerDirection::East)
            || (InputHandler::IsInputHeld(InputActions::Up) && direction != PlayerDirection::North)
            || (InputHandler::IsInputHeld(InputActions::Down) && direction != PlayerDirection::South))
        {
            sprite.SetImageIndex(0);

            sprite.Reset();

            if (InputHandler::IsInputHeld(InputActions::Up))
            {
                sprite.PushFrame(spr);
                spr.SetTextureRect(textureRects["idleNorth"][0]);
            }
            else if (InputHandler::IsInputHeld(InputActions::Down))
            {
                sprite.PushFrame(spr);
                spr.SetTextureRect(textureRects["idleSouth"][0]);
                sprite.PushFrame(spr);
                spr.SetTextureRect(textureRects["idleSouth"][1]);
                sprite.PushFrame(spr);
                spr.SetTextureRect(textureRects["idleSouth"][2]);
                sprite.PushFrame(spr);
                spr.SetTextureRect(textureRects["idleSouth"][3]);
            }
            else if (InputHandler::IsInputHeld(InputActions::Left))
            {
                sprite.PushFrame(spr);
                spr.SetTextureRect(textureRects["idleWest"][0]);
            }
            else if (InputHandler::IsInputHeld(InputActions::Right))
            {
                sprite.PushFrame(spr);
                spr.SetTextureRect(textureRects["idleEast"][0]);
            }
        }


        if (InputHandler::IsInputHeld(InputActions::Up))
        {
            position.y -= speed;
            direction = PlayerDirection::North;
            spr.SetTextureRect(textureRects["idleNorth"][curFrame]);
        }
        else if (InputHandler::IsInputHeld(InputActions::Down))
        {
            position.y += speed;
            direction = PlayerDirection::South;
            spr.SetTextureRect(textureRects["idleSouth"][curFrame]);
        }

        if (InputHandler::IsInputHeld(InputActions::Left))
        {
            position.x -= speed;
            direction = PlayerDirection::West;
            spr.SetTextureRect(textureRects["idleWest"][curFrame]);
        }
        else if (InputHandler::IsInputHeld(InputActions::Right))
        {
            position.x += speed;
            direction = PlayerDirection::East;
            spr.SetTextureRect(textureRects["idleEast"][curFrame]);
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