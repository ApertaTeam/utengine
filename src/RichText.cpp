#include "RichText.h"

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

        for (int i = 0; i < rawText.size(); i++)
        {
            // For now we'll just draw everything
            if (rawText.at(i) == '\n')
            {
                y += font->GetGlyph('A').texture.height + font->GetGlyph('A').offset;
                x = renderPosition.x;
                continue;
            }

            auto glyph = font->GetGlyph(rawText.at(i));
            auto sprite = font->GetGlyphSprite(rawText.at(i));
            sprite.setPosition(x, y);
            x += glyph.shift;
            target.draw(sprite, states);
        }
    }
}