#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Menu.h"
#include "Map.h"
#include "Character.h"
#include "Gui.h"
#include "Ai_Manager.h"




enum GameType {noType, survivalType};

class Game
{
protected:
	RenderWindow *window;
	Event event;
	bool isPlaying;
	Menu<3> pauseMenu;
	Gui gui;
	Character character;
	int stage;	// etap gry, runda
	Music music;

	void setPauseButtons();
public:
	virtual void run(RenderWindow & window) = 0;

	Game();
	~Game();
};

