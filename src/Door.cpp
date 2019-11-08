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
        isAction = true;
    }

    void Door::Run()
    {
        Game::LoadRoom(destRoom);
        CollisionHandler::Reset();

        Player* player = Game::GetRoomStatic()->GetPlayer();
        player->SetPosition(destPosition);
        player->SetDirection(playerDirection);
    }
}
