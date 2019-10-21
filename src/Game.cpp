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
    Game::Game(std::string title, unsigned int FPS, sf::Image icon)
    {
        this->title = title;
        this->icon = icon;

        this->FPS = FPS;
        this->FPStimeObj = sf::Clock();

        this->room = nullptr;
        this->camera = nullptr;
    }

    Game::~Game()
    {
        TextureHandler::ClearTextures();
    }

    void Game::Update()
    {
        camera->Update();

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
            if (delta > 1.0 / ((double)FPS - 10))
            {
                delta = 1.0 / ((double)FPS - 10);
            }


            // Run main update method for all objects
            for (int i = 0; i < this->objects.size(); i++)
            {
                objects[i]->Update(delta);
            }

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