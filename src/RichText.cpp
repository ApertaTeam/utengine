#include "RichText.h"
#include <iostream>
#include <sstream>
namespace UT
{
    RichText::RichText()
    {
        this->font = NULL;
        this->rawText = "";
        this->type = TextType::Normal;
        this->renderPosition = { 0, 0 };
    }

    void RichText::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();

        int x = renderPosition.x, y = renderPosition.y;
        bool cancelNext = false;
        sf::Color formatColor = sf::Color(255, 255, 255);

        for (int i = 0; i < rawText.size(); i++)
        {
            bool verifiedTag = false;

            switch (rawText.at(i))
            {
            case '\n':
                y += font->GetGlyph('A').texture.height + font->GetGlyph('A').offset;
                x = renderPosition.x;
                verifiedTag = true;
                break;

            case '\\':
                cancelNext = true;
                verifiedTag = true;
                break;

            case '[':
                if (!cancelNext)
                {
                    std::string temp = rawText.substr((size_t)i + 1, rawText.substr((size_t)i + 1).find_first_of(']'));
                    bool verifiedTag = false;


                    if (temp[0] == 'c')
                    {
                        std::stringstream ss;
                        int hexColor;

                        // Handles hexadecimal stuff
                        ss << std::hex << "0x" << std::stoul(temp.substr(temp.find_first_of(":") + 1), 0, 16);
                        ss >> hexColor;

                        formatColor = sf::Color(hexColor);
                        i += temp.length() + 1;
                    }

                    verifiedTag = true;
                }
                else
                {
                    cancelNext = false;
                }
                break;

            default:
                break;
            }

            if (verifiedTag)
            {
                continue;
            }

            auto glyph = font->GetGlyph(rawText.at(i));
            auto sprite = font->GetGlyphSprite(rawText.at(i));
            sprite.setPosition(x, y);
            sprite.SetColor(formatColor);
            x += glyph.shift;
            target.draw(sprite, states);
        }
    }
}