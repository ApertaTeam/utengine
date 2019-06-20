#ifndef UT_GAME_H
#define UT_GAME_H

#include "Window.h"
#include "Object.h"

namespace UT
{
	class Game
	{
	public:
		Game(Window* window);

		void Loop();
		void Render();

		void AddObject(Object* object);

		// Getters
		Window* GetWindow();

		// Setters
		void SetWindow(Window* window);
	private:
		Window* window;
		std::vector<Object*> objects;
	};
}

#endif