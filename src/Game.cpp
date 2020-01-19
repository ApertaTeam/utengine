#include "Game.h"

#include <algorithm>

#include "Resources.h"
#include "Logger.h"
#include "Sprite.h"
#include "AssetHandler.h"
#include "BatchHandler.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <sstream>

namespace UT
{
    static Game* instance;

    Game::Game(std::string title, unsigned int FPS, sf::Image icon)
    {
        this->title = title;
        this->icon = icon;

        this->FPS = FPS;
        this->FPStimeObj = sf::Clock();

        this->room = nullptr;
        this->camera = nullptr;

        this->globalObjects = {};

        // Add global objects
        globalObjects.push_back(&dialogueHandler); UIObjects.push_back(&dialogueHandler);
        globalObjects.push_back(&doorHandler);

        #ifdef UT_DEBUG
        globalObjects.push_back(&terminal); UIObjects.push_back(&terminal);
        #endif

        instance = this;
    }

    Game::~Game()
    {
        AssetHandler::ClearTextures();
    }

    void Game::Update()
    {
        sf::Int32 FPStime = FPStimeObj.getElapsedTime().asMilliseconds();

        // Event polling
        sf::Event event;
        while (window->pollEvent(event))
        {
            inputHandler.Update(event, !window->hasFocus());

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape) window->close();
            }
            else if (event.type == sf::Event::Closed)
            {
                window->close();
            }
        }

        // FPS check
        if (FPStime >= FPS)
        {
            double delta = FPStimeObj.restart().asSeconds();
            const double deltaCalculations = 1.0 / ((double)FPS - 10);
            if (delta > deltaCalculations)
            {
                delta = deltaCalculations;
            }


            // Run main update method for all objects
            std::vector<Object*> objects = room->GetObjects();
            objects.reserve(objects.size() + globalObjects.size() + 1);
            objects.insert(objects.end(), globalObjects.begin(), globalObjects.end());
            objects.insert(objects.end(), player);
            for (int i = 0; i < objects.size(); i++)
            {
                objects[i]->Update((float)delta);
            }


            camera->Update();
            window->setView(*camera->GetView());

            // Render
            Render();
        }

    }

    void Game::Render()
    {
        window->clear(sf::Color(0, 0, 0, 255));
        shaderProgram.Bind();

        BatchHandler::getInstance().Reset();

        // Render all objects
        std::vector<Object*> objects = room->GetObjects();
        objects.reserve(objects.size() + globalObjects.size() + 1);
        objects.insert(objects.end(), globalObjects.begin(), globalObjects.end());
        objects.insert(objects.end(), player);
        std::sort(objects.begin(), objects.end(), [](const Object* x, const Object* y)
        {
            return x->depth < y->depth;
        });

        sf::View windowView = window->getView();
        for (int i = 0; i < objects.size(); i++)
        {
            if (std::find(UIObjects.begin(), UIObjects.end(), objects[i]) != UIObjects.end())
            {
                window->setView(window->getDefaultView());
                window->draw(*objects[i]);
                window->setView(windowView);
            }
            else
            {
                window->draw(*objects[i]);
            }
        }

        if (BatchHandler::getInstance().BatchExists()) BatchHandler::getInstance().DrawBatch();

        window->display();
    }

    Room* Game::GetRoomInternal()
    {
        return room;
    }

    Room* Game::GetRoomStatic()
    {
        return instance->GetRoomInternal();
    }

    bool Game::Start()
    {
        // Create & initialize main window
        window.Init(title, { 640, 480 }, sf::Style::Close | sf::Style::Titlebar , icon); // Standard
        //window.Init(title, { 640, 480 }, sf::Style::Fullscreen , icon); // Fullscreen test

        if (!window.GetWin())
        {
            GlobalLogger->Log(Logger::Error, "Failed to create main game window.");
            return false;
        }

        // Center window
        window.CenterWindow();

        // Initialize handlers
        collisionHandler.Reset();
        saveHandler.Reset();

        // Initialize room
        room->Initialize();

        player->Init();


        // Start update loop
        while (window->isOpen())
        {
            Update();
        }

        return true;
    }

    void Game::LoadRoomInternal(Room* room)
    {
        if (this->room == room) return;
        this->room = room;
        if (!this->room->IsInitialized())
        {
            room->Initialize();
        }
    }

    void Game::LoadRoomInternal(int roomId)
    {
        if (this->room == tempRoomList[roomId]) return;
        if (roomId == -1) return;
        this->room = tempRoomList[roomId];
        if (!this->room->IsInitialized())
        {
            room->Initialize();
        }
    }

    void Game::LoadRoom(int roomId)
    {
        instance->LoadRoomInternal(roomId);
    }

    void Game::LoadRoom(Room *room)
    {
        instance->LoadRoomInternal(room);
    }

    // Getters
    double Game::GetFPS()
    {
        return this->FPS;
    }

    std::string Game::GetTitle()
    {
        return title;
    }

    Room* Game::GetRoom()
    {
        return this->room;
    }

    Player* Game::GetPlayer()
    {
        return instance->player;
    }

    Game* Game::GetInstance()
    {
        return instance;
    }
}
