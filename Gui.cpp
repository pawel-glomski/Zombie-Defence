#include "Gui.h"

void Gui::setFrame()
{
	frameTexture.loadFromFile("files/GameFrame.png");
	frameSprite.setTexture(frameTexture);
	frameSprite.setScale(window->getSize().x / (frameTexture.getSize().x - 2 * frameTexture.getSize().x / 48.0), window->getSize().y / (frameTexture.getSize().y - 2 * frameTexture.getSize().y / 24.16));
	frameSprite.setPosition(frameTexture.getSize().x / -48.0*frameSprite.getScale().x, frameTexture.getSize().y / -24.16 * frameSprite.getScale().y);
}

void Gui::setHP()
{
	char text[6];
	sprintf_s(text, "%i HP", character->getHp());
	hpButton.setActive(false);
	hpButton.setButtonText(text, 0.7);
	hpButton.setTextType("files/font.ttf");
	hpButton.setbuttonPosition(Vector2f(window->getSize().x / 3, window->getSize().y - window->getSize().y / 10));
	hpButton.scaleButton(*window, Vector2f(window->getSize().x / 3, window->getSize().y - window->getSize().y / 10));
}

void Gui::setAmmo()
{
	char text[8];
	sprintf_s(text, "%i AMMO", character->getAmmo());
	ammoButton.setActive(false);
	ammoButton.setButtonText(text, 0.7);
	ammoButton.setTextType("files/font.ttf");
	ammoButton.setbuttonPosition(Vector2f(window->getSize().x - window->getSize().x / 4, window->getSize().y - window->getSize().y / 10));
	ammoButton.scaleButton(*window, Vector2f(window->getSize().x - window->getSize().x / 4, window->getSize().y - window->getSize().y / 10));
}

void Gui::setCash()
{
	char text[10];
	sprintf_s(text, "%i CASH", character->getCash());
	cashButton.setActive(false);
	cashButton.setButtonText(text, 0.7);
	cashButton.setTextType("files/font.ttf");
	cashButton.setbuttonPosition(Vector2f(window->getSize().x - window->getSize().x / 10, window->getSize().y / 10));
	cashButton.scaleButton(*window, Vector2f(window->getSize().x - window->getSize().x / 10, window->getSize().y / 10));
}

void Gui::setStage(int & stage)
{
	this->stage = &stage;
	char text[10];
	sprintf_s(text, "STAGE %i", *this->stage);
	stageButton.setActive(false);
	stageButton.setButtonText(text, 0.7);
	stageButton.setTextType("files/font.ttf");
	stageButton.setbuttonPosition(Vector2f(window->getSize().x - window->getSize().x / 4, window->getSize().y / 10));
	stageButton.scaleButton(*window, Vector2f(window->getSize().x - window->getSize().x / 4, window->getSize().y / 10));
}

void Gui::setGui(RenderWindow & window, Character & character, int & gameStage)
{
	this->window = &window;
	this->character = &character;
	setFrame();
	setHP();
	setAmmo();
	setCash();
	setStage(gameStage);
}

void Gui::updateData()
{
	char text[15];
	sprintf_s(text, "%i HP", character->getHp());
	hpButton.setButtonText(text, 0.7);

	sprintf_s(text, "%i AMMO", character->getAmmo());
	ammoButton.setButtonText(text, 0.7);

	sprintf_s(text, "%i CASH", character->getCash());
	cashButton.setButtonText(text, 0.7);

	sprintf_s(text, "STAGE %i", *stage);
	stageButton.setButtonText(text, 0.7);
}

void Gui::drawGui()
{
	updateData();
	hpButton.drawButton(*window);
	ammoButton.drawButton(*window);
	cashButton.drawButton(*window);
	stageButton.drawButton(*window);
	window->draw(character->getWeaponPicture());
	window->draw(frameSprite);
}

Gui::Gui()
{
	character = NULL;
}


Gui::~Gui()
{
}
