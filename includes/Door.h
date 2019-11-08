#ifndef UT_DOOR_H
#define UT_DOOR_H

#include "Room.h"
#include "Interactable.h"

namespace UT
{
    enum DoorType
    {
        DOOR,
        TELEPORTER
    };

    // Interactable used for doors, teleporters and transitions
    class Door : public Interactable
    {
    public:
        Door();
        Door(sf::IntRect collisionBox, int destRoom, sf::Vector2f destPosition);

        void Run() override;

        inline void SetDestRoom(int destRoom) { this->destRoom = destRoom; }
        inline int GetDestRoom() { return destRoom; }

        inline void SetDestPosition(sf::Vector2f destPosition) { this->destPosition = destPosition; }
        inline sf::Vector2f GetDestPosition() { return destPosition; }

    protected:
        int destRoom;
        sf::Vector2f destPosition;
        bool stopMusic;
        DoorType type;
    };
}
#endif
