#pragma once
#include "Buttons.h"
class GameButton :
	public Button
{
public:
	void setbuttonPosition(Vector2f position);
	void scaleButton(RenderWindow & window, Vector2f position); // do skalowania po zmianie wielkosci okna, oraz do ustawienia t³a przycisku
	GameButton();
	~GameButton();
};

