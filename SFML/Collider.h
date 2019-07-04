#ifndef COLLIDER__H
#define COLLIDER__H

#include <SFML/Graphics.hpp>
#include "Math.h"

class RectCollider : public sf::RectangleShape
{
public:
	RectCollider(sf::FloatRect rect, sf::Color color);
	RectCollider(sf::FloatRect rect, sf::Color inColor, sf::Color outColor, float outSize);
	~RectCollider();

	bool Collision(sf::Vector2f position);
};

class CircleColider : public sf::CircleShape
{

public:
	CircleColider(sf::Vector2f position, float radius, sf::Color color);
	~CircleColider();

	static inline sf::Vector2f CircleCenter(sf::Vector2f position, float radius) { return sf::Vector2f(position.x + radius, position.y + radius); }
	bool Collision(sf::Vector2f position);
};


#endif // !COLLIDER__H
