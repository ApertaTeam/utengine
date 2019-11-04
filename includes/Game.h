#ifndef UT_GAME_H
#define UT_GAME_H

#include "Common.h"
#include "Shader.h"
#include "Window.h"
#include "Input.h"
#include "Object.h"

namespace UT
{
    // Handles a running instance of the game.
    class Game
    {
    public:
        Game(std::string title = "Undertale", unsigned int FPS = 30, sf::Image icon = sf::Image());
        ~Game();

        void Update();
        void Render();

        void Refresh();
        static void RefreshDepth();

        std::vector<Object*> GetObjectsInternal();
        static std::vector<Object*> GetObjects();

        bool Start();

		void LoadRoom(Room* room);

        // Getters
        Window GetWindow();
        double GetFPS();
        Room* GetRoom();
        Camera* GetCamera();
        Shader GetShaderProgram();

        // Setters
        void SetWindow(Window window);
        void SetCamera(Camera* camera);
        void SetShaderProgram(Shader shaderProgram);
    private:
        Window window;
        Shader shaderProgram;
        InputHandler inputHandler;

        std::string title;
		sf::Image icon;

        sf::Int32 FPS;
		sf::Clock FPStimeObj;

        Room* room;
        Camera* camera;
        std::vector<Object*> objects;
    };
}

#endif