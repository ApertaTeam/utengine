#include "Camera.h"
#include "Game.h"

#include <iostream>

namespace UT
{
    Camera::Camera(Game* game, sf::Vector2f viewSize, Object* trackedObject)
    {
        this->game = game;
        this->trackedObject = trackedObject;
        this->viewSize = viewSize;
        this->view = sf::View({0.0, 0.0, (float)viewSize.x, (float)viewSize.y});
        this->viewZone = nullptr;
        this->currentBounds = { 0, 0, 0, 0 };
        this->interpolationSpeed = 5;
        this->isInterpolating = false;
    }

    void Camera::Update()
    {
        if (trackedObject != nullptr)
        {
            sf::Vector2f objectPos = trackedObject->getPosition();
            sf::FloatRect newView = {0, 0, 0, 0};
            sf::IntRect boundaries;
            if (viewZone == nullptr)
            {
                boundaries = { 0, 0, game->GetRoom()->GetSize().x, game->GetRoom()->GetSize().y };
            }
            else
            {
                boundaries = viewZone->bounds;
            }
            

            if (isInterpolating)
            {
                if (currentBounds.left < boundaries.left)
                {
                    currentBounds.left += interpolationSpeed;
                }
                else if (currentBounds.left > boundaries.left)
                {
                    currentBounds.left -= interpolationSpeed;
                }

                if (currentBounds.left + interpolationSpeed > boundaries.left&& currentBounds.left - interpolationSpeed < boundaries.left)
                {
                    currentBounds.left = boundaries.left;
                }


                if (currentBounds.top < boundaries.top)
                {
                    currentBounds.top += interpolationSpeed;
                }
                else if (currentBounds.top > boundaries.top)
                {
                    currentBounds.top -= interpolationSpeed;
                }

                if (currentBounds.top + interpolationSpeed > boundaries.top && currentBounds.top - interpolationSpeed < boundaries.top)
                {
                    currentBounds.top = boundaries.top;
                }


                if (currentBounds.left == boundaries.left && currentBounds.top == boundaries.top)
                {
                    isInterpolating = false;
                }
                std::cout << currentBounds.left << " - " << boundaries.left << std::endl;
            
                newView.left = currentBounds.left;
                newView.top = currentBounds.top;
            }
            else
            {
                // Horizontal
                if (objectPos.x - viewSize.x / 2 > boundaries.left)
                {
                    newView.left = objectPos.x - viewSize.x / 2;
                }
                else
                {
                    newView.left = boundaries.left;
                }

                if (objectPos.x + viewSize.x / 2 > boundaries.left + boundaries.width)
                {
                    newView.left = boundaries.left + boundaries.width - viewSize.x;
                }

                // Vertical
                if (objectPos.y - viewSize.y / 2 > boundaries.top)
                {
                    newView.top = objectPos.y - viewSize.y / 2;
                }
                else
                {
                    newView.top = boundaries.top;
                }

                if (objectPos.y + viewSize.y / 2 > boundaries.top + boundaries.height)
                {
                    newView.top = boundaries.top + boundaries.height - viewSize.y;
                }
            }


            newView.width = viewSize.x;
            newView.height = viewSize.y;

            if (viewZone == nullptr && !isInterpolating)
            {
                currentBounds = (sf::IntRect)newView;
            }

            
            view = sf::View(newView);
        }
    }

    void Camera::SetViewZone(ViewZone* viewZone)
    {
        if (viewZone != this->viewZone)
        {
            if (this->interpolationSpeed != -1)
            {
                this->isInterpolating = true;
            }

            this->viewZone = viewZone;
        }
    }
}