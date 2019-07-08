#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Game.h"
#include "Window.h"
#include "Object.h"
#include "Logger.h"

#include <iostream>


using namespace UT;

int main()
{
    glfwInit();
    
    Window mainWindow = Window("Undertale", { 640, 480 }, {
        WindowFlags::Visible,
        WindowFlags::Decorated,
        WindowFlags::Focused,
        WindowFlags::FocusOnShow
    });
    mainWindow.CenterWindow();

    Game mainGame = Game(&mainWindow);

    GLFWwindow* mainWindowPtr = mainWindow.GetWin();
    glfwMakeContextCurrent(mainWindowPtr);

    if (glewInit() != GLEW_OK)
    {
        GlobalLogger->Log(Logger::Error, "Failed to initialize GLEW.");
        return -1;
    }

    while (!glfwWindowShouldClose(mainWindowPtr))
    {
        mainGame.Update();
    }

    glfwTerminate();
    return 0;
}