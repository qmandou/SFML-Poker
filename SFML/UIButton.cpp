#include "stdafx.h"
#include "UIButton.h"


UIButton::UIButton()
	: m_onMouseColor(sf::Color::Transparent)
{
	m_selected = false;
	m_isActiv = false;
	m_rectColl = RectCollider(sf::FloatRect(0.f, 0.f, 0.f, 0.f), sf::Color::Transparent);
}

UIButton::UIButton(sf::FloatRect rect, sf::Color color, sf::Color onMouseColor, string text, sf::Texture* _texture)
	: m_onMouseColor(onMouseColor), m_text(text)
{
	m_baseColor = color;
	m_selected = false;
	m_isActiv = false;
	m_rectColl = RectCollider(rect, color);

	if(_texture != nullptr)
	{
		m_rectColl.setTexture(_texture, true);
		m_rectColl.setTextureRect(sf::IntRect(0, 0, 256, 80));
	}
	else
	{
		cout << "texture button load error" << endl;
	}
}

UIButton::UIButton(sf::FloatRect rect, sf::Color inColor, sf::Color outColor, float outSize, sf::Color onMouseColor, string text, sf::Texture* _texture)
	: m_onMouseColor(onMouseColor), m_text(text)
{
	m_baseColor = inColor;
	m_selected = false;
	m_isActiv = false;
	m_rectColl = RectCollider(rect, inColor, outColor, outSize);

	if (_texture != nullptr)
	{
		m_rectColl.setTexture(_texture);
		m_rectColl.setTextureRect(sf::IntRect(0, 0, 256, 80));
	}
	else
	{
		cout << "texture button load error" << endl;
	}
}

UIButton::~UIButton()
{

}

void UIButton::Update(sf::Event event, sf::RenderWindow& window)
{ 
	if (isOnMouse(window))
	{
		if (isTextured())
		{
			m_rectColl.setTextureRect(sf::IntRect(0, 80, 256, 80));
		}
		else
		{
			m_rectColl.setFillColor(m_onMouseColor);
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !m_selected)
		{
			m_selected = true;
			m_isActiv = true;
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isTextured())
		{
			m_rectColl.setTextureRect(sf::IntRect(0, 160, 256, 80));
		}
	}
	else
	{
		if (isTextured())
		{
			m_rectColl.setTextureRect(sf::IntRect(0, 0, 256, 80));
		}
		else
		{
			m_rectColl.setFillColor(m_baseColor);
		}
	}
}

void UIButton::Event(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonReleased)
	{
		m_selected = false;
	}
}

void UIButton::Draw(sf::RenderWindow& window)
{
	window.draw(m_rectColl);
}


void UIButton::Write(sf::RenderWindow& window, sf::Text text)
{
	window.draw(m_rectColl);
	text.setColor(sf::Color::Black);
	text.setCharacterSize(m_rectColl.getSize().y/ 2);
	text.setPosition(m_rectColl.getPosition().x + (m_rectColl.getSize().x / 2.f - (m_text.size() * 5.f)), m_rectColl.getPosition().y + (m_rectColl.getSize().y / 6.f));
	text.setString(m_text);

	window.draw(text);
}

bool UIButton::isSelected() 
{
	if(m_isActiv)
	{
		m_isActiv = false;
		return true;
	}

	return false;
}

bool UIButton::isTextured()
{
	return m_rectColl.getTexture() != nullptr;
}