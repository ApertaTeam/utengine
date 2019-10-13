#ifndef UT_RICH_TEXT_H
#define UT_RICH_TEXT_H

#include <string>
#include "Font.h"

namespace UT
{
    class RichText : public sf::Drawable, sf::Transformable
    {
    public:
        enum class TextType
        {
            Normal,
            Wavy,
            Shakey,
            WavyShake
        };

        RichText();

        const Font* GetFont() const { return this->font; }
        void SetFont(Font* font) { this->font = font; }

        inline void SetRenderPosition(Vector2 renderPosition) { this->renderPosition = renderPosition; };
        inline Vector2 GetRenderPosition() { return renderPosition; };

        std::string rawText;
        TextType type;

    private:
        Font* font;
        Vector2 renderPosition;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}
#endif