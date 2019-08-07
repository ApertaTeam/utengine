#ifndef UT_SPRITE_H
#define UT_SPRITE_H
#include <SFML/Graphics.hpp>

#include "Common.h"
#include "Object.h"
#include "Texture.h"

namespace UT
{
    // A type of object which has a sprite.
    class Sprite : public Object
    {
    public:
        Sprite();

        virtual void Render() override;

        // Getters
        TextureEntry GetFrame(int idx);
        Transform GetTransform();
		sf::Sprite GetSprite();
		sf::Texture GetTexture();

        // Setters
        void SetFrame(int idx, TextureEntry entry);
        void SetTransform(Transform transform);
		void SetSprite(sf::Sprite sprite);
		void SetTexture(sf::Texture texture);

    protected:
		sf::Sprite sprite;
        std::vector<TextureEntry> frames;
        sf::Texture texture; // TODO: work with texture pages

        uint32_t id;

        Vector2 origin;
        Vector4 mask;
        Transform transform;
        int depth;
        bool isStatic;
    };
}

#endif