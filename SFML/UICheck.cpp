#include "stdafx.h"
#include "UICheck.h"


UICheck::UICheck()
{
	m_selected = false;
	m_rectColl = RectCollider(sf::FloatRect(0.f, 0.f, 0.f, 0.f), sf::Color::Transparent);
}

UICheck::UICheck(sf::FloatRect rect, sf::Color color)
{
	m_selected = false;
	m_rectColl = RectCollider(rect, color);
}

UICheck::UICheck(sf::FloatRect rect, sf::Color inColor, sf::Color outColor, float outSize)
{
	m_selected = false;
	m_rectColl = RectCollider(rect, inColor, outColor, outSize);
}

UICheck::~UICheck()
{

}

void UICheck::Update(sf::Event event, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
		isOnMouse(window))
	{
		// Clicked
		m_selected = !m_selected;
		m_rectColl.setOutlineColor(SwapColor(m_selected));
	}
}



