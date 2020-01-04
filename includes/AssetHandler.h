#ifndef UT_ASSET_HANDLER_H
#define UT_ASSET_HANDLER_H

#include "Logger.h"
#include "Font.h"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio.hpp>
#include <memory>

namespace UT
{
    class AssetHandler
    {
    public:
        // Texture handling
        static std::shared_ptr<sf::Texture> GetTextureById(int texID);
        static int LoadTextureFromFile(const std::string& path);
        static int LoadTextureFromMemory(const void* data, size_t size);
        static void ClearTextures();

        // Sound handling
        static std::shared_ptr<sf::SoundBuffer> GetSoundById(int soundID);
        static int LoadSoundFromFile(const std::string& path);
        static void ClearSounds();

        // Font handling
        static std::shared_ptr<Font> GetFontById(int fontID);
        static int LoadFontFromMemory(const void* data, size_t size);
        static int LoadFontFromFile(const std::string& path);
        static void ClearFonts();
    };
}
#endif