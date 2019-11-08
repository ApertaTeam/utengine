#ifndef UT_GAME_H
#define UT_GAME_H

#include "Common.h"
#include "Shader.h"
#include "Window.h"
#include "Input.h"
#include "Object.h"
#include "Room.h"

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

        Room* GetRoomInternal();
        static Room* GetRoomStatic();

        bool Start();

        void LoadRoomInternal(Room* room);

        // TODO: Replace with a method to load the room
        // from our binary file format.
        void LoadRoomInternal(int roomId);

        static void LoadRoom(int roomId);
        static void LoadRoom(Room* room);

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

        // TODO: Replace this map into a map of memory locations
        // in our binary file format.
        std::map<unsigned int, Room*> tempRoomList;
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
    };
}

#endif
