#pragma once
#include "Buttons.h"
#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>

template <int buttonNumber>
class Menu
{
	Sound buttonSound;
	SoundBuffer buttonSoundBuffer;
	bool mouseOnButton;
	int whichButton;
	Texture backGroundTexture;
	Sprite backGroundSprite;
public:
	Button buttons[buttonNumber];
	bool isFullScreen;
private:
	void loadBackground(RenderWindow & window);
	bool events(RenderWindow & window, Event & event);
	void buttonSoundEvent(RenderWindow & window);
	bool choiceEvent(RenderWindow & window);
	void display(RenderWindow & window);
public:
	Menu();
	~Menu();

	int runMenu(RenderWindow & window);
	int getButtonNumber();
};

//////////////////////////////////////////////// cia³a metod /////////////////////////////////////////////

template<int buttonNumber>
int Menu<buttonNumber>::runMenu(RenderWindow & window)
{
	loadBackground(window);
	Event event;

	while (window.isOpen())
	{
		display(window);
		if (events(window, event)) return whichButton;
	}

	return -1;
}

template<int buttonNumber>
inline int Menu<buttonNumber>::getButtonNumber()
{
	return buttonNumber;
}

template<int buttonNumber>
void Menu<buttonNumber>::loadBackground(RenderWindow & window)
{
	backGroundTexture.loadFromFile("files/MenuBackground.png");
	backGroundSprite.setTexture(backGroundTexture);
	backGroundSprite.setScale(window.getSize().x / (float)backGroundTexture.getSize().x, window.getSize().y / (float)backGroundTexture.getSize().y);
	backGroundSprite.setPosition(0, 0);
}

template<int buttonNumber>
bool Menu<buttonNumber>::events(RenderWindow & window, Event & event)
{
	while (window.pollEvent(event))
	{
		buttonSoundEvent(window);
		if(choiceEvent(window)) return 1;
		
	}
	return 0;
}

template<int buttonNumber>
void Menu<buttonNumber>::buttonSoundEvent(RenderWindow & window)
{
	for (int i = 0; i < buttonNumber; i++)
	{

		if (buttons[i].buttonEvents(window) && !mouseOnButton && buttons[i].isActive())
		{
			buttonSound.play();
			mouseOnButton = true;
			whichButton = i;
		}
		else if (!buttons[whichButton].buttonEvents(window))
		{
			whichButton = 0;
			mouseOnButton = 0;
		}
	}
}

template<int buttonNumber>
bool Menu<buttonNumber>::choiceEvent(RenderWindow & window)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		for (int i = 0; i < buttonNumber; i++)
			if (buttons[i].buttonEvents(window) && buttons[i].isActive())
			{
				whichButton = i;
				return 1;
			}
				
	}
	return 0;
		
}

template<int buttonNumber>
void Menu<buttonNumber>::display(RenderWindow & window)
{
	window.clear();
	window.draw(backGroundSprite);
	for (int i = 0; i < buttonNumber; i++) buttons[i].drawButton(window);
	window.display();
}

template<int buttonNumber>
Menu<buttonNumber>::Menu()
{
	buttonSoundBuffer.loadFromFile("files/BUTTON.wav");
	buttonSound.setBuffer(buttonSoundBuffer);
	mouseOnButton = false;
	whichButton = 0;
	isFullScreen = 0;
}

template<int buttonNumber>
Menu<buttonNumber>::~Menu()
{
}