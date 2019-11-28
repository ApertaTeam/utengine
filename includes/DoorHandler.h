#ifndef UT_DOOR_HANDLER_H
#define UT_DOOR_HANDLER_H
#include <vector>

#include "Game.h"
#include "Fader.h"
#include "CollisionHandler.h"

namespace UT
{
    enum class DoorType
    {
        DOOR,
        TELEPORTER,
        PITFALL
    };

    class DoorHandler : public Object
    {
    public:
        DoorHandler();

        virtual void Init() override;
        virtual void Update(float delta) override;

        static void StartTransition(DoorType type, int destRoom, sf::Vector2f destPosition, PlayerDirection playerDirection);

        static bool GetFading();
        
        static DoorHandler* GetInstance();

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        bool fading;
        DoorType type;
        int destRoom;
        sf::Vector2f destPosition;
        PlayerDirection playerDirection;
    };
}

#endif