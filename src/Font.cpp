#include "Font.h"

namespace UT
{
    Font::Font(int texId, std::map<char, Glyph> glyphs)
    {
        this->texId = texId;
        this->glyphs = glyphs;
    }

    Sprite Font::GetGlyphSprite(char character)
    {
        return Sprite(this->texId, glyphs[character].texture);
    }

    Sprite Font::GetGlyphAsColor(char character, sf::Color color)
    {
        Sprite sprite{this->texId, glyphs[character].texture};
        sprite.SetColor(color);
        return sprite;
    }
}