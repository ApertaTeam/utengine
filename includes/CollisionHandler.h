#ifndef UT_COLLISION_HANDLER_H
#define UT_COLLISION_HANDLER_H

#include "Object.h"
#include "Interactable.h"
#include "Zone.h"

namespace UT
{
    class ViewZone;

    class CollisionHandler
    {
    public:
        CollisionHandler();

        static bool CheckCollision(Object* objectA, Object* objectB);
        static Object* CheckAllCollisions(Object* object);
        static ViewZone* CheckAllViewZoneCollisions(Object* object);
        static bool CheckCollisionDirect(sf::IntRect posA, sf::IntRect posB);
        static sf::Vector2f CheckAllCollisionsMovement(Object* object, sf::Vector2f curPos, sf::Vector2f nextPos);

        static std::vector<Interactable*> CheckAllInteractables(sf::IntRect collisionBox, int padding);

        static void Reset();

    private:
        std::vector<Object*>* objects;
        std::vector<Zone*>* zones;
    };
}
#endif
