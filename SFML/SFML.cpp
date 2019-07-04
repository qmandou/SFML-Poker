
#include "stdafx.h"
#include "SpriteManager.h"
#include "SoundManager.h"
#include "GameManager.h"
#include "MenuManager.h"

#define STATE_END 0
#define STATE_MENU 1
#define STATE_GAME 2

int main()
{
	srand((unsigned)time(NULL));
	sf::RenderWindow window(sf::VideoMode(600, 400), "PokerCaraibes");

	SpriteManager* spriteManager = new SpriteManager();
	SoundManager* soundManager = new SoundManager();

	GameManager *game = new GameManager(&window, spriteManager, soundManager);
	MenuManager *menu = new MenuManager(&window, spriteManager, soundManager);


	int freqStart = 1;

	char state = STATE_MENU;

	while(window.isOpen())
	{
		switch (state)
		{
			case STATE_MENU:
				state = menu->MenuLoop();
				break;
			case STATE_GAME:
				state = game->GameLoop();
				break;
			case STATE_END:
				window.close();
				break;
			default:
				cout << "**** APP STATE ERROR ****" << endl;
		}
	}


	delete menu;
	delete game;

	delete spriteManager;
	delete soundManager;

	return 0;
}

