#include "CollisionHandler.h"
#include <iostream>
#include <vector>

namespace UT
{
    static CollisionHandler* instance;

    CollisionHandler::CollisionHandler()
        : objects(Game::GetRoomStatic()->GetObjects()), interactables(Game::GetRoomStatic()->GetInteractables())
    {
        instance = this;
    }

    void CollisionHandler::Reset()
    {
        instance->objects = Game::GetRoomStatic()->GetObjects();
        instance->interactables = Game::GetRoomStatic()->GetInteractables();
    }

    bool CollisionHandler::CheckCollision(Object* objectA, Object* objectB)
    {
        sf::IntRect mainRect = objectA->GetCollisionBox();
        mainRect.left += objectA->getPosition().x;
        mainRect.top += objectA->getPosition().y;

        sf::IntRect subRect = objectB->GetCollisionBox();
        subRect.left += objectB->getPosition().x;
        subRect.top += objectB->getPosition().y;

        if ((subRect.left <= mainRect.left + mainRect.width
            && subRect.left + subRect.width >= mainRect.left
            && subRect.top <= mainRect.top + mainRect.height
            && subRect.top + subRect.height >= mainRect.top))
        {
            return true;
        }

        return false;
    }

    Object* CollisionHandler::CheckAllCollisions(Object* object)
    {
        sf::IntRect mainRect = object->GetCollisionBox();
        mainRect.left += object->getPosition().x;
        mainRect.top += object->getPosition().y;

        for (int i = 0; i < instance->objects.size(); i++)
        {
            if (instance->objects[i] != object)
            {
                sf::IntRect subRect = instance->objects[i]->GetCollisionBox();
                subRect.left += instance->objects[i]->getPosition().x;
                subRect.top += instance->objects[i]->getPosition().y;

                if ((subRect.left <= mainRect.left + mainRect.width
                    && subRect.left + subRect.width >= mainRect.left
                    && subRect.top <= mainRect.top + mainRect.height
                    && subRect.top + subRect.height >= mainRect.top))
                {
                    return instance->objects[i];
                }
            }
        }

        for (int i = 0; i < instance->interactables.size(); i++)
        {
            if (instance->interactables[i] != object)
            {
                sf::IntRect subRect = instance->interactables[i]->GetCollisionBox();
                subRect.left += instance->interactables[i]->getPosition().x;
                subRect.top += instance->interactables[i]->getPosition().y;

                if ((subRect.left <= mainRect.left + mainRect.width
                    && subRect.left + subRect.width >= mainRect.left
                    && subRect.top <= mainRect.top + mainRect.height
                    && subRect.top + subRect.height >= mainRect.top))
                {
                    return instance->interactables[i];
                }
            }
        }

        return nullptr;
    }

    bool CollisionHandler::CheckCollisionDirect(sf::IntRect posA, sf::IntRect posB)
    {
        if ((posB.left <= posA.left + posA.width
            && posB.left + posB.width >= posA.left
            && posB.top <= posA.top + posA.height
            && posB.top + posB.height >= posA.top))
        {
            return true;
        }

        return false;
    }

    Object* CollisionHandler::CheckAllCollisionsMovement(Object* object, sf::Vector2f nextPos)
    {
        sf::IntRect mainRect = object->GetCollisionBox();
        mainRect.left += nextPos.x;
        mainRect.top += nextPos.y;

        for (int i = 0; i < instance->objects.size(); i++)
        {
            if (instance->objects[i] != object)
            {
                sf::IntRect subRect = instance->objects[i]->GetCollisionBox();
                subRect.left += instance->objects[i]->getPosition().x;
                subRect.top += instance->objects[i]->getPosition().y;

                if ((subRect.left <= mainRect.left + mainRect.width
                    && subRect.left + subRect.width >= mainRect.left
                    && subRect.top <= mainRect.top + mainRect.height
                    && subRect.top + subRect.height >= mainRect.top))
                {
                    return instance->objects[i];
                }
            }
        }

        for (int i = 0; i < instance->interactables.size(); i++)
        {
            if (instance->interactables[i] != object)
            {
                sf::IntRect subRect = instance->interactables[i]->GetCollisionBox();
                subRect.left += instance->interactables[i]->getPosition().x;
                subRect.top += instance->interactables[i]->getPosition().y;

                if ((subRect.left <= mainRect.left + mainRect.width
                    && subRect.left + subRect.width >= mainRect.left
                    && subRect.top <= mainRect.top + mainRect.height
                    && subRect.top + subRect.height >= mainRect.top))
                {
                    return instance->interactables[i];
                }
            }
        }

        return nullptr;
    }

    std::vector<Interactable*> CollisionHandler::CheckAllDirect(sf::IntRect collisionBox, int padding)
    {
        std::vector<Interactable*> interactables = std::vector<Interactable*>();
        sf::IntRect mainRect = collisionBox;
        mainRect.left -= padding;
        mainRect.top -= padding;
        mainRect.width += padding * 2;
        mainRect.height += padding * 2;

        for (int i = 0; i < instance->interactables.size(); i++)
        {
            sf::IntRect subRect = instance->interactables[i]->GetCollisionBox();
            subRect.left += instance->interactables[i]->getPosition().x;
            subRect.top += instance->interactables[i]->getPosition().y;

            if ((subRect.left <= mainRect.left + mainRect.width
                && subRect.left + subRect.width >= mainRect.left
                && subRect.top <= mainRect.top + mainRect.height
                && subRect.top + subRect.height >= mainRect.top))
            {
                Interactable* inst = instance->interactables[i];
                if (!inst->persists) instance->interactables.erase(instance->interactables.begin()+i);
                interactables.push_back(inst);
            }
        }

        return interactables;
    }
}
