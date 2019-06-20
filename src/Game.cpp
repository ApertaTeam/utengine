#include "Game.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace UT
{
    Game::Game(Window* window)
    {
        this->winPtr = window->GetWin();
        this->window = window;
    }

    void Game::Loop()
    {
        glfwPollEvents();

        Render();
    }

    void Game::Render()
    {
        // Clear screen
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Render all objects
        for (int i = 0; i < this->objects.size(); i++)
        {
            objects[i]->Render();
        }

        // Show rendered buffer
        glfwSwapBuffers(winPtr);
    }

    void Game::AddObject(Object* object)
    {
        objects.push_back(object);
    }

    // Getters
    Window* Game::GetWindow()
    {
        return this->window;
    }

    // Setters
    void Game::SetWindow(Window* window)
    {
        this->winPtr = window->GetWin();
        this->window = window;
    }
}