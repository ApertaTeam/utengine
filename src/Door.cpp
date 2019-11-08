#include "Door.h"
#include "Game.h"
#include "CollisionHandler.h"

namespace UT
{
    Door::Door()
        : destRoom(-1), destPosition({ 0, 0 })
    {
        collisionBox = sf::IntRect(0,0,0,0);
        isAction = true;
    }

    Door::Door(sf::IntRect collisionBox, int destRoom, sf::Vector2f destPosition)
        : destRoom(destRoom), destPosition(destPosition)
    {
        this->collisionBox = collisionBox;
        isAction = true;
    }

    void Door::Run()
    {
        Game::LoadRoom(destRoom);
        CollisionHandler::Reset();
        /*auto room = Game::GetRoomStatic();
        for (auto object : room->GetObjects())
        {
            if (Player* player = dynamic_cast<Player*>(object); player != nullptr)
            {
                player->SetPosition(destPosition);
                break;
            }
        }*/
    }
}
