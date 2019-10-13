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

        this->colorPresets = std::map<std::string, int32_t>();
        colorPresets.insert(std::pair<std::string, int32_t>("Yellow", 0xFFFF00));
        colorPresets.insert(std::pair<std::string, int32_t>("Black", 0x000000));
        colorPresets.insert(std::pair<std::string, int32_t>("White", 0xFFFFFF));
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
                    std::string tempData = temp.substr(temp.find_first_of(":") + 1);
                    bool verifiedTag = false;


                    if (temp[0] == 'c')
                    {
                        if (colorPresets.count(tempData))
                        {
                            formatColor = sf::Color(colorPresets.at(tempData));
                        }
                        else
                        {
                            int32_t hexColor = std::stoul((tempData.length() < 8) ? tempData + "FF" : tempData, 0, 16);

                            formatColor = sf::Color(hexColor);
                        }
                    }
                    else if (temp[0] == '/')
                    {
                        if (temp[1] == 'c')
                        {
                            formatColor = sf::Color(255, 255, 255);
                        }
                    }

                    i += temp.length() + 2;
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

            if(i < rawText.length()) {
                auto glyph = font->GetGlyph(rawText.at(i));
                auto sprite = font->GetGlyphSprite(rawText.at(i));
                sprite.setPosition(x, y);
                sprite.SetColor(formatColor);
                x += glyph.shift;
                target.draw(sprite, states);
            }
        }
    }
}