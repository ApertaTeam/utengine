#include "Game.h"

#include <algorithm>

#include "Resources.h"
#include "Logger.h"


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

        if (deltaFPSTime > FPS)
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
        shaderProgram.Bind();


        // Render all objects
        for (int i = 0; i < this->objects.size(); i++)
        {
            objects[i]->Render();
        }
    }

    bool Game::Start()
    {
        

        // Create & initialize main window
        window = Window();
        window.Init(title, { 640, 480 }, {
            WindowFlags::Visible,
            WindowFlags::Decorated,
            WindowFlags::Focused,
            WindowFlags::FocusOnShow
            });
        
        if (window.GetWin() == NULL)
        {
            GlobalLogger->Log(Logger::Error, "Failed to create main game window.");
            return false;
        }

        // Center window
        window.CenterWindow();

        // Initialize FPS variables
        lastFPSTime = 0.0;

        while (true /* TODO */)
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