#include <GL/glew.h>
#include <GLFW/glfw3.h>

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
    // Create main game object
    Game mainGame = Game("Undertale", 30);

    // Create main camera object
    Camera mainCamera = Camera();

    // Attach camera
    mainGame.SetCamera(&mainCamera);

    // Initialize game object
    if (!mainGame.Init())
    {
        GlobalLogger->Log(Logger::Error, "Failed to initialize game object.");
        return -1;
    }

    // Get pointer to main GLFW window
    GLFWwindow* mainWindowPtr = mainGame.GetWindow().GetWin();

    // Main loop
    while (!glfwWindowShouldClose(mainWindowPtr))
    {
        mainGame.Update();
    }

    return 0;
}