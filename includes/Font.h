#ifndef UT_FONT_H
#define UT_FONT_H

#include <Sprite.h>
#include <map>

namespace UT
{
    struct Glyph
    {
        char character;
        sf::IntRect texture;
        int shift; // Not sure what this is used for
        int offset;
    };

    class Font
    {
    public:
        Font(int texId, std::map<char, Glyph> glyphs);

        Glyph GetGlyph(char character) const { return glyphs.at(character); }
        Sprite GetGlyphSprite(char character);
        Sprite GetGlyphAsColor(char character, sf::Color color);
    private:
        int texId;
        std::map<char, Glyph> glyphs; // Not an std::vector due to not having a 0-indexed range
    };
}

#endif