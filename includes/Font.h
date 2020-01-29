#ifndef UT_FONT_H
#define UT_FONT_H

#include <Sprite.h>
#include <unordered_map>

namespace UT
{
    struct Glyph
    {
        wchar_t character;
        sf::IntRect texture;
        int shift; // Probably used for the horizontal offset to the next glyph relative to the starting x of the current glyph
        int offset;

        Glyph() : character(' '), texture({}), shift(0), offset(0) {};
        Glyph(wchar_t character, sf::IntRect texture, int shift, int offset)
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
        Font(int texId, std::unordered_map<char, Glyph> glyphs);

        bool HasGlyph(char character) const { return glyphs.find(character) != glyphs.end(); }
        Glyph GetGlyph(char character) const { return glyphs.at(character); }
        Sprite GetGlyphSprite(char character);
        Sprite GetGlyphAsColor(char character, sf::Color color);

        inline void SetTexId(int texId) { this->texId = texId; }
        inline void SetGlyphs(std::unordered_map<char, Glyph> glyphs) { this->glyphs = glyphs; }
        inline void AddGlyph(char character, Glyph glyph) { this->glyphs.insert(std::pair<char, Glyph>(character, glyph)); }
    private:
        int texId;
        std::unordered_map<char, Glyph> glyphs; // Not an std::vector due to not having a 0-indexed range
    };
}

#endif