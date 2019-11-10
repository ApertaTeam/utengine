#ifndef UT_DOOR_H
#define UT_DOOR_H

#include "Room.h"
#include "Interactable.h"
#include "Fader.h"

namespace UT
{
    enum DoorType
    {
        DOOR,
        TELEPORTER,
        PITFALL
    };

    // Interactable used for doors, teleporters and transitions
    class Door : public Interactable
    {
    public:
        Door(sf::IntRect collisionBox = { 0, 0, 0, 0 }, int destRoom = 0, sf::Vector2f destPosition = { 0, 0 }, DoorType type = DoorType::DOOR, bool stopMusic = false, PlayerDirection playerDirection = PlayerDirection::South);

        void Run() override;

        inline void SetDestRoom(int destRoom) { this->destRoom = destRoom; }
        inline int GetDestRoom() { return destRoom; }

        inline void SetDestPosition(sf::Vector2f destPosition) { this->destPosition = destPosition; }
        inline sf::Vector2f GetDestPosition() { return destPosition; }

        inline void SetStopMusic(bool stopMusic) { this->stopMusic = stopMusic; }
        inline bool GetStopMusic() { return stopMusic; }

        inline void SetPlayerDirection(PlayerDirection playerDirection) { this->playerDirection = playerDirection; }
        inline PlayerDirection GetPlayerDirection() { return playerDirection; }

        inline void SetType(DoorType type) { this->type = type; }
        inline DoorType GetType() { return type; }

        virtual void Update(float delta) override;

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        bool fading;
        int destRoom;
        sf::Vector2f destPosition;
        bool stopMusic;
        PlayerDirection playerDirection;
        DoorType type;
        Fader fader;
    };
}
#endif
