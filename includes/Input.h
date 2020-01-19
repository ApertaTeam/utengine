#ifndef UT_INPUT_H
#define UT_INPUT_H

#include "Window.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Event.hpp>

#include <string>
#include <unordered_map>
#include <functional>
#include <map>
#include <array>
#include <vector>

#define LSAXIS_NEGX 101
#define LSAXIS_NEGY 102
#define LSAXIS_POSX 111
#define LSAXIS_POSY 112
#define RSAXIS_NEGX 201
#define RSAXIS_NEGY 202
#define RSAXIS_POSX 211
#define RSAXIS_POSY 212

namespace UT
{
    enum class InputActions {
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

    enum class InputState
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

        static void Reset(InputActions action, bool clear = false);
        static void Reset(bool clear = false);

        static void RegisterCallback(InputState state, std::function<void(sf::Event::KeyEvent)> func);

        void Update(sf::Event event, bool focused);

    private:
        InputHandler();

        std::unordered_map<InputActions, std::array<sf::Keyboard::Key, 2>> keyboardAliases;
        std::unordered_map<InputActions, std::array<unsigned int, 2>> gamepadAliases;
        std::map<InputActions, InputState> keyStates;
        std::map<InputState, std::vector<std::function<void(sf::Event::KeyEvent)>>> callbacks;
    };
}

#endif
