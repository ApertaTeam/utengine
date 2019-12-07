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

        inline sf::View* GetView() { return &view; };


        Object* trackedObject;
        ViewZone* viewZone;
    
    private:
        Game* game;
        sf::View view;

        sf::Vector2f viewSize;
        
    };
}

#endif