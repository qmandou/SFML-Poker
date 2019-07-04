#ifndef UICHECK__H
#define UICHECK__H

#include "UIGroupBox.h"


class UICheck :
	public UIGroupBox
{
public:
	UICheck();
	UICheck(sf::FloatRect rect, sf::Color color);
	UICheck(sf::FloatRect rect, sf::Color inColor, sf::Color outColor, float outSize);

	~UICheck();

	void Update(sf::Event event, sf::RenderWindow& window);
private:

protected:
};

sf::Color SwapColor(bool b);

#endif // UICHECK__H

