#include "SoundLoader.h"
#include <Logger.h>
#include <vector>

static std::vector<std::shared_ptr<sf::SoundBuffer>> sounds;
static std::vector<std::string> paths;

namespace UT
{
	std::shared_ptr<sf::SoundBuffer> SoundLoader::GetSoundById(int soundID)
	{
		if (soundID >= sounds.size())
			return nullptr;
		return sounds[soundID];
	}

	int SoundLoader::LoadSoundFromFile(const std::string& path)
	{
		int pos = std::distance(paths.begin(), std::find(paths.begin(), paths.end(), path));
		std::cout << pos << std::endl;
		if(pos < paths.size())
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

	void SoundLoader::ClearSounds()
	{
		for (int i = sounds.size() - 1; i >= 0; i--)
		{
			sounds[i].reset();
			sounds.erase(sounds.begin() + i);
		}

		paths.erase(paths.begin(), paths.end());
	}

}