#ifndef UT_GAME_H
#define UT_GAME_H

#include "Common.h"
#include "Shader.h"
#include "Window.h"
#include "Input.h"
#include "Object.h"
#include "Room.h"
#include "DialogueHandler.h"
#include "CollisionHandler.h"
#include "DoorHandler.h"
#include "SaveHandler.h"

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

        inline void AddGlobalObject(Object* object) { globalObjects.push_back(object); }

        // TODO: Replace with a method to load the room
        // from our binary file format.
        void LoadRoomInternal(int roomId);

        static void LoadRoom(int roomId);
        static void LoadRoom(Room* room);

        double GetFPS();
        std::string GetTitle();
        Room* GetRoom();
        static Game* GetInstance();

        // TODO: Replace this map into a map of memory locations
        // in our binary file format.
        std::map<unsigned int, Room*> tempRoomList;


        Window window;
        Camera* camera;
        Shader shaderProgram;

    private:
        InputHandler inputHandler;

        std::string title;
		sf::Image icon;

        sf::Int32 FPS;
		sf::Clock FPStimeObj;

        std::vector<Object*> globalObjects;

        Room* room;

        CollisionHandler collisionHandler;
        SaveHandler saveHandler;
        DialogueHandler dialogueHandler;
        DoorHandler doorHandler;
    };
}

#endif
