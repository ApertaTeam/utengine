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

        void Update(float delta);
        void RawDataCheck();

        inline void SetFont(Font* font) { this->font = font; richText.font = font; }
        inline Font* GetFont() { return font;  }

        inline RichText* GetRichText() { return &richText; };
        
        inline void SetRenderPosition(sf::Vector2f renderPosition) { this->renderPosition = renderPosition; richText.renderPosition = renderPosition; };
        inline sf::Vector2f GetRenderPosition() { return renderPosition; }


        std::string rawText;
        int textPosition;
        float timeout;

    private:
        Font* font;
        RichText richText;
        
        sf::Vector2f renderPosition;


        bool cancelNext;
        int textSpeed = 1;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}

#endif