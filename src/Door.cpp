#include "Door.h"

namespace UT
{
    Door::Door()
        : destRoom(0), destPosition({ 0, 0 })
    {
        isAction = true;
    }

    Door::Door(int destRoom, sf::Vector2f destPosition)
        : destRoom(destRoom), destPosition(destPosition)
    {
        isAction = true;
    }

    void Door::Run()
    {

    }
}