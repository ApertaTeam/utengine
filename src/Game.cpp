#include "Game.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace UT
{
	Game::Game(Window* window)
	{
		this->window = window;
	}

	void Game::Loop()
	{
		glfwPollEvents();

		Render();
	}

	void Game::Render()
	{
		glClearColor(0.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Render all objects
		for (int i = 0; i < this->objects.size(); i++)
		{
			objects[i]->Render();
		}

		glfwSwapBuffers(this->window->GetWin());
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
		this->window = window;
	}
}