#include "Window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace UT
{
    Window::Window(std::string title, glm::vec2 size, std::vector<WindowFlags> flags)
        : title(title),
          size(size)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        for (int i = 0; i < flags.size(); i++)
        {
            glfwWindowHint(flags[i], GL_TRUE);
        }

        this->win = glfwCreateWindow(size.x, size.y, title.c_str(), NULL, NULL);
        glfwMakeContextCurrent(this->win);
        if (this->win == NULL)
        {
            glfwTerminate();
            throw "Failed to create GLFW window.";
        }
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

	glm::vec2 Window::GetSize()
	{
		return this->size;
	}

	// Setters
	void Window::SetTitle(std::string title)
	{
		this->title = title;
	}

	void Window::SetSize(glm::vec2 size)
	{
		this->size = size;
	}
}