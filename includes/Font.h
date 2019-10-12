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
        int shift; // Probably used for the horizontal offset to the next glyph relative to the starting x of the current glyph
        int offset;

        Glyph() : character(' '), texture({}), shift(0), offset(0) {};
        Glyph(char character, sf::IntRect texture, int shift, int offset)
            : character(character),
            texture(texture),
            shift(shift),
            offset(offset)
        {};
    };

    class Font
    {
    public:
        Font();
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