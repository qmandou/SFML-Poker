#include "stdafx.h"
#include "MenuManager.h"


MenuManager::MenuManager(sf::RenderWindow* window, SpriteManager* _spriteManager, SoundManager* _soundManager)
	: p_window(window), spriteManager(_spriteManager), soundManager(_soundManager)
{
	m_UIFont.loadFromFile("Font/AdobeArabic-Regular.otf");
	m_UIText = sf::Text("test", m_UIFont);
	isLoop = true;
	sf::Texture* buttonTexture = spriteManager->getTexture("button");

	play = new UIButton(sf::FloatRect(250.f, 150.f, 100.f, 40.f), sf::Color::White, sf::Color::Green, "Play", buttonTexture);
	quit = new UIButton(sf::FloatRect(250.f, 300.f, 100.f, 40.f), sf::Color::White, sf::Color::Green, "Quit", buttonTexture);

	v_UI.push_back(play);
	v_UI.push_back(quit);
}

MenuManager::~MenuManager()
{

}

int MenuManager::MenuLoop()
{
	isLoop = true;
	state = 0;
	while (isLoop)
	{
		UpdateLoop();
		EventLoop();

		p_window->clear();

		m_UIText.setColor(sf::Color::White);
		m_UIText.setPosition(95.f, 0.f);
		m_UIText.setString("**Poker des Caraïbes**");
		m_UIText.setCharacterSize(60);
		p_window->draw(m_UIText);
		m_UIText.setCharacterSize(20);


		// Display UI
		for (unsigned int i = 0; i < v_UI.size(); i++)
		{
			v_UI[i]->Draw(*p_window);
			v_UI[i]->Write(*p_window, m_UIText);
		}

		p_window->display();
	}

	return state;
}

void MenuManager::EventLoop()
{
	while (p_window->pollEvent(m_event))
	{
		for (unsigned int i = 0; i < v_UI.size(); i++)
			v_UI[i]->Event(m_event);

		if (m_event.type == sf::Event::Closed || m_event.key.code == sf::Keyboard::Escape)
		{
			p_window->close();
			state = 0;
			isLoop = false;
		}

		if (quit->isSelected())
		{
			state = 0;
			isLoop = false;
		}

		if (play->isSelected())
		{
			soundManager->playSound("clic");
			state = 2;
			isLoop = false;
		}

		if (m_event.key.code == sf::Keyboard::Space &&
			m_event.type == m_event.KeyPressed)
		{
			isLoop = false;
			state = 2;
		}
	}
}


void MenuManager::UpdateLoop()
{
	for (unsigned int i = 0; i < v_UI.size(); i++)
	{
		v_UI[i]->Update(m_event, *p_window);
	}
}
