#ifndef UT_GAME_H
#define UT_GAME_H

#include "Shader.h"
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

        bool Start();
        void AddObject(Object* object);

        // Getters
        Window GetWindow();
        double GetFPS();
        Room* GetRoom();
        Camera* GetCamera();
        Shader GetShaderProgram();

        // Setters
        void SetWindow(Window window);
        void SetRoom(Room* room);
        void SetCamera(Camera* camera);
        void SetShaderProgram(Shader shaderProgram);
    private:
        Window window;
        Shader shaderProgram;
        glm::mat4 modelMatrix;

        std::string title;
        double FPS;
        double lastFPSTime;

        Room* room;
        Camera* camera;
        std::vector<Object*> objects;
    };
}

#endif