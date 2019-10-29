#include "Player.h"
#include "Input.h"
#include "Game.h"

namespace UT
{
    Player::Player(std::map<std::string, std::vector<sf::IntRect>> frames)
        : textureRects(frames), texture(-1), speed(3), direction(PlayerDirection::South), isMoving(false), canMove(true)
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

        bool moving = (InputHandler::IsInputHeld(InputActions::Left)
            || InputHandler::IsInputHeld(InputActions::Right)
            || InputHandler::IsInputHeld(InputActions::Up)
            || InputHandler::IsInputHeld(InputActions::Down));

        if (InputHandler::IsInputHeld(InputActions::Up))
        {
            position.y -= speed;

            if (direction != PlayerDirection::North)
            {
                isMoving = false;
                direction = PlayerDirection::North;
            }
        }
        else if (InputHandler::IsInputHeld(InputActions::Down))
        {
            position.y += speed;

            if (direction != PlayerDirection::South)
            {
                isMoving = false;
                direction = PlayerDirection::South;
            }
        }

        if (InputHandler::IsInputHeld(InputActions::Left))
        {
            position.x -= speed;

            if (direction != PlayerDirection::West)
            {
                isMoving = false;
                direction = PlayerDirection::West;
            }
        }
        else if (InputHandler::IsInputHeld(InputActions::Right))
        {
            position.x += speed;

            if (direction != PlayerDirection::East)
            {
                isMoving = false;
                direction = PlayerDirection::East;
            }
        }

        if (InputHandler::IsInputHeld(InputActions::Up) || InputHandler::IsInputHeld(InputActions::Down))
        {
            depth = position.y - 1;
            Game::RefreshDepth();
        }

        if (moving != isMoving)
        {
            isMoving = moving;
            sprite.Reset();
            if (isMoving)
            {
                switch (direction)
                {
                case PlayerDirection::North:
                    sprite.PushFrames(textureRects["walkNorth"]);
                    break;
                case PlayerDirection::East:
                    sprite.PushFrames(textureRects["walkEast"]);
                    break;
                case PlayerDirection::South:
                    sprite.PushFrames(textureRects["walkSouth"]);
                    break;
                case PlayerDirection::West:
                    sprite.PushFrames(textureRects["walkWest"]);
                    break;
                }
            }
            else
            {
                switch (direction)
                {
                case PlayerDirection::North:
                    sprite.PushFrames(textureRects["idleNorth"]);
                    break;
                case PlayerDirection::East:
                    sprite.PushFrames(textureRects["idleEast"]);
                    break;
                case PlayerDirection::South:
                    sprite.PushFrames(textureRects["idleSouth"]);
                    break;
                case PlayerDirection::West:
                    sprite.PushFrames(textureRects["idleWest"]);
                    break;
                }
            }
        }
        else if (sprite.GetFrames().size() == 0)
        {
            sprite.PushFrames(textureRects["idleSouth"]);
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