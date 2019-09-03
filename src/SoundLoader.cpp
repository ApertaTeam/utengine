#include "SoundLoader.h"

namespace UT
{
	SoundLoader* SoundLoader::inst_ = NULL;

	SoundLoader* SoundLoader::GetInstance()
	{
		if(inst_ == NULL) 
		{
			inst_ = new SoundLoader();
		}
		return inst_ ;
	}

	ALuint SoundLoader::LoadSoundFromPath(std::string path)
	{


		return 0;
	}

}