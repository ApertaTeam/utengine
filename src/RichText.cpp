#include "RichText.h"

namespace UT
{
    RichText::RichText()
    {
        this->font = NULL;
        this->rawText = "";
        this->type = TextType::Normal;
    }

    void RichText::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();

        int x = 0, y = 0;

        for (int i = 0; i < rawText.size(); i++)
        {
            // For now we'll just draw everything
            if (rawText.at(i) == '\n')
            {
                y += font->GetGlyph('A').texture.height + font->GetGlyph('A').offset;
                x = 0;
                continue;
            }

            auto glyph = font->GetGlyph(rawText.at(i));
            auto sprite = font->GetGlyphSprite(rawText.at(i));
            sprite.setPosition((x += glyph.shift), y);
            target.draw(sprite, states);
        }
    }
}