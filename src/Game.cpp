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
            for (int i = 0; i < this->objects.size(); i++)
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
        window->clear();
        shaderProgram.Bind();

        BatchHandler::getInstance().Reset();

        // Render all objects
        for (int i = 0; i < this->objects.size(); i++)
        {
            window->draw(*objects[i]);
        }

        if (BatchHandler::getInstance().BatchExists()) BatchHandler::getInstance().DrawBatch();
        
        window->display();
    }

    void Game::Refresh()
    {
        // Sort game objects in order of depth
        std::sort(objects.begin(), objects.end(), [](const Object* x, const Object* y)
            {
                return x->GetDepth() < y->GetDepth();
            });
    }

    void Game::RefreshDepth()
    {
        instance->Refresh();
    }

    std::vector<Object*>& Game::GetObjectsInternal()
    {
        return objects;
    }

    std::vector<Object*>& Game::GetObjects()
    {
        return instance->GetObjectsInternal();
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

        for (auto& object : objects)
        {
            object->Init();
        }

        RefreshDepth();

        while (window->isOpen())
        {
            Update();
        }

        return true;
    }

    void Game::LoadRoom(Room* room) 
    {
        this->room = room;

        objects = room->objects;
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