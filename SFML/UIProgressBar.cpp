#include "stdafx.h"
#include "UIProgressBar.h"


UIProgressBar::UIProgressBar()
	: m_progressRect(sf::FloatRect(0.f, 0.f, 0.f, 0.f), sf::Color::Transparent), m_maxValue(0), m_value(0)
{
	m_selected = false;
	m_rectColl = RectCollider(sf::FloatRect(0.f, 0.f, 0.f, 0.f), sf::Color::Transparent);
}

UIProgressBar::UIProgressBar(sf::FloatRect rect, sf::Color color, sf::FloatRect rectProgress, sf::Color colorProgress, int maxValue)
	: m_progressRect(rectProgress, colorProgress), m_maxValue(maxValue), m_value(0)
{
	m_selected = false;
	m_rectColl = RectCollider(rect, color);
}

UIProgressBar::UIProgressBar(sf::FloatRect rect, sf::Color inColor, sf::Color outColor, float outSize,
	                         sf::FloatRect rectProgress, sf::Color inColorProgress, sf::Color outColorProgress, float outSizeProgress, int maxValue)
	: m_progressRect(rectProgress, inColorProgress, outColorProgress, outSizeProgress), m_maxValue(maxValue), m_value(0)
{
	m_selected = false;
	m_rectColl = RectCollider(rect, inColor, outColor, outSize);
}

UIProgressBar::~UIProgressBar()
{

}

void UIProgressBar::Draw(sf::RenderWindow& window)
{
	window.draw(m_progressRect);
}

void UIProgressBar::Update(sf::Event event, sf::RenderWindow& window)
{
	m_progressRect.setScale(sf::Vector2f((float)m_value / (float)m_maxValue, 1.f));
}