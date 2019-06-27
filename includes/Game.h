#ifndef UT_GAME_H
#define UT_GAME_H

#include "Window.h"
#include "Object.h"

namespace UT
{
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
        GLFWwindow* winPtr;
        GLuint shaderProgram;

        unsigned int FPS;
        std::vector<Object*> objects;


        double lastFPSTime;
        double FPSTime;
        double deltaFPSTime;
    };
}

#endif