#pragma once
#include <SFML\Graphics.hpp>
#include "Character.h"
#include "Weapons.h"
#include "GameButton.h"

using namespace sf;
class Gui
{
	RenderWindow *window;

	Texture frameTexture;	// ramka
	Sprite frameSprite;

	Character * character;
	GameButton hpButton;
	GameButton ammoButton;
	GameButton cashButton;
	GameButton stageButton;
	int *stage;

private:
	void setFrame();	// ustaw ramke

	void setHP();

	void setAmmo();

	void setCash();

	void setStage(int & stage);

	void updateData();
public:
	void setGui(RenderWindow & window, Character & character, int & gameStage);
	void drawGui();
	Gui();
	~Gui();
};

