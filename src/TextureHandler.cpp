#include "TextureHandler.h"

#include <vector>
#include <memory>

static std::vector<std::shared_ptr<sf::Texture>> textures;

namespace UT
{
    sf::Texture* TextureHandler::GetTextureById(int texID)
    {
        if (texID >= textures.size())
            return nullptr;
        return textures[texID].get();
    }

    int TextureHandler::LoadTextureFromFile(const std::string& path)
    {
        std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
        if (!texture->loadFromFile(path))
        {
            texture.reset();
            return -1;
        }
        textures.push_back(std::move(texture));
        return textures.size() - 1;
    }

    int TextureHandler::LoadTextureFromMemory(const void* data, size_t size)
    {
        std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
        if (!texture->loadFromMemory(data, size))
        {
            texture.reset();
            return -1;
        }
        textures.push_back(std::move(texture));
        return textures.size() - 1;
    }

    void TextureHandler::ClearTextures()
    {
        for (int i = textures.size() - 1; i <= 0; i--)
        {
            textures[i].reset();
            textures.erase(textures.begin() + i);
        }
    }
}