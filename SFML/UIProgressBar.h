#ifndef UIPROGRESSBAR__H
#define UIPROGRESSBAR__H

#include "UIGroupBox.h"

class UIProgressBar
	: public UIGroupBox
{

public:
	UIProgressBar();
	UIProgressBar(sf::FloatRect rect, sf::Color color, sf::FloatRect rectProgress, sf::Color colorProgress, int maxValue);

	UIProgressBar(sf::FloatRect rect, sf::Color inColor, sf::Color outColor, float outSize,
				  sf::FloatRect rectProgress, sf::Color inColorProgress, sf::Color outColorProgress, 
				  float outSizeProgress, int maxValue);

	~UIProgressBar();

	inline void setValue(int value) { m_value = value; }
	inline const int getValue() { return m_value; }

	inline void setMaxValue(int value) { m_maxValue = value; }
	inline const int getMaxValue() { return m_maxValue; }

	void Update(sf::Event event, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);

private:
	int m_value;
	int m_maxValue;

	RectCollider m_progressRect;
protected:

};



#endif