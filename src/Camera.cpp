#include "Camera.h"
#include "Game.h"

namespace UT
{
    Camera::Camera(Game* game, sf::Vector2f viewSize, Object* trackedObject)
    {
        this->game = game;
        this->trackedObject = trackedObject;
        this->viewSize = viewSize;
        this->view = sf::View({0.0, 0.0, (float)viewSize.x, (float)viewSize.y});
    }

    void Camera::Update()
    {
        if (trackedObject != nullptr)
        {
            sf::Vector2f objectPos = trackedObject->getPosition();
            sf::FloatRect newView = {0, 0, 0, 0};
            Vector2 roomSize = game->GetRoom()->size;
            

            if (objectPos.x - viewSize.x / 2 > 0)
            {
                newView.left = objectPos.x - viewSize.x / 2;
            }
            
            if (objectPos.x + viewSize.x / 2 > roomSize.x)
            {
                newView.left = 320 - viewSize.x;
            }

            if (objectPos.y - viewSize.y / 2 > 0)
            {
                newView.top = objectPos.y - viewSize.y / 2;
            }
            
            if (objectPos.y + viewSize.y / 2 > roomSize.y)
            {
                newView.top = 240 - viewSize.y;
            }

            newView.width = viewSize.x;
            newView.height = viewSize.y;

            
            view = sf::View(newView);
        }
    }

    // Getters
    Object* Camera::GetTrackedObject()
    {
        return this->trackedObject;
    }

    // Setters
    void Camera::SetTrackedObject(Object* trackedObject)
    {
        this->trackedObject = trackedObject;
    }
}