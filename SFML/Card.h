#ifndef CARD__H
#define CARD__H

#include "Collider.h"
#include "SpriteManager.h"

#define CARD_BY_SERIES 13
#define CARD_BY_HAND 5
#define CARD_NBR 52

#define COEUR 0
#define CARREAU 1
#define TREFLE 2
#define PIQUE 3

#define STRAIGHT 0
#define FLUSH 1
#define STRAIGHT_FLUSH 2

#define SPRITE_WIDTH 68
#define SPRITE_HEIGHT 96

#define SPRITE_LINE 11
#define SPRITE_COL 5

typedef struct CardData
{
	char series;
	char type;
}CardData;

class Card
{

public:
	Card();
	Card(sf::FloatRect _rect, sf::Color _color, SpriteManager* spriteManager);
	~Card();

	void Draw(sf::RenderWindow &window);

	inline void setCardData(CardData& _data) { data = _data; }
	inline CardData& getCardData() { return data; }

	void inline setTexture(sf::Texture* texture) { rect.setTexture(texture); }
	void inline setPosition(sf::Vector2f position) { rect.setPosition(position); }

	sf::Vector2f inline getPosition() { return rect.getPosition(); }

	void inline setHidden(bool _hidden) { hidden = _hidden; }
	bool inline isHidden() { return hidden; }
private:

	bool hidden;
	RectCollider rect;
	CardData data;
};


#endif // !CARD__H
