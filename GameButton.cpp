#include "GameButton.h"



void GameButton::setbuttonPosition(Vector2f position)
{
	buttonText.setPosition(position.x - buttonText.getGlobalBounds().width/2, position.y);
}

void GameButton::scaleButton(RenderWindow & window, Vector2f position)
{
	buttonText.setCharacterSize(30.0 * textSize * (window.getSize().x / window.getSize().y));
	setbuttonPosition(position);
	buttonBackgroundShape.setSize(Vector2f(float(window.getSize().x / 2) * textSize, buttonText.getGlobalBounds().height));
	buttonBackgroundShape.setPosition(window.getSize().x / 2 - buttonBackgroundShape.getSize().x / 2, buttonText.getPosition().y + 2 * textSize);
}

GameButton::GameButton()
{
}


GameButton::~GameButton()
{
}
