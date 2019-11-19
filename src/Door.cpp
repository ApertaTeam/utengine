#include "Door.h"
#include "Game.h"
#include "CollisionHandler.h"

namespace UT
{
    Door::Door(sf::IntRect collisionBox, int destRoom, sf::Vector2f destPosition, DoorType type, bool stopMusic, PlayerDirection playerDirection)
    {
        this->destRoom = destRoom;
        this->destPosition = destPosition;
        this->collisionBox = collisionBox;
        this->type = type;
        this->stopMusic = stopMusic;
        this->playerDirection = playerDirection;
        this->fading = false;
        isAction = true;
        depth = 999999;
    }

    void Door::Run()
    {
        if (fading) return;
        fading = true;
        Fader::Setup();
        Game::GetRoomStatic()->GetPlayer()->SetCanMove(false);
    }

    void Door::Update(float delta)
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

    void Door::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(Fader::GetInstance(), states);
    }
}
