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
        void RawDataCheck();

        inline void SetFont(Font* font) { this->font = font; };
        inline Font* GetFont() { return font; };

        inline void SetRawText(std::string rawText) { this->rawText = rawText; };
        inline std::string GetRawText() { return rawText; };

        inline void SetRenderPosition(Vector2 renderPosition) { this->renderPosition = renderPosition; richText.SetRenderPosition(renderPosition); };
        inline Vector2 GetRenderPosition() { return renderPosition; };

        inline void SetTextPosition(int textPosition) { this->textPosition = textPosition; };
        inline int GetTextPosition() { return textPosition; };

    private:
        Font* font;
        RichText richText;
        
        Vector2 renderPosition;

        std::string rawText;
        int textPosition;
        short timeout;

        bool cancelNext;
        int textSpeed = 1;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}

#endif