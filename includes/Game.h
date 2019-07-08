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
        Game(std::string title = "Undertale", unsigned int FPS = 30);
        ~Game();

        void Update();
        void Render();

        bool Init();
        void AddObject(Object* object);

        // Getters
        Window GetWindow();
        double GetFPS();
        Room* GetRoom();
        Camera* GetCamera();
        GLuint GetShaderProgram();

        // Setters
        void SetWindow(Window window);
        void SetRoom(Room* room);
        void SetCamera(Camera* camera);
        void SetShaderProgram(GLuint shaderProgram);
    private:
        Window window;
        GLuint shaderProgram;

        std::string title;
        double FPS;
        double lastFPSTime;

        Room* room;
        Camera* camera;
        std::vector<Object*> objects;
    };
}

#endif