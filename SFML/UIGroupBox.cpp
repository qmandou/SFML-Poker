#include "stdafx.h"
#include "UIGroupBox.h"

UIGroupBox::UIGroupBox(sf::FloatRect rect, sf::Color color)
 : m_selected(false), m_rectColl(rect, color)
{

}

UIGroupBox::UIGroupBox(sf::FloatRect rect, sf::Color inColor, sf::Color outColor, float outSize)
	: m_selected(false), m_rectColl(rect, inColor, outColor, outSize)
{

}

UIGroupBox::UIGroupBox()
	:	m_selected(false), m_rectColl(sf::FloatRect( 0.f, 0.f, 0.f, 0.f), sf::Color::Transparent)
{

}

UIGroupBox::~UIGroupBox()
{

}

void UIGroupBox::Write(sf::RenderWindow& window, sf::Text text)
{

}

void UIGroupBox::Update(sf::Event event, sf::RenderWindow& window)
{

}

void UIGroupBox::Draw(sf::RenderWindow& window)
{

}

void UIGroupBox::Event(sf::Event event)
{

}

void UIGroupBox::MoveWindow(sf::Event event, sf::RenderWindow& window)
{
	if (!m_selected &&
		sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
		isOnMouse(window))
	{
		// Selected
		cout << "Selected" << endl;
		m_rectColl.setOutlineColor(sf::Color::Red);
		m_mouseShift = sf::Vector2f(m_rectColl.getPosition().x - (float)sf::Mouse::getPosition(window).x, m_rectColl.getPosition().y - (float)sf::Mouse::getPosition(window).y);
		m_selected = true;
	}

	if (m_selected && event.type == sf::Event::MouseButtonReleased)
	{
		//Realese
		cout << "Released" << endl;
		m_rectColl.setOutlineColor(sf::Color::Blue);
		m_mouseShift = sf::Vector2f(0.f, 0.f);
		m_selected = false;
	}
	else if (m_selected && event.type == sf::Event::MouseMoved)
	{
		// Drag
		cout << "Drag" << endl;
		m_rectColl.setPosition((float)sf::Mouse::getPosition(window).x + m_mouseShift.x, (float)sf::Mouse::getPosition(window).y + m_mouseShift.y);
	}
}

bool UIGroupBox::isOnMouse(sf::RenderWindow& window)
{
	return m_rectColl.Collision(sf::Vector2f((float)sf::Mouse::getPosition(window).x,
											 (float)sf::Mouse::getPosition(window).y));
}


sf::Color SwapColor(bool b)
{
	return b ? sf::Color::Blue : sf::Color::Red;
}