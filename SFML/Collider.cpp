#include "stdafx.h"
#include "Collider.h"
#include "Math.h"

RectCollider::RectCollider(sf::FloatRect rect, sf::Color color)
{
	setPosition(sf::Vector2f(rect.left, rect.top));
	setSize(sf::Vector2f(rect.width, rect.height));
	setFillColor(color);
}


RectCollider::RectCollider(sf::FloatRect rect, sf::Color inColor, sf::Color outColor, float outSize)
{
	setPosition(sf::Vector2f(rect.left, rect.top));
	setSize(sf::Vector2f(rect.width, rect.height));
	setFillColor(inColor);
	setOutlineColor(outColor);
	setOutlineThickness(outSize);
}

RectCollider::~RectCollider()
{

}


bool RectCollider::Collision(sf::Vector2f position)
{
	sf::Vector2f rectPos = getPosition();
	sf::Vector2f rectSize = getSize();

	return ((position.x >= rectPos.x && position.x <= rectPos.x + rectSize.x) &&
			(position.y >= rectPos.y && position.y <= rectPos.y + rectSize.y)) 
			? true : false;
}

CircleColider::CircleColider(sf::Vector2f position, float radius, sf::Color color)
{
	setPosition(position);
	setRadius(radius);
	setFillColor(color);
}

CircleColider::~CircleColider()
{

}

bool CircleColider::Collision(sf::Vector2f position)
{
	float radius = getRadius();
	sf::Vector2f rectPos = CircleCenter(getPosition(), radius);

	float norme = Math::Norme(rectPos, position);

	return radius >= norme ? true : false;
}
