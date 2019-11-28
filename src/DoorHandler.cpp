#include "DoorHandler.h"

namespace UT
{
    static DoorHandler* instance;

    DoorHandler::DoorHandler()
    {
        instance = this;
    }

    size_t DoorHandler::AddDoor(Door* door)
    {
        doors.push_back(door);

        return doors.size() - 1;
    }

    DoorHandler* DoorHandler::GetThis()
    {
        return instance;
    }
}