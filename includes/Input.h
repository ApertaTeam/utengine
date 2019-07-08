#ifndef UT_INPUT_H
#define UT_INPUT_H

#include <string>
#include <map>
#include <vector>

struct GLFWwindow;

namespace UT
{
    class InputHandler
    {
    public:
        InputHandler();

        bool Pressed(std::string input);
        bool Held(std::string input);
        bool Released(std::string input);
        
        void HandleInput(GLFWwindow* window, int key, int scancode, int action, int mods);
    private:
        std::map<std::string, std::vector<int>> keyboardAliases;
        std::map<std::string, std::vector<int>> gamepadAliases;
        std::map<std::string, int> keyStates;
    };
}

#endif