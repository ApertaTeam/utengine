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
            sf::Vector2f roomSize = game->GetRoom()->GetSize();
            

            if (objectPos.x - viewSize.x / 2 > 0)
            {
                newView.left = objectPos.x - viewSize.x / 2;
            }
            
            if (objectPos.x + viewSize.x / 2 > roomSize.x)
            {
                newView.left = roomSize.x - viewSize.x;
            }

            if (objectPos.y - viewSize.y / 2 > 0)
            {
                newView.top = objectPos.y - viewSize.y / 2;
            }
            
            if (objectPos.y + viewSize.y / 2 > roomSize.y)
            {
                newView.top = roomSize.y - viewSize.y;
            }

            newView.width = viewSize.x;
            newView.height = viewSize.y;

            
            view = sf::View(newView);
        }
    }
}