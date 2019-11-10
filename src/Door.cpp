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
        this->fader = Fader({0, 0, 640, 480}, 10);
        isAction = true;
        depth = 4000;
    }

    void Door::Run()
    {
        if (fading) return;
        fading = true;
        fader.Init();
        /*Game::LoadRoom(destRoom);
        CollisionHandler::Reset();

        Player* player = Game::GetRoomStatic()->GetPlayer();
        player->SetPosition(destPosition);
        player->SetDirection(playerDirection);*/
    }

    void Door::Update(float delta)
    {
        if (fading)
        {
            if (fader.IsDone())
            {
                fading = false;
                Game::LoadRoom(destRoom);
                CollisionHandler::Reset();
                
                Player* player = Game::GetRoomStatic()->GetPlayer();
                player->SetPosition(destPosition);
                player->SetDirection(playerDirection);
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
