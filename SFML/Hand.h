#ifndef HAND__H
#define HAND__H

#include "Card.h"

#define ASROI 0
#define PAIR 1
#define DOUBLE_PAIR 2
#define BRELAN 3
#define QUINTE 4
#define FLUSH 5
#define FULL 7
#define CARRE 20
#define QUINTE_FLUSH 50
#define QUINTE_FLUSH_ROYALE 100

class Hand
{

public:
	Hand();
	Hand(sf::Vector2f position, SpriteManager* spriteManager);
	~Hand();

	void SetCardData(CardData cardData[CARD_BY_HAND]);
	int Score();
	void Draw(sf::RenderWindow* window);
	void HideHand();
	void DiscoverHand();
private:
	Card hand[CARD_BY_HAND];
	bool AsRoi();
	bool IsFlush();
	bool IsStraight();
	int NType();
};


#endif // !HAND__H
