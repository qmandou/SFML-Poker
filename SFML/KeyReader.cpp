#include "stdafx.h"
#include "KeyReader.h"


KeyReader::KeyReader(ReaderType rt, int maxSize)
	: m_type(rt), m_buffer(""), m_clock(), m_enter(false), m_maxSize(maxSize), m_countMajChar(0)
{

}

KeyReader::~KeyReader()
{
	m_buffer.erase(m_buffer.begin(), m_buffer.end());
}

void KeyReader::Event(sf::Event event)
{
	if (m_clock.getElapsedTime().asSeconds() > 0.020f && event.type == sf::Event::KeyPressed)
	{

		if (m_buffer.size() <= m_maxSize)
		{
			if (event.key.code <= sf::Keyboard::Z && m_type != onlyNumber)
			{
				if (event.key.shift && (m_type != onlyCharMin || m_type != NumCharMin))
				{
					m_buffer += 'A' + event.key.code;
					m_countMajChar++;
				}
				else
				{
					m_buffer += 'a' + event.key.code;
				}
			}

			if (m_type >= NumCharMin)
			{
				if (event.key.code >= sf::Keyboard::Num0 && event.key.code <= sf::Keyboard::Num9)
				{
					m_buffer += '0' + (event.key.code - sf::Keyboard::Num0);
				}
				else if (event.key.code >= sf::Keyboard::Numpad0 && event.key.code <= sf::Keyboard::Numpad9)
				{
					m_buffer += '0' + (event.key.code - sf::Keyboard::Numpad0);
				}
			}

			if (event.key.code == sf::Keyboard::Space)
			{
				m_buffer += ' ';
			}
		}

		if (event.key.code == sf::Keyboard::BackSpace && m_buffer.size() != 0)
		{
			if (m_buffer[m_buffer.size() - 1] >= 'A' && m_buffer[m_buffer.size() - 1] <= 'Z')
				m_countMajChar--;
			m_buffer.erase(m_buffer.end() - 1, m_buffer.end());
		}
		else if (event.key.code == 58)
		{
			m_enter = true;
			cout << m_buffer << endl;
		}

		m_clock.restart();
	}
}
