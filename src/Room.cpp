#include "Room.h"

namespace UT
{
    Room::Room()
        : size({ 0, 0 })
    {

    }

    Room::Room(Vector2 size)
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

        isInitialized = true;
    }
}
