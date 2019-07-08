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
        Focused = 131073 /* GLFW_FOCUSED's value */,
        Iconified,
        Resizable,
        Visible,
        Decorated,
        AutoIconify,
        Floating,
        Maximized,
        CenterCursor,
        TransparentFramebuffer,
        Hovered,
        FocusOnShow
    };

    // Handles a game window
    class Window
    {
    public:
        Window(std::string title = "C++ Undertale Engine", glm::vec2 size = glm::vec2(640, 480), std::vector<WindowFlags> flags = {}, Camera* camera = nullptr);
        ~Window();

        void CenterWindow();
        
        // Getters
        GLFWwindow* GetWin();
        std::string GetTitle();
        glm::vec2 GetSize();

        // Setters
        void SetTitle(std::string title);
        void SetSize(glm::vec2 size);
    private:
        GLFWwindow* win;
        std::string title;
        glm::vec2 size;
    };
}

#endif // UT_WINDOW_H