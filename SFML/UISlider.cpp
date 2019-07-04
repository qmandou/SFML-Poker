#include "stdafx.h"
#include "UISlider.h"

UISlider::UISlider()
	: m_circle(sf::Vector2f(0.f,0.f), 0, sf::Color::Transparent), m_value(0), m_maxValue(0), m_circleClic(false)
{
	m_selected = false;
	m_rectColl = RectCollider(sf::FloatRect(0.f, 0.f, 0.f, 0.f), sf::Color::Transparent);
}

UISlider::UISlider(sf::FloatRect rect, sf::Color color, sf::Color circleColor, int maxValue)
	: m_circle(sf::Vector2f(rect.left - rect.height / 8.f, rect.top - rect.height / 2.f), rect.height, circleColor), m_value(0), m_maxValue(maxValue), m_circleClic(false)
{
	m_startPosition = sf::Vector2f(rect.left - rect.height / 8.f, rect.top - rect.height / 2.f);
	m_selected = false;
	m_rectColl = RectCollider(rect, color);
}

UISlider::UISlider(sf::FloatRect rect, sf::Color inColor, sf::Color outColor, float outSize, sf::Color circleColor, int maxValue)
	: m_circle(sf::Vector2f(rect.left - rect.height / 8.f, rect.top - rect.height / 2.f), rect.height * 2, circleColor), m_value(0), m_maxValue(maxValue), m_circleClic(false)
{
	m_startPosition = sf::Vector2f(rect.left - rect.height / 8.f, rect.top - rect.height / 2.f);
	m_selected = false;
	m_rectColl = RectCollider(rect, inColor, outColor, outSize);
}

void UISlider::Draw(sf::RenderWindow& window)
{
	window.draw(m_circle);
}

void UISlider::Update(sf::Event event, sf::RenderWindow& window)
{
	sf::Vector2i mouse = sf::Mouse::getPosition(window);
	m_circle.setPosition(sf::Vector2f(m_startPosition.x + Rate(), m_startPosition.y));

	if (event.type == sf::Event::MouseButtonReleased)
		m_circleClic = false;

	if (m_circleClic)
	{
		if (m_circle.getPosition().x + m_circle.getRadius() < mouse.x - 10.f && m_value < m_maxValue)
			m_value++;
		else if(m_circle.getPosition().x + m_circle.getRadius() > mouse.x + 10.f && m_value > 0)
			m_value--;
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (m_circle.Collision(sf::Vector2f((float)mouse.x, mouse.y)))
		{
			m_circleClic = true;
		}
	}

	m_oldMouse = mouse;
}

UISlider::~UISlider()
{

}
