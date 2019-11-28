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

        DoorHandler::GetInstance()->StartTransition(type, destRoom, destPosition, playerDirection);
    }

    void Door::Update(float delta)
    {
        if (!fading) return;

        if (!DoorHandler::GetInstance()->GetFading())
        {
            fading = false;
        }
    }

    void Door::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        
    }
}
