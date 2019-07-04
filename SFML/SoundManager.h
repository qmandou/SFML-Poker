#ifndef SOUNDMANAGER__H
#define SOUNDMANAGER__H

class SoundManager
{

public:
	SoundManager();
	~SoundManager();

	sf::Sound getSound(string name);

	void playSound(string name);

private:
	map <string, sf::SoundBuffer> soundBuffers;
	map <string, sf::Sound> sounds;
};



#endif // !SOUNDMANAGER__H
