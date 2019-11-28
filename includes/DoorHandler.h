#ifndef UT_DOOR_HANDLER_H
#define UT_DOOR_HANDLER_H
#include <vector>

#include "Game.h"
#include "Door.h"
#include "CollisionHandler.h"

namespace UT
{
    enum DoorType
    {
        DOOR,
        TELEPORTER,
        PITFALL
    };

    class DoorHandler : public Object
    {
    public:
        virtual void Init() override;
        virtual void Update(float delta) override;

        static size_t AddDoor(Door* door);
        static void StartTransition(DoorType type, int destRoom, sf::Vector2f destPosition, PlayerDirection playerDirection);

        static void Update();
        
        static DoorHandler& GetInstance();

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        static DoorHandler instance;

        std::vector<Door*> doors;
        size_t currentDoor;
        bool fading;
        DoorType type;
        int destRoom;
        sf::Vector2f destPosition;
        PlayerDirection playerDirection;
    };
}

#endif