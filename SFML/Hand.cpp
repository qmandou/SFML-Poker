#include "stdafx.h"
#include "Hand.h"

Hand::Hand()
{
	
}

Hand::Hand(sf::Vector2f position, SpriteManager* spriteManager)
{
	for (int i = 0; i < CARD_BY_HAND; i++)
	{
		hand[i] = Card(sf::FloatRect(position.x + (i * 110.f), position.y, 90.f, 150.f), sf::Color::White, spriteManager);
	}
}

void Hand::SetCardData(CardData cardData[CARD_BY_HAND])
{
	for (int i = 0; i < CARD_BY_HAND; i++)
	{
		hand[i].setCardData(cardData[i]);
	}
}

Hand::~Hand()
{

}

void Hand::Draw(sf::RenderWindow* window)
{
	for (int i = 0; i < CARD_BY_HAND; i++)
	{
		hand[i].Draw(*window);
	}
}

int CardCompare(const void* a, const void* b)
{
	CardData* aCard = (CardData*)a;
	CardData* bCard = (CardData*)b;

	if (aCard->type > bCard->type)
		return 1;
	else if (aCard->type < bCard->type)
		return -1;
	else
		return 0;
}

int Hand::Score()
{
	int score = -1;
	CardData _aCardDataHand[CARD_BY_HAND];
	bool isFlush, isStraight;

	score = NType();

	for (int i = 0; i < CARD_BY_HAND; i++)
	{
		_aCardDataHand[i] = hand[i].getCardData();
	}

	isFlush = IsFlush();

	qsort(_aCardDataHand, CARD_BY_HAND, sizeof(CardData), CardCompare);

	isStraight = IsStraight();

	if (isStraight && isFlush)
	{
		if (AsRoi())
		{
			score = QUINTE_FLUSH_ROYALE;
		}
		else 
		{
			score = QUINTE_FLUSH;
		}
	}
	else if (isFlush && score < FLUSH)
	{
		score = FLUSH;
	}
	else if (isStraight && score < QUINTE)
	{
		score = QUINTE;
	}

	if (score == -1 && AsRoi())
	{
		score = ASROI;
	}

	return score;
}

bool Hand::AsRoi()
{
	bool as = false, roi = false;
	for (int i = 0; i < CARD_BY_HAND; i++)
	{
		int type = (int)hand[i].getCardData().type;

		if (type == 0)
		{
			as = true;
		}

		if (type == 12)
		{
			roi = true;
		}
	}

	return as && roi;
}

bool Hand::IsFlush()
{
	char memSeries = hand[0].getCardData().series;

	for (int i = 1; i < CARD_BY_HAND; i++)
	{
		if (memSeries != hand[i].getCardData().series)
		{
			return false;
		}
	}

	return true;
}

int Hand::NType()
{
	int type[CARD_BY_SERIES];
	bool pair = false, doublePair = false, brelan = false;

	for(int i = 0; i < CARD_BY_SERIES; i++)
	{
		type[i] = 0;
	}

	for (int i = 0; i < CARD_BY_HAND; i++)
	{
		type[hand[i].getCardData().type]++;
	}

	for (int i = 0; i < CARD_BY_SERIES; i++)
	{
		if (type[i] == 4)
		{
			return CARRE;
		}
		else if (type[i] == 3)
		{
			brelan = true;
		}
		else if (type[i] == 2 && !pair)
		{
			pair = true;
		}
		else if (type[i] == 2)
		{
			doublePair = true;
		}
	}

	if (brelan && pair)
	{
		return FULL;
	}
	else if (brelan)
	{
		return BRELAN;
	}
	else if (doublePair)
	{
		return DOUBLE_PAIR;
	}
	else if (pair)
	{
		return PAIR;
	}
	else
	{
		return -1;
	}
}

void Hand::HideHand()
{
	for (int i = 0; i < CARD_BY_HAND - 1; i++)
	{
		hand[i].setHidden(true);
	}
}

void Hand::DiscoverHand()
{
	for (int i = 0; i < CARD_BY_HAND - 1; i++)
	{
		hand[i].setHidden(false);
	}
}

bool Hand::IsStraight()
{
	if ((int)hand[0].getCardData().type == 0 && 
		(int)hand[CARD_BY_HAND - 1].getCardData().type == CARD_BY_SERIES - 1)
	{
		for (int i = 1; i < CARD_BY_HAND - 1; i++)
		{
			if ((int)hand[i].getCardData().type != 9 + (i - 1))
			{
				return false;
			}
		}
	}
	else
	{
		for (int i = 0; i < CARD_BY_HAND - 1; i++)
		{
			if ((int)hand[i].getCardData().type != (int)hand[i + 1].getCardData().type - 1)
			{
				return false;
			}
		}
	}

	return true;
}

