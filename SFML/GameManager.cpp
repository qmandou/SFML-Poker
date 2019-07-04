#include "stdafx.h"
#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow* window, SpriteManager* _spriteManager, SoundManager* _soundManager)
	: p_window(window), spriteManager(_spriteManager), soundManager(_soundManager)
{
	isLoop = true;
	m_UIFont.loadFromFile("Font/AdobeArabic-Regular.otf");
	m_UIText = sf::Text("test", m_UIFont);
	clock = new Clock();

	sf::Texture* buttonTexture = spriteManager->getTexture("button");

	antMore = new UIButton(sf::FloatRect(350.f, 360.f, 50.f, 50.f), sf::Color::White, sf::Color::Green, "+", buttonTexture);
	antLess = new UIButton(sf::FloatRect(225.f, 360.f, 50.f, 50.f), sf::Color::White, sf::Color::Green, "-", buttonTexture);

	pay = new UIButton(sf::FloatRect(425.f, 360.f, 80.f, 50.f), sf::Color::White, sf::Color::Green, "Pay", buttonTexture);
	next = new UIButton(sf::FloatRect(425.f, 360.f, 80.f, 50.f), sf::Color::White, sf::Color::Green, "Next", buttonTexture);
	quit = new UIButton(sf::FloatRect(525.f, 360.f, 80.f, 50.f), sf::Color::White, sf::Color::Green, "Quit", buttonTexture);


	player = Hand(sf::Vector2f(25, 200.f), spriteManager);
	banque = Hand(sf::Vector2f(25.f, 0.f), spriteManager);
	//otherPlayer = Hand(sf::Vector2f(25.f, 100.f), spriteManager);

	InitCardData();
}

GameManager::~GameManager()
{
	cout << "Game Manager START Destroy" << endl;
	 

	for (unsigned int i = 0; i < v_UI.size(); i++)
		delete v_UI[i];

	delete clock;

	cout << "Game Manager END Destroy" << endl;
}

int GameManager::GameLoop()
{
	isLoop = true;
	argentPlayer = 1000;
	//argentOtherPlayer = 1000;
	antPlayer = 0;
	//antOtherPlayer = 0;

	state = STATE_ANT;
	Ant();

	while (isLoop)
	{
		UpdateLoop();
		EventLoop();

		p_window->clear();

		sf::Sprite bg = spriteManager->getSprite("background");
		bg.setPosition(sf::Vector2f(0.f, 0.f));
		p_window->draw(bg);


		TextInfo();

		if(state == STATE_ANT)
		{
			m_UIText.setCharacterSize(30);
			m_UIText.setString(to_string(antPlayer));
			m_UIText.setPosition(sf::Vector2f(290.f, 360.f));
			p_window->draw(m_UIText);
		}

		if (state == STATE_MISE)
		{
			m_UIText.setCharacterSize(30);
			m_UIText.setString("Ant : " + to_string(antPlayer));
			m_UIText.setPosition(sf::Vector2f(200.f, 360.f));
			p_window->draw(m_UIText);
		}

		// Display UI
		for (unsigned int i = 0; i < v_UI.size(); i++)
		{
			v_UI[i]->Draw(*p_window);
			v_UI[i]->Write(*p_window, m_UIText);
		}

		// Display Card
		if (state == STATE_MISE || state == STATE_END)
		{
			banque.Draw(p_window);
			player.Draw(p_window);
		}
		//otherPlayer.Draw(p_window);

		// Display top info

		p_window->display();
	}

	return 1;
}

void GameManager::EventLoop()
{
	while (p_window->pollEvent(m_event))
	{
		for (unsigned int i = 0; i < v_UI.size(); i++)
			v_UI[i]->Event(m_event);

		if (m_event.type == sf::Event::Closed)
		{
			p_window->close();
			isLoop = false;
		}

		if (m_event.key.code == sf::Keyboard::Space &&
			m_event.type == m_event.KeyPressed)
		{

		}

	}
}

void GameManager::UpdateLoop()
{
	for (unsigned int i = 0; i < v_UI.size(); i++)
	{
		v_UI[i]->Update(m_event, *p_window);
	}

	if (quit->isSelected())
	{
		soundManager->playSound("clic");
		isLoop = false;
	}

	if (state == STATE_ANT)
	{
		if (antMore->isSelected() &&
			antPlayer * 2 <= argentPlayer &&
			antPlayer <= MAX_ANT)
		{
			antPlayer++;
		}

		if (antLess->isSelected())
		{
			antPlayer--;
		}

		if (pay->isSelected() && antPlayer > 0 && timer + 0.25f <= sf::Time(clock->getElapsedTime()).asSeconds())
		{
			state = STATE_MISE;
			banque.HideHand();
			Mise();
		}
	}

	if (state == STATE_MISE)
	{
		int banqueScore = banque.Score();

		if (pay->isSelected() && banqueScore != -1)
		{
			state = STATE_END;
			banque.DiscoverHand();
			antPlayer *= 2;
			End();
		}

		if (next->isSelected() && timer + 0.25f <= sf::Time(clock->getElapsedTime()).asSeconds())
		{
			state = STATE_ANT;
			if (banqueScore != -1)
			{
				argentPlayer -= antPlayer;
			}

			Ant();
		}
	}

	if (state == STATE_END)
	{
		if (next->isSelected() && timer + 0.25f <= sf::Time(clock->getElapsedTime()).asSeconds())
		{
			state = STATE_ANT;
			Ant();
		}
	}

	/*if (next->isSelected() && timer + 1.f <= sf::Time(clock->getElapsedTime()).asSeconds())
	{
		GameUpdate();
	}*/
}

void GameManager::TextInfo()
{
	m_UIText.setCharacterSize(30);
	m_UIText.setString("Crédit : " + to_string(argentPlayer));
	m_UIText.setPosition(sf::Vector2f(25.f, 360.f));
	p_window->draw(m_UIText);

	m_UIText.setCharacterSize(40);
	m_UIText.setString(textInfo);
	m_UIText.setPosition(sf::Vector2f(200.f, 145.f));
	p_window->draw(m_UIText);
}

void GameManager::InitCardData()
{
	for (int i = 0; i < CARD_NBR; i++)
	{
		aCardData[i].series = (char)(i / CARD_BY_SERIES);
		aCardData[i].type = (char)(i % CARD_BY_SERIES); 
	}
}

void GameManager::Ant()
{
	timer = sf::Time(clock->getElapsedTime()).asSeconds();
	v_UI.clear();
	textInfo = "Choisissez une ant";
	pay->SetPosition(sf::Vector2f(425.f, 360.f));
	v_UI.push_back(antMore);
	v_UI.push_back(antLess);
	v_UI.push_back(pay);
	v_UI.push_back(quit);
}

void GameManager::Mise()
{
	timer = sf::Time(clock->getElapsedTime()).asSeconds();
	v_UI.clear();
	ShuffleDeck();
	Distribute();

	if (banque.Score() == -1)
	{
		textInfo = "La banque passe...";
		banque.DiscoverHand();
		v_UI.push_back(next);
	}
	else
	{
		textInfo = "Miser ou passer";
		pay->SetPosition(sf::Vector2f(325.f, 360.f));
		v_UI.push_back(pay);
		v_UI.push_back(next);
		v_UI.push_back(quit);
	}
}

void GameManager::End()
{
	timer = sf::Time(clock->getElapsedTime()).asSeconds();
	v_UI.clear();
	int playerScore = player.Score();
	int banqueScore = banque.Score();

	if (playerScore > banqueScore)
	{
		textInfo = "Vous Gagnez : " + to_string(antPlayer * playerScore);
		argentPlayer += antPlayer * playerScore;
	}
	else
	{
		textInfo = "Vous Perdez : " + to_string(antPlayer);
		argentPlayer -= antPlayer;
	}

	pay->SetPosition(sf::Vector2f(325.f, 360.f));
	v_UI.push_back(next);
	v_UI.push_back(quit);
}
//
//void GameManager::AfterAnt()
//{
//	timer = sf::Time(clock->getElapsedTime()).asSeconds();
//
//	system("cls");
//	cout << "banque : " << banque.Score() << endl;
//	//cout << "other : " << otherPlayer.Score() << endl;
//	cout << "player : " << player.Score() << endl;
//}

void GameManager::ShuffleDeck()
{
	random_shuffle(&aCardData[0], &aCardData[CARD_NBR - 1]);
}

void GameManager::Distribute()
{
	CardData _otherPlayer[5];
	CardData _player[5];
	CardData _banque[5];
	int count = 0;

	for (int i = 0; i < 15; i += 3)
	{
		_otherPlayer[count] = aCardData[i];
		_player[count] = aCardData[i+1];
		_banque[count] = aCardData[i+2];
		count++;
	}

	player.SetCardData(_player);
	banque.SetCardData(_banque);
//	otherPlayer.SetCardData(_otherPlayer);
}

/*
	Basic Loop

void GameManager::GameLoop()
{
	while (p_window->isOpen())
	{
		EventLoop();

		p_window->clear();

		p_window->display();
	}
}

void GameManager::EventLoop()
{
	while (p_window->pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
			p_window->close();
	}
}

*/