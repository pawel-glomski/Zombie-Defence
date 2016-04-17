#include "Buttons.h"

void Button::setActive(bool active)
{
	this->active = active;
	if (!active)
		withBackground = false;
}
bool Button::isActive()
{
	return active;
}

void Button::setButtonText(string text, float textSize)
{
	this->textSize = textSize;
	buttonText.setString(text);
}

void Button::setTextType(string fontName)
{
	if (!textType.loadFromFile(fontName))
		cout << "Nie udalo sie wczytac pliku .ttf" << endl;
	buttonText.setStyle(Text::Bold);
	buttonText.setFont(textType);
}

void Button::setbuttonPosition(RenderWindow & window, int buttonPosition)
{
	this->buttonPosition = buttonPosition;
	buttonText.setPosition(float(window.getSize().x / 2 - buttonText.getGlobalBounds().width/2), buttonPosition-1*window.getSize().x / 100 + buttonPosition*window.getSize().y/10);
}

void Button::setButtonBackgroundTexture(string name)
{
	if (!buttonBackgroundTexture.loadFromFile(name))
		cout << "Nie udalo sie wczytac tekstury przycisku" << endl;

	buttonBackgroundShape.setTexture(&buttonBackgroundTexture);
	buttonBackgroundShape.setTextureRect(IntRect(0, 0, buttonBackgroundTexture.getSize().x / 2, buttonBackgroundTexture.getSize().y));
}

void Button::scaleButton(RenderWindow & window)
{
	buttonText.setCharacterSize(int(30.0 * textSize * (window.getSize().x/ window.getSize().y)));
	setbuttonPosition(window, buttonPosition);
	buttonBackgroundShape.setSize(Vector2f(float(window.getSize().x/2) * textSize, buttonText.getGlobalBounds().height ));
	buttonBackgroundShape.setPosition(window.getSize().x/2 - buttonBackgroundShape.getSize().x/2, buttonText.getPosition().y + 2*textSize);
}

void Button::drawButton(RenderWindow & window)
{
	if (withBackground)
		window.draw(buttonBackgroundShape);
	window.draw(buttonText);
}

bool Button::buttonEvents(RenderWindow & window)
{
	if (buttonBackgroundShape.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
	{
		buttonBackgroundShape.setTextureRect(IntRect(buttonBackgroundTexture.getSize().x / 2, 0, buttonBackgroundTexture.getSize().x / 2, buttonBackgroundTexture.getSize().y));
		return 1;
	}
	else
		buttonBackgroundShape.setTextureRect(IntRect(0, 0, buttonBackgroundTexture.getSize().x / 2, buttonBackgroundTexture.getSize().y));
	return 0;
}

Button::Button()
{
	withBackground = true;
	active = true;
}
Button::~Button(){}
