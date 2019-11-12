#include "Game.h"

#include <algorithm>

#include "Resources.h"
#include "Logger.h"
#include "Sprite.h"
#include "TextureHandler.h"
#include "BatchHandler.h"

#include <SFML/Graphics.hpp>
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

        instance = this;
    }

    Game::~Game()
    {
        TextureHandler::ClearTextures();
    }

    void Game::Update()
    {
        inputHandler.Update();

        sf::Int32 FPStime = FPStimeObj.getElapsedTime().asMilliseconds();

        // Event polling
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape) window->close();
            }
            else if (event.type == sf::Event::Closed) {
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
            objects.reserve(room->GetInteractables().size() + objects.size() + room->GetTileMaps().size());
            objects.insert(objects.end(), room->GetInteractables().begin(), room->GetInteractables().end());
            objects.insert(objects.end(), room->GetTileMaps().begin(), room->GetTileMaps().end());
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
        objects.reserve(room->GetInteractables().size() + objects.size() + room->GetTileMaps().size());
        objects.insert(objects.end(), room->GetInteractables().begin(), room->GetInteractables().end());
        objects.insert(objects.end(), room->GetTileMaps().begin(), room->GetTileMaps().end());
        std::sort(objects.begin(), objects.end(), [](const Object* x, const Object* y)
        {
            return x->GetDepth() < y->GetDepth();
        });
        for (int i = 0; i < objects.size(); i++)
        {
            window->draw(*objects[i]);
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
        window.Init(title, { 640, 480 }, sf::Style::Close | sf::Style::Titlebar, icon);
        
        if (!window.GetWin())
        {
            GlobalLogger->Log(Logger::Error, "Failed to create main game window.");
            return false;
        }

        // Center window
        window.CenterWindow();

        room->Initialize();

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
    Window Game::GetWindow()
    {
        return this->window;
    }

    double Game::GetFPS()
    {
        return this->FPS;
    }

    Room* Game::GetRoom()
    {
        return this->room;
    }

    Camera* Game::GetCamera()
    {
        return this->camera;
    }

    Shader Game::GetShaderProgram()
    {
        return this->shaderProgram;
    }

    // Setters
    void Game::SetWindow(Window window)
    {
        this->window = window;
    }

    void Game::SetCamera(Camera* camera)
    {
        this->camera = camera;
    }

    void Game::SetShaderProgram(Shader shaderProgram)
    {
        this->shaderProgram = shaderProgram;
    }
}
