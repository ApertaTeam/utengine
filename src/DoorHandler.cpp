#include "DoorHandler.h"
#include "Game.h"

namespace UT
{
    static DoorHandler* instance;

    DoorHandler::DoorHandler()
    {
        fading = false;
        instance = this;
        depth = 999999;
    }

    void DoorHandler::Init()
    {
        
    }

    void DoorHandler::StartTransition(DoorType type, int destRoom, sf::Vector2f destPosition, PlayerDirection playerDirection)
    {
        instance->type = type;
        instance->destRoom = destRoom;
        instance->destPosition = destPosition;
        instance->playerDirection = playerDirection;
        instance->fading = true;

        Fader::Setup();
        Game::GetPlayer()->canMove = false;
    }

    bool DoorHandler::GetFading()
    {
        return instance->fading;
    }

    DoorHandler* DoorHandler::GetInstance()
    {
        return instance;
    }

    void DoorHandler::Update(float delta)
    {
        if (fading)
        {
            if (Fader::IsDone())
            {
                if (!Fader::IsReversing())
                {
                    Game::LoadRoom(destRoom);
                    CollisionHandler::Reset();

                    Player* player = Game::GetPlayer();
                    player->position = destPosition;
                    player->direction = playerDirection;
                    Fader::Reverse();
                }
                else
                {
                    fading = false;
                    Game::GetPlayer()->canMove = true;
                }
            }
        }
        Fader::Update();
    }

    void DoorHandler::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(Fader::GetInstance(), states);
    }
}
