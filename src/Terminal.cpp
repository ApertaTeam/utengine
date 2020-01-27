#include "Terminal.h"
#include "Input.h"
#include "AssetHandler.h"

namespace UT
{
    static Terminal* instance;

    Terminal::Terminal()
    {
        this->inputBox = Rectangle9Slice();
        this->outputBox = Rectangle9Slice();
        this->isVisible = true;
        this->depth = 999999998;


        int terminalTexture = AssetHandler::LoadTextureFromFile("terminal.png");
        std::array<Sprite, 9> terminalSlices = {
            Sprite(terminalTexture, {0, 0, 25, 25}),
            Sprite(terminalTexture, {25, 0, 25, 25}),
            Sprite(terminalTexture, {50, 0, 25, 25}),

            Sprite(terminalTexture, {0, 25, 25, 25}),
            Sprite(terminalTexture, {25, 25, 25, 25}),
            Sprite(terminalTexture, {50, 25, 25, 25}),

            Sprite(terminalTexture, {0, 50, 25, 25}),
            Sprite(terminalTexture, {25, 50, 25, 25}),
            Sprite(terminalTexture, {50, 50, 25, 25}),
        };

        inputBox.slice = terminalSlices;
        outputBox.slice = terminalSlices;
        inputBox.MoveToRect(sf::FloatRect(8, 8, 640 - 8, 480 - 8), 1);
        outputBox.MoveToRect(sf::FloatRect(8, 480 - 8 - 60, 640 - 8, 480 - 8), 1);

        instance = this;

        InputHandler::RegisterCallback(InputState::Pressed, [&](sf::Event::KeyEvent keyEvent)
            {
                if (keyEvent.code < 24)
                {
                    std::cout << (char)(keyEvent.code + 65) << std::endl;
                }

                
                buttonsPressed.push_back(keyEvent.code);
            });
    }

    void Terminal::Init()
    {
        
    }

    void Terminal::Update(float delta)
    {
        if (std::find(buttonsPressed.begin(), buttonsPressed.end(), sf::Keyboard::Tilde) - buttonsPressed.begin() != buttonsPressed.end() - buttonsPressed.begin())
        {
            isVisible = !isVisible;
        }
        

        buttonsPressed.clear();

        if (!isVisible) return;
        inputBox.Update(delta);
        outputBox.Update(delta);
    }

    void Terminal::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if (!isVisible) return;

        target.draw(inputBox);
        target.draw(outputBox);
    }
}