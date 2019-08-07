#include "Game.h"
#include "Window.h"
#include "Object.h"
#include "Logger.h"
#include "Resources.h"
#include "Camera.h"

#include <iostream>


using namespace UT;

int main()
{
	// Load game icon
	sf::Image gameIcon = sf::Image();
	gameIcon.loadFromFile("test.png");

    // Create main game object
	Game mainGame = Game("Undertale", 30, gameIcon);

    // Create main camera object
    Camera mainCamera = Camera();

    // Attach camera
    mainGame.SetCamera(&mainCamera);

    // Initialize game object
    if (!mainGame.Start())
    {
        GlobalLogger->Log(Logger::Error, "Failed to initialize game object.");
        return -1;
    }

    return 0;
}