#include "Window.h"

#include "Logger.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace UT
{
    Window::Window()
    {
        this->title = "";
        this->win = NULL;
        this->size = glm::ivec2(0, 0);
    }

    void Window::Init(std::string title, glm::ivec2 size, std::vector<WindowFlags> flags)
    {        
        this->title = title;
        this->size = size;

        // Clear all window flags
        for (int i = WindowFlags::Focused; i <= WindowFlags::FocusOnShow; i++)
        {
            if (i == 0x00020002 || i == 0x0002000B) continue;
            glfwWindowHint(i, GL_FALSE);
        }

        // Set inputted window flags
        for (int i = 0; i < flags.size(); i++)
        {
            glfwWindowHint(flags[i], GL_TRUE);
        }

        this->win = glfwCreateWindow(size.x, size.y, title.c_str(), NULL, NULL);
        glfwMakeContextCurrent(this->win);
        
        if (this->win == NULL)
        {
            GlobalLogger->Log(Logger::Error, "Failed to create GLFW window.");
        }
    }

    Window::~Window()
    {
        glfwDestroyWindow(win);
    }

    void Window::CenterWindow()
    {
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();

        if (!monitor)
        {
            return;
        }

        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        if (!mode)
        {
            return;
        }

        int monitorX, monitorY;
        glfwGetMonitorPos(monitor, &monitorX, &monitorY);

        int windowWidth, windowHeight;
        glfwGetWindowSize(this->win, &windowWidth, &windowHeight);

        glfwSetWindowPos(this->win, monitorX + (mode->width - windowWidth) / 2, monitorY + (mode->height - windowHeight) / 2);
    }

    // Getters
    GLFWwindow* Window::GetWin()
    {
        return this->win;
    }

    std::string Window::GetTitle()
    {
        return this->title;
    }

    glm::ivec2 Window::GetSize()
    {
        return this->size;
    }

    // Setters
    void Window::SetTitle(std::string title)
    {
        this->title = title;
        glfwSetWindowTitle(this->win, title.c_str());
    }

    void Window::SetSize(glm::ivec2 size)
    {
        this->size = size;
        glfwSetWindowSize(this->win, size.x, size.y);
    }
}