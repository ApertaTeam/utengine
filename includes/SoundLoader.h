#ifndef UT_SOUNDLOADER_H
#define UT_SOUNDLOADER_H

#include <memory>
#include <SFML/Audio.hpp>

namespace UT
{
	class SoundLoader
	{
	public:
		static std::shared_ptr<sf::SoundBuffer> GetSoundById(int soundID);
		static int LoadSoundFromFile(const std::string& path);
		static void ClearSounds();
	};
}

#endif