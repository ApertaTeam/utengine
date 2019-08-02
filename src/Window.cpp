#include "Window.h"

#include "Logger.h"

namespace UT
{
    Window::Window()
    {
        this->title = "";
        this->size = Vector2(0, 0);
    }

    void Window::Init(std::string title, Vector2 size, int flags)
    {        
        this->title = title;
        this->size = size;

        this->win.create(sf::VideoMode(size.x, size.y), title, flags);
        
        /*if (this->win == NULL)
        {
            GlobalLogger->Log(Logger::Error, "Failed to create GLFW window.");
        }*/
    }

    Window::~Window()
    {
        
    }

    void Window::CenterWindow()
    {
        Vector2 center{sf::VideoMode::getDesktopMode().width/2 - (this->win.getSize().x/2), sf::VideoMode::getDesktopMode().height/2 - (this->win.getSize().y/2)};
        this->win.setPosition({center.x, center.y});
    }

    // Getters
    sf::RenderWindow& Window::GetWin()
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
        this->win.setTitle(title);
    }

    void Window::SetSize(Vector2 size)
    {
        this->size = size;
        this->win.setSize({size.x, size.y});
    }
}