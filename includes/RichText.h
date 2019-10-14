#ifndef UT_RICH_TEXT_H
#define UT_RICH_TEXT_H

#include <string>
#include "Font.h"

namespace UT
{
    enum TextType
    {
        Normal = 0,
        Wavy = 1,
        Shaky = 2,
    };

    class RichText : public sf::Drawable, sf::Transformable
    {
    public:
        RichText();

        void Update(float delta);

        const Font* GetFont() const { return this->font; }
        void SetFont(Font* font) { this->font = font; }

        inline void SetRenderPosition(Vector2 renderPosition) { this->renderPosition = renderPosition; };
        inline Vector2 GetRenderPosition() { return renderPosition; };

        inline void SetMonospacing(short monospacing) { this->monospacing = monospacing; };
        inline short GetMonospacing() { return monospacing; };

        inline void SetTextTypeFlags(char textTypeFlags) { this->textTypeFlags = textTypeFlags; };
        inline char GetTextTypeFlags() { return textTypeFlags; };

        std::string rawText;

    private:
        Font* font;
        Vector2 renderPosition;

        char textTypeFlags;
        Vector2 renderOffset;

        float wavyAngle = 0;

        short monospacing;
        std::map<std::string, int32_t> colorPresets;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}
#endif