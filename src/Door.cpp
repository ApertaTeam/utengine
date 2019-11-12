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
        this->fader = Fader({0, 0, 640, 480}, 1);
        isAction = true;
        depth = 999999;
    }

    void Door::Run()
    {
        if (fading) return;
        fading = true;
        fader.Init();
    }

    void Door::Update(float delta)
    {
        if (fading)
        {
            if (fader.IsDone())
            {
                if (!fader.IsReversing())
                {
                    Game::LoadRoom(destRoom);
                    CollisionHandler::Reset();
                    
                    Player* player = Game::GetRoomStatic()->GetPlayer();
                    player->SetPosition(destPosition);
                    player->SetDirection(playerDirection);
                    fader.Reverse();
                }
                else
                {
                    fading = false;
                }
            }
            else
            {
                fader.Update(delta);
            }
        }
    }

    void Door::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if (fading) target.draw(fader, states);
    }
}
