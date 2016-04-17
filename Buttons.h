#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
using namespace std;
using namespace sf;
class Button
{
protected:
	Text buttonText;
	Font textType;
	bool active;
	int buttonPosition;
	float textSize;

	bool withBackground;
	Texture buttonBackgroundTexture;
	RectangleShape buttonBackgroundShape;


public:
	void setActive(bool active);
	bool isActive();

	void setButtonText(string text, float textSize = 1.0);	// rozmiar 1 - domyœlna wielkoœæ
	void setTextType(string fontName);
	void setbuttonPosition(RenderWindow & window, int buttonPosition);
	void setButtonBackgroundTexture(string name);
	void scaleButton(RenderWindow & window); // do skalowania po zmianie wielkosci okna, oraz do ustawienia t³a przycisku
	void drawButton(RenderWindow & window);


	bool buttonEvents(RenderWindow & window);	// sprawdza, czy myszka jest na przycisku
	Button();
	~Button();
};

