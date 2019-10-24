#ifndef UT_INPUT_H
#define UT_INPUT_H

#include "Window.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>

#include <string>
#include <map>
#include <vector>
#include <array>

namespace UT
{
    enum InputActions {
        Confirm,
        Back,
        Menu,
        Skip,
        Exit
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
        static bool Pressed(InputActions input);
        static bool Held(InputActions input);
        static bool Released(InputActions input);

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