#ifndef UT_WINDOW_H
#define UT_WINDOW_H

#include "Common.h"
#include "Camera.h"

#include <string>
#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>

namespace UT
{    
    enum WindowFlags
    {
        Focused = 0x00020001 /* GLFW_FOCUSED's value */,
        Resizable = 0x00020003,
        Visible = 0x00020004,
        Decorated = 0x00020005,
        AutoIconify = 0x00020006,
        Floating = 0x00020007,
        Maximized = 0x00020008,
        CenterCursor = 0x00020009,
        TransparentFramebuffer = 0x0002000A,
        FocusOnShow = 0x0002000C
    };

    // Handles a game window
    class Window
    {
    public:
        Window();
        ~Window();

        void Init(std::string title = "Undertale", Vector2 size = { 640, 480 }, int style = sf::Style::Default);
        void CenterWindow();

        // Wrappers to RenderWindow
        inline bool PollEvent(sf::Event& event) { return this->win.pollEvent(event); }
        inline void Close() { this->win.close(); }
        inline bool IsOpen() { this->win.isOpen(); }
        
        // Getters
        sf::RenderWindow& GetWin();
        std::string GetTitle();
        Vector2 GetSize();

        // Setters
        void SetTitle(std::string title);
        void SetSize(Vector2 size);
    private:
        sf::RenderWindow win;
        std::string title;
        Vector2 size;
    };
}

#endif // UT_WINDOW_H