#ifndef MENUMANAGER__H
#define MENUMANAGER__H

#include "UIButton.h"
#include "SpriteManager.h"
#include "SoundManager.h"

class MenuManager
{

public:
	MenuManager(sf::RenderWindow* window, SpriteManager* _spriteManager, SoundManager* _soundManager);
	~MenuManager();

	int MenuLoop();
private:
	void UpdateLoop();
	void EventLoop();

	sf::RenderWindow* p_window;
	sf::Event m_event;

	sf::Font m_UIFont;
	sf::Text m_UIText;

	vector <UIGroupBox*> v_UI;
	UIButton* play;
	UIButton* quit;
	bool isLoop;
	int state;


	SpriteManager* spriteManager;
	SoundManager* soundManager;
};


#endif // !MENUMANAGER__H
