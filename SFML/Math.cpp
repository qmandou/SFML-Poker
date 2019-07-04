#include "stdafx.h"
#include "Math.h"


float Math::Manhattan(sf::Vector2f a, sf::Vector2f b)
{
	return (fabsf(b.x - a.x) + fabsf(b.y - a.y));
}

int Math::Manhattan(sf::Vector2i a, sf::Vector2i b)
{
	return (abs(b.x - a.x) + abs(b.y - a.y));
}

float Math::Norme(sf::Vector2f a, sf::Vector2f b)
{
	return sqrtf((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
}

int Math::Norme(sf::Vector2i a, sf::Vector2i b)
{
	return (int)sqrt((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
}