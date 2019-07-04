#ifndef KEYREADER__H
#define KEYREADER__H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class KeyReader
{

	/*
		Cette class permet de récupérer les saisis clavier
		dans un buffer.
	*/

public:

	enum ReaderType
	{
		onlyChar,
		onlyCharMin,
		NumCharMin,
		onlyNumber,
		all
	};


	KeyReader(ReaderType rt, int maxSize);
	~KeyReader();

	void Event(sf::Event event);
	inline bool pressEnter() { return m_enter; }
	inline string getBuffer() { return m_buffer; }
	inline void resetBuffer() { m_buffer.erase(m_buffer.begin(), m_buffer.end()); m_enter = false; }

private:

	ReaderType m_type;
	bool m_enter;
	unsigned int m_maxSize;
	unsigned int m_countMajChar;
	string m_buffer;
	sf::Clock m_clock;
protected:
};

#endif // !KEYREADER__H
