#include "stdafx.h"
#include "UITextBox.h"


UITextBox::UITextBox()
	: m_kr(KeyReader::all, 0)
{
	m_selected = false;
	m_rectColl = RectCollider(sf::FloatRect(0.f, 0.f, 0.f, 0.f), sf::Color::Transparent);
}

UITextBox::UITextBox(sf::FloatRect rect, sf::Color color, KeyReader::ReaderType rType, int maxSize)
	: m_kr(rType, maxSize)
{
	m_selected = false;
	m_rectColl = RectCollider(rect, color);
}

UITextBox::UITextBox(sf::FloatRect rect, sf::Color inColor, sf::Color outColor, float outSize, KeyReader::ReaderType rType, int maxSize)
	: m_kr(rType, maxSize)
{
	m_selected = false;
	m_rectColl = RectCollider(rect, inColor, outColor, outSize);
}

void UITextBox::Write(sf::RenderWindow& window, sf::Text text)
{
	text.setPosition(m_rectColl.getPosition().x + 5.f, m_rectColl.getPosition().y + (m_rectColl.getSize().y / 8.f));
	text.setString(m_kr.getBuffer());
	
	if (m_kr.pressEnter())
	{
		m_kr.resetBuffer();
	}

	window.draw(text);
}

void UITextBox::Event(sf::Event event)
{
	if(m_selected)
		m_kr.Event(event);
}

void UITextBox::Update(sf::Event event, sf::RenderWindow& window)
{
	sf::Vector2i mouse = sf::Mouse::getPosition(window);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && 
		m_rectColl.Collision(sf::Vector2f((float)mouse.x, (float)mouse.y)))
	{
		m_selected = true;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_selected = false;
	}
}

UITextBox::~UITextBox()
{

}
