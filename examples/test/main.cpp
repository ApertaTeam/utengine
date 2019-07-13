#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Game.h"
#include "Window.h"
#include "Object.h"
#include "Logger.h"
#include "Resources.h"
#include "Camera.h"

#include "ObjTest.h"

#include <iostream>


using namespace UT;
using namespace UTEXAMPLE;

int main()
{
    // Create main game object
    Game mainGame = Game("Undertale", 30);

    // Create main camera object
    Camera mainCamera = Camera();

    // Attach camera
    mainGame.SetCamera(&mainCamera);

    // Add test object
    ObjTest testObject = ObjTest();

    mainGame.AddObject(&testObject);

    // Initialize game object
    if (!mainGame.Start())
    {
        GlobalLogger->Log(Logger::Error, "Failed to initialize game object.");
        return -1;
    }

    return 0;
}