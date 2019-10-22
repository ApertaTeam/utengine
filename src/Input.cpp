#include "Input.h"


namespace UT
{
    InputHandler::InputHandler()
    {
        
    }

    bool InputHandler::Pressed(InputActions input)
    {
		if (sf::Joystick::isConnected(0)) {
			if (keyStates.find(input) == keyStates.end()) {
				keyStates[input] = sf::Joystick::isButtonPressed(0, keyboardAliases.at(input));
			}
			else {
				keyStates.insert(std::pair<InputActions, bool>(input, sf::Joystick::isButtonPressed(0, keyboardAliases.at(input))));
			}
		}
		else {
			if (keyStates.find(input) == keyStates.end()) {
				keyStates[input] = sf::Keyboard::isKeyPressed(keyboardAliases.at(input));
			}
			else {
				keyStates.insert(std::pair<InputActions, bool>(input, sf::Keyboard::isKeyPressed(keyboardAliases.at(input))));
			}
		}

		return keyStates.at(input);
    }

    bool InputHandler::Held(InputActions input)
    {
		return false;
    }

    bool InputHandler::Released(InputActions input)
    {
		return false;
    }

    void InputHandler::Set(InputActions action, sf::Keyboard::Key key)
    {
		if (keyboardAliases.find(action) == keyboardAliases.end()) {
			keyboardAliases[action] = key;
		}
		else {
			keyboardAliases.insert(std::pair<InputActions, sf::Keyboard::Key>(action, key));
		}
    }
}