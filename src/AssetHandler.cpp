#include "AssetHandler.h"

#include <vector>

static std::vector<std::shared_ptr<sf::Texture>> textures;
static std::vector<std::shared_ptr<sf::SoundBuffer>> sounds;
static std::vector<std::string> paths;

namespace UT
{
    // Texture handling
    std::shared_ptr<sf::Texture> AssetHandler::GetTextureById(int texID)
    {
        if (texID >= textures.size())
            return nullptr;
        return textures[texID];
    }

    int AssetHandler::LoadTextureFromFile(const std::string& path)
    {
        std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
        if (!texture->loadFromFile(path))
        {
            texture.reset();
            return -1;
        }
        //textures.push_back(std::move(texture));
        textures.emplace_back(texture);
        return textures.size() - 1;
    }

    int AssetHandler::LoadTextureFromMemory(const void* data, size_t size)
    {
        std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
        if (!texture->loadFromMemory(data, size))
        {
            texture.reset();
            return -1;
        }
        textures.emplace_back(texture);
        return textures.size() - 1;
    }

    void AssetHandler::ClearTextures()
    {
        for (int i = textures.size() - 1; i >= 0; i--)
        {
            textures[i].reset();
            textures.erase(textures.begin() + i);
        }
    }

    // Sound handling
    std::shared_ptr<sf::SoundBuffer> AssetHandler::GetSoundById(int soundID)
    {
        if (soundID >= sounds.size())
            return nullptr;
        return sounds[soundID];
    }

    int AssetHandler::LoadSoundFromFile(const std::string& path)
    {
        int pos = std::distance(paths.begin(), std::find(paths.begin(), paths.end(), path));
        if (pos < paths.size())
        {
            return pos;
        }
        else
        {
            std::shared_ptr<sf::SoundBuffer> buffer = std::make_shared<sf::SoundBuffer>();
            if (!buffer->loadFromFile(path))
            {
                GlobalLogger->Log(Logger::Error, "Failed to load sound from path: '" + path + "'");
                buffer.reset();
                return -1;
            }

            sounds.emplace_back(buffer);
            paths.emplace_back(path);

            return sounds.size() - 1;
        }
    }

    void AssetHandler::ClearSounds()
    {
        for (int i = sounds.size() - 1; i >= 0; i--)
        {
            sounds[i].reset();
            sounds.erase(sounds.begin() + i);
        }

        paths.erase(paths.begin(), paths.end());
    }
}