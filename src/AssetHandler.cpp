#include "AssetHandler.h"
#include "BinaryReader.h"

#include <vector>

static std::vector<std::shared_ptr<sf::Texture>> textures;
static std::vector<std::shared_ptr<sf::SoundBuffer>> sounds;
static std::vector<std::shared_ptr<UT::Font>> fonts;
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

    // Font handling
    std::shared_ptr<Font> AssetHandler::GetFontById(int fontID)
    {
        if (fontID >= fonts.size())
            return nullptr;
        return fonts[fontID];
    }

    int AssetHandler::LoadFontFromMemory(const void* data, size_t size)
    {


        return 0;
    }

    int AssetHandler::LoadFontFromFile(const std::string& path)
    {
        std::vector<Font> fonts;
        std::ifstream fs;
        fs.open(path, std::ios::binary);

        // Read length
        uint8_t len = 0;
        fs.read(reinterpret_cast<char*>(&len), sizeof(len));

        for (int i = 0; i < len; i++)
        {
            // Read data
            uint8_t character;
            fs.read(reinterpret_cast<char*>(&character), sizeof(character));

            uint16_t x;
            fs.read(reinterpret_cast<char*>(&x), sizeof(x));

            uint16_t y;
            fs.read(reinterpret_cast<char*>(&y), sizeof(y));

            uint16_t w;
            fs.read(reinterpret_cast<char*>(&w), sizeof(w));

            uint16_t h;
            fs.read(reinterpret_cast<char*>(&h), sizeof(h));

            uint8_t shift;
            fs.read(reinterpret_cast<char*>(&shift), sizeof(shift));

            uint8_t offset;
            fs.read(reinterpret_cast<char*>(&offset), sizeof(offset));

            
            // Reverse
            if (BinaryReader::IsBigEndian())
            {
                BinaryReader::ReverseUInt16(&x);
                BinaryReader::ReverseUInt16(&y);
                BinaryReader::ReverseUInt16(&w);
                BinaryReader::ReverseUInt16(&h);
            }

            // Debug output
            std::cout << "Character: " << character << ", X: " << (int)x << ", Y: " << (int)y << ", Width: " << (int)w << ", Height: " << (int)h << ", Shift: " << (int)shift << ", Offset: " << (int)offset << std::endl;

            
        }

        
        return fonts.size() - 1;
    }

    void AssetHandler::ClearFonts()
    {
        for (int i = fonts.size() - 1; i >= 0; i--)
        {
            fonts[i].reset();
            fonts.erase(fonts.begin() + i);
        }
    }
}