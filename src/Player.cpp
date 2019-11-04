#include "Player.h"
#include "Input.h"
#include "Game.h"
#include "CollisionHandler.h"

namespace UT
{
    Player::Player(std::map<std::string, std::vector<sf::IntRect>> frames)
        : textureRects(frames), texture(-1), speed(3), direction(PlayerDirection::South), isMoving(false), canMove(true)
    {

    }

    void Player::Init()
    {
        sprite.SetSpeed(4);
    }

    void Player::AddTextureRect(std::string name, std::vector<sf::IntRect> textureRect)
    {
        this->textureRects.insert(std::pair(name, textureRect));
    }

    void Player::Update(float delta)
    {
        int curFrame = sprite.GetImageIndex();
        sf::Vector2f oldPosition = position;

        bool moving = (InputHandler::IsInputHeld(InputActions::Left)
            || InputHandler::IsInputHeld(InputActions::Right)
            || InputHandler::IsInputHeld(InputActions::Up)
            || InputHandler::IsInputHeld(InputActions::Down));
       
        if (InputHandler::IsInputHeld(InputActions::Left))
        {
            position.x -= speed;

            if (direction != PlayerDirection::West && !InputHandler::IsInputHeld(InputActions::Up) && !InputHandler::IsInputHeld(InputActions::Down))
            {
                isMoving = false;
                direction = PlayerDirection::West;
            }
        }
        else if (InputHandler::IsInputHeld(InputActions::Right))
        {
            position.x += speed;

            if (direction != PlayerDirection::East && !InputHandler::IsInputHeld(InputActions::Up) && !InputHandler::IsInputHeld(InputActions::Down))
            {
                isMoving = false;
                direction = PlayerDirection::East;
            }
        }

        if (CollisionHandler::CheckAllCollisions(this) != nullptr)
        {
            position.x = oldPosition.x;
        }

        if (InputHandler::IsInputHeld(InputActions::Up))
        {
            position.y -= speed;

            if (direction != PlayerDirection::North)
            {
                if (direction != PlayerDirection::NorthEast && InputHandler::IsInputHeld(InputActions::Right))
                {
                    if (direction != PlayerDirection::North && direction != PlayerDirection::NorthEast && direction != PlayerDirection::NorthWest)
                    {
                        isMoving = false;
                    }

                    direction = PlayerDirection::NorthEast;
                }
                else if(direction != PlayerDirection::NorthWest && InputHandler::IsInputHeld(InputActions::Left))
                {
                    if (direction != PlayerDirection::North && direction != PlayerDirection::NorthEast && direction != PlayerDirection::NorthWest)
                    {
                        isMoving = false;
                    }

                    direction = PlayerDirection::NorthWest;
                }
                else if (!InputHandler::IsInputHeld(InputActions::Left) && !InputHandler::IsInputHeld(InputActions::Right))
                {
                    isMoving = false;
                    direction = PlayerDirection::North;
                }
            }
        }
        else if (InputHandler::IsInputHeld(InputActions::Down))
        {
            position.y += speed;

            if (direction != PlayerDirection::South)
            {
                if (direction != PlayerDirection::SouthEast && InputHandler::IsInputHeld(InputActions::Right))
                {
                    if (direction != PlayerDirection::South && direction != PlayerDirection::SouthEast && direction != PlayerDirection::SouthWest)
                    {
                        isMoving = false;
                    }

                    direction = PlayerDirection::SouthEast;
                }
                else if (direction != PlayerDirection::SouthWest && InputHandler::IsInputHeld(InputActions::Left))
                {
                    if (direction != PlayerDirection::South && direction != PlayerDirection::SouthEast && direction != PlayerDirection::SouthWest)
                    {
                        isMoving = false;
                    }

                    direction = PlayerDirection::SouthWest;
                }
                else if(!InputHandler::IsInputHeld(InputActions::Left) && !InputHandler::IsInputHeld(InputActions::Right))
                {
                    isMoving = false;
                    direction = PlayerDirection::South;
                }
            }
        }

        if (CollisionHandler::CheckAllCollisions(this) != nullptr)
        {
            position.y = oldPosition.y;
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
                case PlayerDirection::NorthWest:
                    sprite.PushFrames(textureRects["walkNorth"]);
                    break;
                case PlayerDirection::NorthEast:
                    sprite.PushFrames(textureRects["walkNorth"]);
                    break;
                case PlayerDirection::East:
                    sprite.PushFrames(textureRects["walkEast"]);
                    break;
                case PlayerDirection::South:
                    sprite.PushFrames(textureRects["walkSouth"]);
                    break;
                case PlayerDirection::SouthWest:
                    sprite.PushFrames(textureRects["walkSouth"]);
                    break;
                case PlayerDirection::SouthEast:
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
                case PlayerDirection::NorthWest:
                    sprite.PushFrames(textureRects["idleNorth"]);
                    break;
                case PlayerDirection::NorthEast:
                    sprite.PushFrames(textureRects["idleNorth"]);
                    break;
                case PlayerDirection::East:
                    sprite.PushFrames(textureRects["idleEast"]);
                    break;
                case PlayerDirection::South:
                    sprite.PushFrames(textureRects["idleSouth"]);
                    break;
                case PlayerDirection::SouthWest:
                    sprite.PushFrames(textureRects["idleSouth"]);
                    break;
                case PlayerDirection::SouthEast:
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