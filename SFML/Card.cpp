#include "stdafx.h"
#include "Card.h"

Card::Card()
	: rect(sf::FloatRect(0, 0, 100, 100), sf::Color::Blue), data({0,0})
{
	hidden = false;
}

Card::Card(sf::FloatRect _rect, sf::Color _color, SpriteManager* spriteManager)
	: rect(_rect, _color), data({0,0})
{
	rect.setTexture(spriteManager->getTexture("CardDeck"));
	hidden = false;
}

Card::~Card()
{

}

void Card::Draw(sf::RenderWindow& _window)
{
	if (rect.getTexture() != NULL )
	{
		if (hidden)
		{
			rect.setTextureRect(sf::IntRect(13 * SPRITE_WIDTH, 0, SPRITE_WIDTH, SPRITE_HEIGHT));
		}
		else
		{
			rect.setTextureRect(sf::IntRect(((int)data.type == 0 ? 12 : (int)data.type - 1) * SPRITE_WIDTH, (int)data.series * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
		}
	}

	_window.draw(rect);
}
