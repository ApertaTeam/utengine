#include "TextureHandler.h"

#include <map>
#include <memory>

static std::map<int, std::shared_ptr<sf::Texture>> textures;
static int idOff = 0;

namespace UT
{
    sf::Texture* TextureHandler::GetTextureById(int texID)
    {
        if (textures.find(texID) == textures.end()) return nullptr;
        return textures[texID].get();
    }

    int TextureHandler::LoadTextureFromFile(const std::string& path)
    {
        std::shared_ptr<sf::Texture> texture;
        if (!texture->loadFromFile(path))
        {
            texture.reset();
            return -1;
        }
        textures[idOff] = texture;
        return idOff++;
    }

    int TextureHandler::LoadTextureFromMemory(const void* data, size_t size)
    {
        std::shared_ptr<sf::Texture> texture;
        if (!texture->loadFromMemory(data, size))
        {
            texture.reset();
            return -1;
        }
        textures[idOff] = texture;
        return idOff++;
    }

    void TextureHandler::ClearTextures()
    {
        for (int i = textures.size() - 1; i <= 0; i--)
        {
            textures[i].reset();
            textures.erase(i);
        }
        idOff = 0;
    }
}