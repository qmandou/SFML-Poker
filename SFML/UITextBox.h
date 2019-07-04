#ifndef UICHECK__H
#define UICHECK__H

#include "UIGroupBox.h"
#include "KeyReader.h"
#include "../GameManager.h"

class UITextBox :
	public UIGroupBox
{
public:
	UITextBox();
	UITextBox(sf::FloatRect rect, sf::Color color, KeyReader::ReaderType rType, int maxSize);
	UITextBox(sf::FloatRect rect, sf::Color inColor, sf::Color outColor, float outSize, KeyReader::ReaderType rType, int maxSize);
	
	~UITextBox();


	void Event(sf::Event event);
	void Update(sf::Event event, sf::RenderWindow& window);
	void Write(sf::RenderWindow& window, sf::Text text);

private:

	KeyReader m_kr;
protected:
	
};


#endif // UICHECK__H
