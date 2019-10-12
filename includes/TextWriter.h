#ifndef UT_TEXT_WRITER_H
#define UT_TEXT_WRITER_H

#include "Font.h"
#include "RichText.h"

namespace UT
{
    class TextWriter : public sf::Drawable
    {
    public:
        TextWriter();
        TextWriter(Font* font);

        void Update();

        inline void SetFont(Font* font) { this->font = font; };
        inline Font* GetFont() { return font; };

        inline void SetRawText(std::string rawText) { this->rawText = rawText; };
        inline std::string GetRawText() { return rawText; };

    private:
        Font* font;
        RichText richText;

        std::string rawText;
        int position;
        short timeout;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}

#endif