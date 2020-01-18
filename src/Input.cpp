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
            { InputActions::Exit, {sf::Keyboard::Escape, sf::Keyboard::Escape} },
            { InputActions::Up, {sf::Keyboard::W, sf::Keyboard::Up} },
            { InputActions::Left, {sf::Keyboard::A, sf::Keyboard::Left} },
            { InputActions::Right, {sf::Keyboard::D, sf::Keyboard::Right} },
            { InputActions::Down, {sf::Keyboard::S, sf::Keyboard::Down} }
        };

        gamepadAliases = {
            { InputActions::Confirm, {1,1} },
            { InputActions::Back, {2,2} },
            { InputActions::Menu, {4,9} },
            { InputActions::Skip, {3,2} },
            { InputActions::Exit, {10,10} },
            { InputActions::Up, {LSAXIS_NEGY,12} },
            { InputActions::Down, {LSAXIS_POSY,13} },
            { InputActions::Left, {LSAXIS_NEGX,14} },
            { InputActions::Right, {LSAXIS_POSX,15} }
        };

        _instance = this;
    }

    void InputHandler::Update(bool focused)
    {
        if (focused) return;

        std::map<InputActions, bool> actionHandled =
        {
            {InputActions::Confirm, false},
            {InputActions::Back, false},
            {InputActions::Menu, false},
            {InputActions::Skip, false},
            {InputActions::Exit, false},
            {InputActions::Up, false},
            {InputActions::Down, false},
            {InputActions::Left, false},
            {InputActions::Right, false}
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
                bool alias1 = false, alias2 = false;
                if (gamepadAlias.second[0] >= LSAXIS_NEGX)
                {
                    switch (gamepadAlias.second[0])
                    {
                    case LSAXIS_NEGX:
                        alias1 = sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -10;
                        break;
                    case LSAXIS_POSX:
                        alias1 = sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 10;
                        break;
                    case LSAXIS_NEGY:
                        alias1 = sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -10;
                        break;
                    case LSAXIS_POSY:
                        alias1 = sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 10;
                        break;
                    case RSAXIS_NEGX:
                        alias1 = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < -10;
                        break;
                    case RSAXIS_POSX:
                        alias1 = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) > 10;
                        break;
                    case RSAXIS_NEGY:
                        alias1 = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < -10;
                        break;
                    case RSAXIS_POSY:
                        alias1 = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) > 10;
                        break;
                    }
                }
                else
                {
                    alias1 = sf::Joystick::isButtonPressed(0, gamepadAlias.second[0]);
                }

                if (gamepadAlias.second[1] >= LSAXIS_NEGX)
                {
                    switch (gamepadAlias.second[1])
                    {
                    case LSAXIS_NEGX:
                        alias2 = sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -10;
                        break;
                    case LSAXIS_POSX:
                        alias2 = sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 10;
                        break;
                    case LSAXIS_NEGY:
                        alias2 = sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -10;
                        break;
                    case LSAXIS_POSY:
                        alias2 = sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 10;
                        break;
                    case RSAXIS_NEGX:
                        alias2 = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < -10;
                        break;
                    case RSAXIS_POSX:
                        alias2 = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) > 10;
                        break;
                    case RSAXIS_NEGY:
                        alias2 = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < -10;
                        break;
                    case RSAXIS_POSY:
                        alias2 = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) > 10;
                        break;
                    }
                }
                else
                {
                    alias2 = sf::Joystick::isButtonPressed(0, gamepadAlias.second[0]);
                }
                
                if (alias1 || alias2)
                {
                    if (keyStates[gamepadAlias.first] != InputState::Pressed && keyStates[gamepadAlias.first] != InputState::Held)
                    {
                        keyStates[gamepadAlias.first] = InputState::Pressed;
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

    bool InputHandler::IsInputPressed(InputActions input)
    {
        if (_instance->keyStates[input] == InputState::Pressed)
        {
            _instance->keyStates[input] = InputState::Held;
            return true;
        }
        return false;
    }

    bool InputHandler::IsInputHeld(InputActions input)
    {
        return _instance->keyStates[input] == InputState::Pressed || _instance->keyStates[input] == InputState::Held;
    }

    bool InputHandler::IsInputReleased(InputActions input)
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

    void InputHandler::Reset(InputActions action, bool clear)
    {
        if (_instance->keyStates[action] == InputState::Held && !clear)
        {
            _instance->keyStates[action] = InputState::Pressed;
        }
        else if (clear)
        {
            _instance->keyStates[action] = InputState::None;
        }
    }

    void InputHandler::Reset(bool clear)
    {
        for (auto const& [key, val] : _instance->keyStates)
        {
            Reset(key);
        }
    }
}