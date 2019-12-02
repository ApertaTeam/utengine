#include "Room.h"

namespace UT
{
    Room::Room()
        : size({ 0, 0 })
    {

    }

    Room::Room(sf::Vector2f size)
        : size(size)
    {

    }

    void Room::Initialize()
    {
        if (isInitialized) return;
        for (auto& object : objects)
        {
            object->Init();
        }

        for (auto& interactable : interactables)
        {
            interactable->Init();
        }

        for (auto& tilemap : tilemaps)
        {
            tilemap->Init();
        }

        isInitialized = true;
    }
}
