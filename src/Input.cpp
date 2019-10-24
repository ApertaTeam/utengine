#include "Input.h"

static UT::InputHandler* _instance;
namespace UT
{
    InputHandler::InputHandler()
    {
        keyboardAliases = {
            { InputActions::Confirm, {sf::Keyboard::Z, sf::Keyboard::Enter} },
            { InputActions::Back, {sf::Keyboard::X, sf::Keyboard::LShift} },
            { InputActions::Menu, {sf::Keyboard::C, sf::Keyboard::LControl} },
            { InputActions::Skip, {sf::Keyboard::X, sf::Keyboard::LShift} },
            { InputActions::Exit, {sf::Keyboard::Escape, sf::Keyboard::Escape} }
        };

        gamepadAliases = {
            { InputActions::Confirm, {1,1} },
            { InputActions::Back, {2,2} },
            { InputActions::Menu, {4,9} },
            { InputActions::Skip, {3,2} },
            { InputActions::Exit, {10,10} }
        };

        _instance = this;
    }

    void InputHandler::Update()
    {
        std::map<InputActions, bool> actionHandled =
        {
            {InputActions::Confirm, false},
            {InputActions::Back, false},
            {InputActions::Menu, false},
            {InputActions::Skip, false},
            {InputActions::Exit, false}
        };
        
        for (auto &&keyAlias : keyboardAliases)
        {
            if (actionHandled[keyAlias.first]) continue;
            if (sf::Keyboard::isKeyPressed(keyAlias.second[0]) || sf::Keyboard::isKeyPressed(keyAlias.second[1]))
            {
                if (keyStates[keyAlias.first] != InputState::Pressed && keyStates[keyAlias.first] != InputState::Held)
                {
                    keyStates[keyAlias.first] = InputState::Pressed;
                }
                else
                {
                    keyStates[keyAlias.first] = InputState::Held;
                }
                actionHandled[keyAlias.first] = true;
            }
            else
            {
                if (keyStates[keyAlias.first] == InputState::Released)
                {
                    keyStates[keyAlias.first] = InputState::None;
                }
                else
                {
                    keyStates[keyAlias.first] = InputState::Released;
                }
                actionHandled[keyAlias.first] = true;
            }
        }

        if (sf::Joystick::isConnected(0))
        {
            for (auto &&gamepadAlias : gamepadAliases)
            {
                if (actionHandled[gamepadAlias.first]) continue;
                if (sf::Joystick::isButtonPressed(0, gamepadAlias.second[0]) || sf::Joystick::isButtonPressed(0, gamepadAlias.second[1]))
                {
                    if (keyStates[gamepadAlias.first] != InputState::Pressed && keyStates[gamepadAlias.first] != InputState::Held)
                    {
                        keyStates[gamepadAlias.first] = InputState::Pressed;
                    }
                    else
                    {
                        keyStates[gamepadAlias.first] = InputState::Held;
                    }
                    actionHandled[gamepadAlias.first] = true;
                }
                else
                {
                    if (keyStates[gamepadAlias.first] == InputState::Released)
                    {
                        keyStates[gamepadAlias.first] = InputState::None;
                    }
                    else
                    {
                        keyStates[gamepadAlias.first] = InputState::Released;
                    }
                    actionHandled[gamepadAlias.first] = true;
                }
            }
        }
    }

    bool InputHandler::Pressed(InputActions input)
    {
        return _instance->keyStates[input] == InputState::Pressed;
    }

    bool InputHandler::Held(InputActions input)
    {
        return _instance->keyStates[input] == InputState::Pressed || _instance->keyStates[input] == InputState::Held;
    }

    bool InputHandler::Released(InputActions input)
    {
        return _instance->keyStates[input] == InputState::Released;
    }

    void InputHandler::Set(InputActions action, sf::Keyboard::Key key, bool alt)
    {
        if (alt)
        {
            _instance->keyboardAliases[action][1] = key;

        }
        else
        {
            _instance->keyboardAliases[action][0] = key;
        }
    }

    void InputHandler::Set(InputActions action, unsigned int button, bool alt)
    {
        if (alt)
        {
            _instance->gamepadAliases[action][1] = button;
        }
        else
        {
            _instance->gamepadAliases[action][0] = button;
        }
    }
}