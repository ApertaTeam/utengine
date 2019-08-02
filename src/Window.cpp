#include "Window.h"

#include "Logger.h"

namespace UT
{
    Window::Window()
    {
        this->title = "";
        this->win = NULL;
        this->size = Vector2(0, 0);
    }

    void Window::Init(std::string title, Vector2 size, std::vector<WindowFlags> flags)
    {        
        this->title = title;
        this->size = size;

        /* TODO */
        
        if (this->win == NULL)
        {
            GlobalLogger->Log(Logger::Error, "Failed to create GLFW window.");
        }
    }

    Window::~Window()
    {
        
    }

    void Window::CenterWindow()
    {
        
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

    Vector2 Window::GetSize()
    {
        return this->size;
    }

    // Setters
    void Window::SetTitle(std::string title)
    {
        this->title = title;
    }

    void Window::SetSize(Vector2 size)
    {
        this->size = size;
    }
}