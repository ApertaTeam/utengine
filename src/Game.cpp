#include "Game.h"

#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Resources.h"
#include "Logger.h"


namespace UT
{
    Game::Game(std::string title, unsigned int FPS)
    {
        this->shaderProgram = 0;

        this->title = title;
        this->FPS = 1.0 / FPS;
        this->lastFPSTime = 0;

        this->room = nullptr;
        this->camera = nullptr;
    }

    Game::~Game()
    {
        glfwTerminate();

        if (shaderProgram != 0) glDeleteProgram(shaderProgram);
    }

    void Game::Update()
    {
        camera->Update();

        double FPSTime = glfwGetTime();
        double deltaFPSTime = FPSTime - lastFPSTime;

        if (deltaFPSTime > FPS)
        {
            lastFPSTime = FPSTime;

            Render();
        }

        glfwPollEvents();
    }

    void Game::Render()
    {
        // Clear screen
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glUseProgram(shaderProgram);

        // Update uniforms
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "ProjectionMatrix"), 1, GL_FALSE, glm::value_ptr(camera->GetProjectionMatrix()));

        glUniform1i(glGetUniformLocation(shaderProgram, "texture0"), 0);

        // Move, rotate and scale (Model Matrix)
        modelMatrix = glm::mat4(1.0f);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(0));
        modelMatrix = glm::rotate(modelMatrix, glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        modelMatrix = glm::rotate(modelMatrix, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        modelMatrix = glm::rotate(modelMatrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(1.0f));

        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "ModelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix));


        // Render all objects
        /*for (int i = 0; i < this->objects.size(); i++)
        {
            objects[i]->Render();
        }*/
        
        // Show rendered buffer
        glfwSwapBuffers(window.GetWin());
        glFlush();

        glActiveTexture(0);
        glBindVertexArray(0);
        glUseProgram(0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    bool Game::Init()
    {
        // GLFW initialization
        if (!glfwInit())
        {
            GlobalLogger->Log(Logger::Error, "Failed to initialize GLFW");
            return false;
        }

        // OpenGL version
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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
            glfwTerminate();
            GlobalLogger->Log(Logger::Error, "Failed to create main game window.");
            return false;
        }

        // Center window
        window.CenterWindow();

        // GLEW initialization
        glewExperimental = GL_TRUE;

        if (glewInit() != GLEW_OK)
        {
            glfwTerminate();
            GlobalLogger->Log(Logger::Error, "Failed to initialize GLEW.");
            return false;
        }

        // Setup shader program
        shaderProgram = glCreateProgram();
        GLuint shaderVertexPlain = Resources::LoadShader(GetExecutableDirectory() + "/assets/shaders/shaderVertexPlain.glsl", GL_VERTEX_SHADER);
        GLuint shaderFragmentPlain = Resources::LoadShader(GetExecutableDirectory() + "/assets/shaders/shaderFragmentPlain.glsl", GL_FRAGMENT_SHADER);
        Resources::LinkProgram(shaderProgram, shaderVertexPlain, shaderFragmentPlain);

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
        modelMatrix = glm::mat4(1.0f);
        modelMatrix = glm::translate(modelMatrix, position);
        modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        modelMatrix = glm::scale(modelMatrix, scale);

        // View matrix
        glm::vec3 worldUp(0.0f, 1.0f, 0.0f);
        glm::vec3 camPosition(0.0f, 0.0f, 1.0f);
        glm::vec3 camFront(0.0f, 0.0f, -1.0f);
        glm::mat4 ViewMatrix(1.0f);
        ViewMatrix = glm::lookAt(camPosition, camPosition + camFront, worldUp);

        // Send matrices
        glUseProgram(shaderProgram);

        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "ModelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "ViewMatrix"), 1, GL_FALSE, glm::value_ptr(ViewMatrix));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "ProjectionMatrix"), 1, GL_FALSE, glm::value_ptr(camera->GetProjectionMatrix()));

        glUseProgram(0);

        // Initialize FPS variables
        lastFPSTime = 0.0;

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

    GLuint Game::GetShaderProgram()
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

    void Game::SetShaderProgram(GLuint shaderProgram)
    {
        this->shaderProgram = shaderProgram;
    }
}