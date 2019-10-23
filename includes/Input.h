#ifndef UT_INPUT_H
#define UT_INPUT_H

#include "Window.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>

#include <string>
#include <map>
#include <vector>

namespace UT
{
    enum InputActions {
        Confirm,
        Back,
        Menu,
        Skip,
        Exit
    };

    class InputHandler
    {
    public:
        InputHandler();

        bool Pressed(InputActions input);
        bool Held(InputActions input);
        bool Released(InputActions input);

        void Set(InputActions action, sf::Keyboard::Key key);
        void Set(InputActions action, unsigned int button);

    private:
        std::map<InputActions, sf::Keyboard::Key> keyboardAliases;
        std::map<InputActions, unsigned int> gamepadAliases;
        std::map<InputActions, bool> keyStates;
    };
}

#endif