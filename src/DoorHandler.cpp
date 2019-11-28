#include "DoorHandler.h"

namespace UT
{
    DoorHandler DoorHandler::instance = DoorHandler();

    void DoorHandler::Init()
    {
        currentDoor = 0;
    }

    size_t DoorHandler::AddDoor(Door* door)
    {
        instance.doors.push_back(door);

        return instance.doors.size() - 1;
    }

    void DoorHandler::StartTransition(DoorType type, int destRoom, sf::Vector2f destPosition, PlayerDirection playerDirection)
    {
        instance.type = type;
        instance.destRoom = destRoom;
        instance.destPosition = destPosition;
        instance.playerDirection = playerDirection;
        instance.fading = true;

        Fader::Setup();
        Game::GetRoomStatic()->GetPlayer()->SetCanMove(false);
    }

    DoorHandler& DoorHandler::GetInstance()
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

                    Player* player = Game::GetRoomStatic()->GetPlayer();
                    player->SetPosition(destPosition);
                    player->SetDirection(playerDirection);
                    Fader::Reverse();
                }
                else
                {
                    fading = false;
                    Game::GetRoomStatic()->GetPlayer()->SetCanMove(true);
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