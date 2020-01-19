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
        inputBox.MoveToRect(sf::FloatRect(8, 8, 300, 200), 1);
        outputBox.MoveToRect(sf::FloatRect(320, 8, 630, 200), 1);

        instance = this;
    }

    void Terminal::Init()
    {
        
    }

    void Terminal::Update(float delta)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde))
        {
            isVisible = !isVisible;
        }

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