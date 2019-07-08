#ifndef UT_GAME_H
#define UT_GAME_H

#include <GL/glew.h>

#include "Window.h"
#include "Object.h"

namespace UT
{
    // Handles a running instance of the game.
    class Game
    {
    public:
        Game(Window* window, unsigned int FPS = 30);
        ~Game();

        void Update();
        void Render();

        void Init();
        void AddObject(Object* object);

        // Getters
        Window* GetWindow();
        unsigned int GetFPS();

        // Setters
        void SetWindow(Window* window);
    private:
        Window* window;
        GLuint shaderProgram;

        double FPS;
        std::vector<Object*> objects;


        double lastFPSTime;
    };
}

#endif