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

    int AssetHandler::LoadFontFromFile(const std::string& texturePath, const std::string& path)
    {
        std::map<char, Glyph> glyphs;
        BinaryFileReader bfr = BinaryFileReader(path);

        // Read length
        uint8_t len = bfr.ReadUInt8();

        for (int i = 0; i < len; i++)
        {
            // Read data
            uint8_t character = bfr.ReadUInt8();
            uint16_t x = bfr.ReadUInt16();
            uint16_t y = bfr.ReadUInt16();
            uint16_t w = bfr.ReadUInt16();
            uint16_t h = bfr.ReadUInt16();
            uint8_t shift = bfr.ReadUInt8();
            uint8_t offset = bfr.ReadUInt8();

            // Add glyph
            Glyph glyph;
            glyph.character = character;
            glyph.offset = offset;
            glyph.shift = shift;
            glyph.texture = sf::IntRect(x, y, w, h);
            
            glyphs.insert(std::pair<char, Glyph>(character, glyph));
        }

        std::shared_ptr<Font> font = std::make_shared<Font>();
        font->SetGlyphs(glyphs);
        font->SetTexId(AssetHandler::LoadTextureFromFile(texturePath));

        fonts.push_back(font);
        
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