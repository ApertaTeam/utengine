#include "Game.h"

#include <algorithm>

#include "Resources.h"
#include "Logger.h"

#include <SFML/Graphics.hpp>

namespace UT
{
    Game::Game(std::string title, unsigned int FPS)
    {
        this->title = title;
        this->FPS = 1.0 / FPS;
        this->lastFPSTime = 0;

        this->room = nullptr;
        this->camera = nullptr;
    }

    Game::~Game()
    {
    }

    void Game::Update()
    {
        camera->Update();

        double FPSTime = 0; /* TODO */
        double deltaFPSTime = FPSTime - lastFPSTime;

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape) window->close();
            }
        }

        if (/*deltaFPSTime > FPS*/true)
        {
            lastFPSTime = FPSTime;

            // Sort objects by depth
            std::sort(objects.begin(), objects.end(), [](Object* obj1, Object* obj2)
                {
                    return (obj1->GetRenderType() > obj2->GetRenderType());
                });

            // Run main update method for all objects
            for (int i = 0; i < this->objects.size(); i++)
            {
                objects[i]->Update();
            }

            // Render
            Render();
        }
    }

    void Game::Render()
    {
        window->clear();
        shaderProgram.Bind();


        // Render all objects
        for (int i = 0; i < this->objects.size(); i++)
        {
            objects[i]->Render();
        }
        
        window->display();
    }

    bool Game::Start()
    {
        // Create & initialize main window
        window.Init(title, { 640, 480 }, sf::Style::Close | sf::Style::Titlebar );
        
        /*if (window.GetWin() == NULL)
        {
            GlobalLogger->Log(Logger::Error, "Failed to create main game window.");
            return false;
        }*/

        // Center window
        window.CenterWindow();

        // Initialize FPS variables
        lastFPSTime = 0.0;

        while (window->isOpen())
        {
            Update();
        }

        return true;
    }

    void Game::AddObject(Object* object)
    {
        objects.push_back(object);
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

    void Game::SetRoom(Room* room)
    {
        this->room = room;
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