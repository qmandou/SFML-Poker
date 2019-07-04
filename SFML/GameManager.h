
#ifndef GAMEMANAGER__H
#define GAMEMANAGER__H

#include "SpriteManager.h"
#include "SoundManager.h"
#include "UIButton.h"
#include "Card.h"
#include "Hand.h"


/*
:: GAMEMANAGER
*/

#define MAX_ANT 1000

#define STATE_ANT 0
#define STATE_MISE 1
#define STATE_END 2

class GameManager
{

public:
	GameManager(sf::RenderWindow* window, SpriteManager* _spriteManager, SoundManager* _soundManager);
	virtual ~GameManager();

	int GameLoop();
private:

	void EventLoop();
	void UpdateLoop();

	// Main Poker func
	void InitCardData();
	void Ant();
	void Mise();
	void End();
	void ShuffleDeck();
	void Distribute();
	void TextInfo();

	sf::RenderWindow* p_window;
	sf::Event m_event;

	sf::Font m_UIFont;
	sf::Text m_UIText;

	vector <UIGroupBox*> v_UI;
	UIButton* antMore;
	UIButton* antLess;
	UIButton* pay;
	UIButton* next;
	UIButton* quit;

	CardData aCardData[CARD_NBR];

	Hand banque;
	Hand player;
	//Hand otherPlayer;

	int argentPlayer;
	//int argentOtherPlayer;

	int antPlayer;
	//int antOtherPlayer;

	sf::Clock* clock;
	string textInfo;
	float timer;
	bool isLoop;

	int state;

	SpriteManager* spriteManager;
	SoundManager* soundManager;
protected:
};

#endif