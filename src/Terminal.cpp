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

        inputText.renderPosition = { 16, 420 };
        inputText.font = &*AssetHandler::GetFontById(AssetHandler::LoadFontFromFile("font.png", "font.dat"));
        inputText.rawText = "";


        instance = this;
        
        InputHandler::RegisterCallback(InputState::Pressed, [&](sf::Event::KeyEvent keyEvent)
            {
                std::cout << keyEvent.code << ":" << (char)(keyEvent.code + 65) << std::endl;
                if (keyEvent.code < 26)
                {
                    if (keyEvent.shift) inputText.rawText += (char)(keyEvent.code + 65);
                    else inputText.rawText += (char)(keyEvent.code + 97);
                }
                else
                {
                    switch (keyEvent.code)
                    {
                    case 26:
                        if (keyEvent.shift) inputText.rawText += '=';
                        else if (keyEvent.alt) inputText.rawText += '}';
                        else inputText.rawText += '0';
                        break;
                    case 27: inputText.rawText += '1'; break;
                    case 28: inputText.rawText += '2'; break;
                    case 29: inputText.rawText += '3'; break;
                    case 30: inputText.rawText += '4'; break;
                    case 31: inputText.rawText += '5'; break;
                    case 32: inputText.rawText += '6'; break;
                    case 33:
                        if (keyEvent.alt) inputText.rawText += '{';
                        else inputText.rawText += '7';
                        break;
                    case 34:
                        if (keyEvent.shift) inputText.rawText += '(';
                        else inputText.rawText += '8';
                        break;
                    case 35:
                        if (keyEvent.shift) inputText.rawText += ')';
                        else inputText.rawText += '9';
                        break;
                    case 49:
                        if (keyEvent.shift) inputText.rawText += ';';
                        else inputText.rawText += ',';
                        break;
                    case 50:
                        if (keyEvent.shift) inputText.rawText += ':';
                        else inputText.rawText += '.';
                        break;
                    case 52:
                        inputText.rawText += '\'';
                        break;
                    case 56:
                        if(keyEvent.shift) inputText.rawText += '_';
                        else inputText.rawText += '-';
                        break;
                    case 57: inputText.rawText += ' '; break;
                    case 59:
                        if(inputText.rawText.length() > 0) inputText.rawText = inputText.rawText.substr(0, inputText.rawText.length() - 1);
                        break;
                    case 67: inputText.rawText += '+'; break;
                    case 68: inputText.rawText += '-'; break;
                    }
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

        target.draw(inputText);
        target.draw(outputText);
    }
}