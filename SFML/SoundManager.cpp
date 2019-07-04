#include "stdafx.h"
#include "SoundManager.h"


SoundManager::SoundManager()
{
	
	if (soundBuffers["clic"].loadFromFile("Data/Sound/clic.wav") == -1)
	{
		cout << "ERROR **** load sound fail" << endl;
	}

	sounds["clic"] = sf::Sound(soundBuffers["clic"]);
	sounds["clic"].setVolume(25.f);
}

SoundManager::~SoundManager()
{
	soundBuffers.clear();
	sounds.clear();
}

sf::Sound SoundManager::getSound(string name)
{
	return sounds[name];
}

void SoundManager::playSound(string name)
{
	sounds[name].play();
}
