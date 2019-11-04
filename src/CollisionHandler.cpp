#include "CollisionHandler.h"
#include <iostream>
namespace UT
{
    static CollisionHandler* instance;

    CollisionHandler::CollisionHandler()
    {
        instance = this;
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

        return nullptr;
    }

    std::vector<Interactable*> CollisionHandler::CheckAllInteractablesDirect(sf::IntRect collisionBox, int padding)
    {
        std::vector<Interactable*> interactables;

        sf::IntRect mainRect = collisionBox;
        mainRect.left -= padding;
        mainRect.top -= padding;
        mainRect.width += padding * 2;
        mainRect.height += padding * 2;

        for (int i = 0; i < instance->objects.size(); i++)
        {
            sf::IntRect subRect = instance->objects[i]->GetCollisionBox();
            subRect.left += instance->objects[i]->getPosition().x;
            subRect.top += instance->objects[i]->getPosition().y;

            if ((subRect.left <= mainRect.left + mainRect.width
                && subRect.left + subRect.width >= mainRect.left
                && subRect.top <= mainRect.top + mainRect.height
                && subRect.top + subRect.height >= mainRect.top))
            {
                interactables.push_back(dynamic_cast<Interactable*>(instance->objects[i]));
            }
        }

        return interactables;
    }

    void CollisionHandler::UpdateObjects()
    {
        instance->objects = Game::GetObjects();
    }
}