#ifndef UT_CAMERA_H
#define UT_CAMERA_H

#include "ViewZone.h"
#include "Object.h"
#include "Common.h"
#include "Player.h"

#include <SFML/Graphics.hpp>

namespace UT
{
    class Game;

    // Handles the game camera movement
    class Camera
    {
    public:
        Camera(Game* game, sf::Vector2f viewSize = { 320, 240 }, Object* trackedObject = nullptr);

        virtual void Update();

        inline sf::View* GetView() { return &view; }

        void SetViewZone(ViewZone* viewZone);
        inline ViewZone* GetViewZone() { return viewZone; }


        Object* trackedObject;
        int interpolationSpeed;
    
    private:
        Game* game;
        sf::View view;
        ViewZone* viewZone;
        sf::IntRect currentBounds;

        sf::Vector2f viewSize;
        bool isInterpolating;
    };
}

#endif