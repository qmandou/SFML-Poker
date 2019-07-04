#ifndef UIBUTTON__H
#define UIBUTTON__H

#include "UIGroupBox.h"
#include "SpriteManager.h"

class UIButton :
	public UIGroupBox
{
public:
	UIButton();
	UIButton(sf::FloatRect rect, sf::Color color, sf::Color onMouseColor, string text, sf::Texture* texture);
	UIButton(sf::FloatRect rect, sf::Color inColor, sf::Color outColor, float outSize, sf::Color onMouseColor, string text, sf::Texture* texture);

	~UIButton();
	void Draw(sf::RenderWindow& window);
	void Write(sf::RenderWindow& window, sf::Text text);
	void Update(sf::Event event, sf::RenderWindow& window);
	void Event(sf::Event event);

	inline void SetPosition(sf::Vector2f position) { m_rectColl.setPosition(position); }

	bool isSelected();
	bool isTextured();
private:
	sf::Color m_baseColor;
	sf::Color m_onMouseColor;
	string m_text;
	bool m_isActiv;

protected:
};

#endif // UIBUTTON__H


