#ifndef UT_INPUT_H
#define UT_INPUT_H

#include <string>
#include <map>
#include <vector>

struct GLFWwindow;

namespace UT
{
    enum InputActions
    {
        Confirm,
        Back,
        Menu,
        Exit
    };

    class InputHandler
    {
    public:
        InputHandler();

        bool Pressed(InputActions input);
        bool Held(InputActions input);
        bool Released(InputActions input);

        void Set(InputActions action, std::vector<int> keys);
        
        void HandleInput(GLFWwindow* window, int key, int scancode, int action, int mods);
    private:
        std::map<InputActions, std::vector<int>> keyboardAliases;
        std::map<InputActions, std::vector<int>> gamepadAliases;
        std::map<InputActions, int> keyStates;
    };
}

#endif