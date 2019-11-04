#ifndef UT_COLLISION_HANDLER_H
#define UT_COLLISION_HANDLER_H

#include "Game.h"
#include "Object.h"

namespace UT
{
    class CollisionHandler
    {
    public:
        CollisionHandler();
        static bool CheckCollision(Object* objectA, Object* objectB);
        static Object* CheckAllCollisions(Object* object);
        static bool CheckCollisionDirect(sf::IntRect posA, sf::IntRect posB);
        static Object* CheckAllCollisionsMovement(Object* object, sf::Vector2f nextPos);

        static void UpdateObjects();

    private:
        std::vector<Object*> objects;
    };
}
#endif