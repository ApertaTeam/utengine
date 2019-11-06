#ifndef UT_COLLISION_HANDLER_H
#define UT_COLLISION_HANDLER_H

#include "Game.h"
#include "Object.h"
#include "Interactable.h"

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

        static std::vector<Interactable*> CheckAllDirect(sf::IntRect collisionBox, int padding);

    private:
        std::vector<Object*>& objects;
        std::vector<Interactable*>& interactables;
    };
}
#endif
