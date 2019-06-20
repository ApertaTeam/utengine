#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Game.h"
#include "Window.h"
#include "Object.h"

#include <iostream>

int main()
{
    glfwInit();
    
	UT::Window mainWindow = UT::Window("Undertale", { 640, 480 }, {
		UT::WindowFlags::Visible,
		UT::WindowFlags::Decorated,
		UT::WindowFlags::Focused,
		UT::WindowFlags::FocusOnShow
		});
	UT::Game mainGame = UT::Game(&mainWindow);

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