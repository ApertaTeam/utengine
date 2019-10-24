#ifndef UT_CAMERA_H
#define UT_CAMERA_H

#include "Object.h"
#include "Common.h"
#include "Player.h"

#include <SFML/Graphics.hpp>

namespace UT
{
    // Handles the game camera movement
    class Camera
    {
    public:
        Camera(sf::Vector2f viewSize = { 320, 240 }, Object* trackedObject = nullptr);

        virtual void Update();

        inline void SetTrackedObject(Object* trackedObject);
        inline Object* GetTrackedObject();

        inline sf::View* GetView() { return &view; };

    private:
        Object* trackedObject;
        sf::View view;

        sf::Vector2f viewSize;
    };
}

#endif