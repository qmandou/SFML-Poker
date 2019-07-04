#ifndef UISLIDER__H
#define UISLIDER__H

#include "UIGroupBox.h"

class UISlider :
	public UIGroupBox
{
public:
	UISlider();
	UISlider(sf::FloatRect rect, sf::Color color, sf::Color circleColor, int maxValue);
	UISlider(sf::FloatRect rect, sf::Color inColor, sf::Color outColor, float outSize, sf::Color circleColor, int maxValue);
	~UISlider();

	void Update(sf::Event event, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	float inline Rate() { return ((float)m_value / (float)m_maxValue) * m_rectColl.getSize().x; }
private:
	CircleColider m_circle;
	int m_value;
	int m_maxValue;
	sf::Vector2f m_startPosition;
	sf::Vector2i m_oldMouse;
	bool m_circleClic;
protected:
};

#endif // UISLIDER__H

