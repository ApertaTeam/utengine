#ifndef UT_INPUT_H
#define UT_INPUT_H

#include "Window.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>

#include <string>
#include <map>
#include <array>

namespace UT
{
    enum InputActions {
        Confirm,
        Back,
        Menu,
        Skip,
        Exit,
        Up,
        Down,
        Left,
        Right
    };

    enum InputState
    {
        None,
        Pressed,
        Held,
        Released
    };

    class InputHandler
    {
        friend class Game;
    public:
        static bool IsInputPressed(InputActions input);
        static bool IsInputHeld(InputActions input);
        static bool IsInputReleased(InputActions input);

        static void Set(InputActions action, sf::Keyboard::Key key, bool alt = false);
        static void Set(InputActions action, unsigned int button, bool alt = false);

        void Update();

    private:
        InputHandler();

        std::map<InputActions, std::array<sf::Keyboard::Key, 2>> keyboardAliases;
        std::map<InputActions, std::array<unsigned int, 2>> gamepadAliases;
        std::map<InputActions, InputState> keyStates;
    };
}

#endif