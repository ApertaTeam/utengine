#ifndef UT_RICH_TEXT_H
#define UT_RICH_TEXT_H

#include <string>
#include "Font.h"

namespace UT
{
    enum TextType
    {
        Normal,
        Wavy,
        Shakey,
        WavyShake
    };

    class RichText : sf::Drawable, sf::Transformable
    {
    public:
        RichText();

        const Font const* GetFont() const { return this->font; }
        void SetFont(Font* font) { this->font = font; }

        std::string rawText;
        TextType type;
    private:
        Font* font;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}

#endif