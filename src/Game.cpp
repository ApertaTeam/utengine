#include "Game.h"

#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace UT
{
    Game::Game(Window* window, unsigned int FPS)
    {
        this->window = window;
        this->shaderProgram = 0;

        this->FPS = FPS;
        this->FPSTime = 0;
        this->lastFPSTime = 0;
        this->deltaFPSTime = 0;
    }

    Game::~Game()
    {
        glfwTerminate();
        glDeleteProgram(shaderProgram);
    }

    void Game::Update()
    {
        glfwPollEvents();

        FPSTime = glfwGetTime();
        deltaFPSTime = FPSTime - lastFPSTime;

        if (deltaFPSTime > FPS)
        {
            lastFPSTime = FPSTime;
            Render();
        }
    }

    void Game::Render()
    {
        // Clear screen
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glUseProgram(shaderProgram);

        // Render all objects
        for (int i = 0; i < this->objects.size(); i++)
        {
            objects[i]->Render();
        }

        // Show rendered buffer
        glfwSwapBuffers(window->GetWin());
        glFlush();

        glActiveTexture(0);
        glBindVertexArray(0);
        glUseProgram(0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void Game::Init()
    {
        // OpenGL properties
        glEnable(GL_DEPTH_TEST);

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glFrontFace(GL_CW);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        // All matrices
        glm::vec3 position(0.0f);
        glm::vec3 rotation(0.0f);
        glm::vec3 scale(1.0f);

        // Model matrix
        glm::mat4 ModelMatrix(1.0f);
        ModelMatrix = glm::translate(ModelMatrix, position);
        ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        ModelMatrix = glm::scale(ModelMatrix, scale);

        // View matrix
        glm::vec3 worldUp(0.0f, 1.0f, 0.0f);
        glm::vec3 camPosition(0.0f, 0.0f, 1.0f);
        glm::vec3 camFront(0.0f, 0.0f, -1.0f);
        glm::mat4 ViewMatrix(1.0f);
        ViewMatrix = glm::lookAt(camPosition, camPosition + camFront, worldUp);

        // Send matrices
        glUseProgram(shaderProgram);

        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "ModelMatrix"), 1, GL_FALSE, glm::value_ptr(ModelMatrix));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "ViewMatrix"), 1, GL_FALSE, glm::value_ptr(ViewMatrix));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "ProjectionMatrix"), 1, GL_FALSE, glm::value_ptr(window->GetCamera()->GetProjectionMatrix()));

        glUseProgram(0);

        // Initialize FPS variables
        FPSTime = glfwGetTime();
        deltaFPSTime = 0.0;
        lastFPSTime = 0.0;
    }

    void Game::AddObject(Object* object)
    {
        objects.push_back(object);
    }

    // Getters
    Window* Game::GetWindow()
    {
        return this->window;
    }

    unsigned int Game::GetFPS()
    {
        return this->FPS;
    }

    // Setters
    void Game::SetWindow(Window* window)
    {
        this->window = window;
    }
}