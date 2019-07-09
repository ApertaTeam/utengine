#ifndef UT_WINDOW_H
#define UT_WINDOW_H

#include "Common.h"
#include "Camera.h"

#include <glm/vec2.hpp>
#include <string>
#include <vector>

struct GLFWwindow; // Forward declare

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

        void Init(std::string title = "Undertale", glm::ivec2 size = { 640, 480 }, std::vector<WindowFlags> flags = {});
        void CenterWindow();
        
        // Getters
        GLFWwindow* GetWin();
        std::string GetTitle();
        glm::ivec2 GetSize();

        // Setters
        void SetTitle(std::string title);
        void SetSize(glm::ivec2 size);
    private:
        GLFWwindow* win;
        std::string title;
        glm::ivec2 size;
    };
}

#endif // UT_WINDOW_H