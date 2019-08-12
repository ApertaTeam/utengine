#ifndef UT_SPRITE_H
#define UT_SPRITE_H
#include <SFML/Graphics.hpp>

#include "Common.h"
#include "Object.h"
#include "Texture.h"

namespace UT
{
    class Sprite : public sf::Drawable, public sf::Transformable
    {
    public:
        Sprite();
        Sprite(int texId, sf::IntRect texRect);

        inline int GetTexture() const { return textureId; }
        inline void SetTexture(int texId) { textureId = texId; }

        inline sf::IntRect GetTextureRect() const { return textureRect; }
        inline void SetTextureRect(sf::IntRect texRect) { textureRect = texRect; }
    private:
        int textureId;
        sf::IntRect textureRect;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}

#endif