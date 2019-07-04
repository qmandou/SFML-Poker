#include "stdafx.h"
#include "SpriteManager.h"


SpriteManager::SpriteManager()
{
	sf::Texture background;
	background.loadFromFile("Data/Sprite/background.png");

	textures["background"] = background;

	sf::Texture button;
	button.loadFromFile("Data/Sprite/button.png");
	textures["button"] = button;

	sf::Texture cardDeck;
	cardDeck.loadFromFile("Data/Sprite/CardDeckV2.png");
	textures["CardDeck"] = cardDeck;
}


SpriteManager::~SpriteManager()
{
	textures.clear();
}

sf::Sprite SpriteManager::getSprite(string name)
{
	sf::Sprite sprite;
	sprite.setTexture(textures[name]);
	return sprite;
}

sf::Sprite SpriteManager::getTileSprite(string name, int wtile, int htile, int x, bool isVertical)
{
	sf::Sprite sprite;
	sprite.setTexture(textures[name]);

	if (isVertical)
	{
		sprite.setTextureRect(sf::IntRect(0, htile * x, wtile, htile));
	}
	else
	{
		sprite.setTextureRect(sf::IntRect(wtile * x, 0, wtile, htile));
	}

	return sprite;
}

sf::Sprite SpriteManager::getTileSprite(string name, int wtile, int htile, int x, int y)
{
	sf::Sprite sprite;
	sprite.setTexture(textures[name]);
	sprite.setTextureRect(sf::IntRect(wtile * x, htile * y, wtile, htile));
	return sprite;
}
