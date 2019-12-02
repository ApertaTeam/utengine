#ifndef UT_DOOR_H
#define UT_DOOR_H

#include "Room.h"
#include "Interactable.h"
#include "Fader.h"
#include "DoorHandler.h"

namespace UT
{
    // Interactable used for doors, teleporters and transitions
    class Door : public Interactable
    {
    public:
        Door(sf::IntRect collisionBox = { 0, 0, 0, 0 }, int destRoom = 0, sf::Vector2f destPosition = { 0, 0 }, DoorType type = DoorType::DOOR, bool stopMusic = false, PlayerDirection playerDirection = PlayerDirection::South);

        void Run() override;

        virtual void Update(float delta) override;


        int destRoom;
        sf::Vector2f destPosition;
        bool stopMusic;
        PlayerDirection playerDirection;
        DoorType type;

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        bool fading;
    };
}
#endif
