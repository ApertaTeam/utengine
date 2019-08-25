#ifndef UT_TEXTURE_HANDLER_H
#define UT_TEXTURE_HANDLER_H

#include <SFML/Graphics/Texture.hpp>
#include <memory>

namespace UT
{
    class TextureHandler
    {
    public:
        static std::shared_ptr<sf::Texture> GetTextureById(int texID);
        static int LoadTextureFromFile(const std::string& path);
        static int LoadTextureFromMemory(const void* data, size_t size);
        static void ClearTextures();
    };
}

#endif