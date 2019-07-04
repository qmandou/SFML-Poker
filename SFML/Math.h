#ifndef MATH__H
#define MATH__H


class Math
{

public:
	static float Manhattan(sf::Vector2f a, sf::Vector2f b);
	static int Manhattan(sf::Vector2i a, sf::Vector2i b);

	static float Norme(sf::Vector2f a, sf::Vector2f b);
	static int Norme(sf::Vector2i a, sf::Vector2i b);
};



#endif // !MATH__H
