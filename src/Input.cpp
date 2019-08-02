#include "Input.h"


namespace UT
{
    InputHandler::InputHandler()
    {
        
    }

    bool InputHandler::Pressed(InputActions input)
    {
        return false;
    }

    bool InputHandler::Held(InputActions input)
    {
        return false;
    }

    bool InputHandler::Released(InputActions input)
    {
        return false;
    }

    void InputHandler::Set(InputActions action, std::vector<int> keys)
    {
        
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