#include "Input.h"

#include <GLFW/glfw3.h>

namespace UT
{
    InputHandler::InputHandler()
    {
        // Set up some common aliases
        keyboardAliases =
        {
            {Confirm, {GLFW_KEY_Z, GLFW_KEY_ENTER}},
            {Back, {GLFW_KEY_X, GLFW_KEY_LEFT_SHIFT, GLFW_KEY_RIGHT_SHIFT}},
            {Menu, {GLFW_KEY_C, GLFW_KEY_LEFT_CONTROL, GLFW_KEY_RIGHT_CONTROL}},
            {Exit, {GLFW_KEY_ESCAPE}}
        };
        gamepadAliases =
        {
            {Confirm, {GLFW_GAMEPAD_BUTTON_CROSS}},
            {Back, {GLFW_GAMEPAD_BUTTON_CIRCLE}},
            {Menu, {GLFW_GAMEPAD_BUTTON_START, GLFW_GAMEPAD_BUTTON_TRIANGLE}},
            {Exit, {GLFW_GAMEPAD_BUTTON_BACK}}
        };
    }

    bool InputHandler::Pressed(InputActions input)
    {
        return keyStates[input] == GLFW_PRESS;
    }

    bool InputHandler::Held(InputActions input)
    {
        return keyStates[input] == GLFW_REPEAT;
    }

    bool InputHandler::Released(InputActions input)
    {
        return keyStates[input] == GLFW_RELEASE;
    }

    void InputHandler::Set(InputActions action, std::vector<int> keys)
    {
        std::vector<int> confirmedKeys = {};
        std::vector<int> confirmedButtons = {};
        for (int i = 0; i < keys.size(); i++)
        {
            int key = keys[i];
            if (key >= GLFW_GAMEPAD_BUTTON_A && key <= GLFW_GAMEPAD_BUTTON_DPAD_LEFT)
            {
                confirmedButtons.push_back(key);
                continue;
            }

            if (key < GLFW_KEY_SPACE) continue;
            if (key < GLFW_KEY_APOSTROPHE && key > GLFW_KEY_SPACE) continue;
            if (key < GLFW_KEY_COMMA && key > GLFW_KEY_APOSTROPHE) continue;
            if (key == 58) continue;
            if (key == 60) continue;
            if (key < GLFW_KEY_A && key > GLFW_KEY_EQUAL) continue;
            if (key < GLFW_KEY_GRAVE_ACCENT && key > GLFW_KEY_RIGHT_BRACKET) continue;
            if (key < GLFW_KEY_WORLD_1 && key > GLFW_KEY_GRAVE_ACCENT) continue;
            if (key < GLFW_KEY_ESCAPE && key > GLFW_KEY_WORLD_2) continue;
            if (key < GLFW_KEY_CAPS_LOCK && key > GLFW_KEY_END) continue;
            if (key < GLFW_KEY_F1 && key > GLFW_KEY_PAUSE) continue;
            if (key < GLFW_KEY_KP_0 && key > GLFW_KEY_F25) continue;
            if (key < GLFW_KEY_LEFT_SHIFT && key > GLFW_KEY_KP_EQUAL) continue;
            if (key > GLFW_KEY_MENU) continue;
            confirmedKeys.push_back(key);
        }

        if (confirmedKeys.size() > 0) keyboardAliases[action] = confirmedKeys;
        if (confirmedButtons.size() > 0) gamepadAliases[action] = confirmedButtons;
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