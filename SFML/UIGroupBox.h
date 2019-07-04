
#ifndef UIGROUPBOX__H
#define UIGROUPBOX__H

#include "../Collider.h"
#include <iostream>

using namespace std;

class UIGroupBox
{

public:
	UIGroupBox(sf::FloatRect rect, sf::Color color);
	UIGroupBox(sf::FloatRect rect, sf::Color inColor, sf::Color outColor, float outSize);
	UIGroupBox();
	virtual ~UIGroupBox();

	inline RectCollider getRectCollider() { return  m_rectColl; }

	virtual void Update(sf::Event event, sf::RenderWindow& window);
	virtual void Event(sf::Event event);
	virtual void Write(sf::RenderWindow& window, sf::Text text);
	virtual void Draw(sf::RenderWindow& window);

	void MoveWindow(sf::Event event, sf::RenderWindow& window);

private:
	sf::Vector2f m_mouseShift;

protected:
	bool isOnMouse(sf::RenderWindow& window);
	bool m_selected;
	RectCollider m_rectColl;
};

#endif // UIGROUPBOX__H




