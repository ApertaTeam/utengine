#include "Input.h"

#include <GLFW/glfw3.h>

namespace UT
{
    InputHandler::InputHandler()
    {
        // Set up some common aliases
        keyboardAliases =
        {
            {"confirm", {GLFW_KEY_Z, GLFW_KEY_ENTER}},
            {"back", {GLFW_KEY_X, GLFW_KEY_LEFT_SHIFT, GLFW_KEY_RIGHT_SHIFT}},
            {"menu", {GLFW_KEY_C, GLFW_KEY_LEFT_CONTROL, GLFW_KEY_RIGHT_CONTROL}},
            {"exit", {GLFW_KEY_ESCAPE}}
        };
        gamepadAliases =
        {
            {"confirm", {GLFW_GAMEPAD_BUTTON_CROSS}},
            {"back", {GLFW_GAMEPAD_BUTTON_CIRCLE}},
            {"menu", {GLFW_GAMEPAD_BUTTON_START, GLFW_GAMEPAD_BUTTON_TRIANGLE}},
            {"exit", {GLFW_GAMEPAD_BUTTON_BACK}}
        };
    }

    bool InputHandler::Pressed(std::string input)
    {
        if (!(input == "confirm" || input == "back" || input == "menu" || input == "exit")) return false;

        return keyStates[input] == GLFW_PRESS;
    }

    bool InputHandler::Held(std::string input)
    {
        if (!(input == "confirm" || input == "back" || input == "menu" || input == "exit")) return false;

        return keyStates[input] == GLFW_REPEAT;
    }

    bool InputHandler::Released(std::string input)
    {
        if (!(input == "confirm" || input == "back" || input == "menu" || input == "exit")) return false;
        return keyStates[input] == GLFW_RELEASE;
    }

    void InputHandler::HandleInput(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        for (auto const &input : keyboardAliases)
        {
            for (int i = 0; i < input.second.size(); i++)
            {
                if (key == input.second[i])
                {
                    keyStates[input.first] = action;
                    break;
                }
            }
        }
        for (auto const &input : gamepadAliases)
        {
            for (int i = 0; i < input.second.size(); i++)
            {
                if (key == input.second[i])
                {
                    keyStates[input.first] = action;
                    break;
                }
            }
        }
    }
}