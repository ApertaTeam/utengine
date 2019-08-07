#include "Window.h"

#include "Logger.h"

namespace UT
{
    Window::Window()
    {
        this->title = "";
        this->size = Vector2(0, 0);
    }

    void Window::Init(std::string title, Vector2 size, int flags, sf::Image icon)
    {        
        this->title = title;
        this->size = size;

        this->win = new sf::RenderWindow(sf::VideoMode(size.x, size.y), title, flags);

		if (icon.getSize().x != 0) {
			this->win->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
		}
    }

    Window::~Window()
    {
        if (this->win != NULL) delete this->win;
    }

    void Window::CenterWindow()
    {
        if (this->win == NULL) return;
        sf::Vector2u center{sf::VideoMode::getDesktopMode().width/2 - (this->win->getSize().x/2), sf::VideoMode::getDesktopMode().height/2 - (this->win->getSize().y/2)};
        this->win->setPosition((sf::Vector2i)center);
    }

    // Getters
    sf::RenderWindow* Window::GetWin()
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
        if (this->win != NULL) this->win->setTitle(title);
    }

    void Window::SetSize(Vector2 size)
    {
        this->size = size;
        if (this->win != NULL) this->win->setSize({(unsigned int)size.x, (unsigned int)size.y});
    }
}