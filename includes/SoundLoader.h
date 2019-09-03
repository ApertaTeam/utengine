#ifndef UT_SOUNDLOADER_H
#define UT_SOUNDLOADER_H
#include <iostream>
#include <AL/al.h>

namespace UT
{
	class SoundLoader
	{
	public:
		static SoundLoader* GetInstance();

		ALuint LoadSoundFromPath(std::string path);
		inline ALuint GetSound() { return sound; };

	protected:
		ALuint sound;

	private:
		static SoundLoader* inst_;
		SoundLoader() : sound(0) {}
		SoundLoader(const SoundLoader&);
		SoundLoader& operator=(const SoundLoader&);
	};
}

#endif