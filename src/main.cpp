#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Game.h"
#include "Window.h"
#include "Object.h"

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
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // This might be better set at 320x240
    glViewport(0, 0, 640, 480);

    while (!glfwWindowShouldClose(mainWindowPtr))
    {
        mainGame.Loop();
    }

    glfwTerminate();
    return 0;
}