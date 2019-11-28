#ifndef UT_DOOR_HANDLER_H
#define UT_DOOR_HANDLER_H
#include <vector>

#include "Door.h"

namespace UT
{
    class DoorHandler
    {
    public:
        DoorHandler();

        size_t AddDoor(Door* door);

        static DoorHandler* GetThis();

    private:
        std::vector<Door*> doors;

    };
}

#endif