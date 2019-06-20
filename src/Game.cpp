#include "Game.h"

namespace UT
{
	Game::Game(Window* window)
	{
		this->window = window;
	}

	void Game::Loop()
	{
		Render();
	}

	void Game::Render()
	{
		// Render all objects
		for (int i = 0; i < this->objects.size(); i++)
		{
			objects[i]->Render();
		}
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