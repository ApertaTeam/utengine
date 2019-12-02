#ifndef UT_RICH_TEXT_H
#define UT_RICH_TEXT_H

#include <string>
#include "Font.h"

namespace UT
{
    enum class TextType : unsigned char
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
    

        Font* font;
        std::string rawText;
        sf::Vector2f renderPosition;
        short monospacing;

        char textTypeFlags;

    private:
        sf::Vector2f renderOffset;

        float wavyAngle = 0;

        std::map<std::string, int32_t> colorPresets;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}
#endif