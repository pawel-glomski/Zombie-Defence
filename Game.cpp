#include "Game.h"


void Game::setPauseButtons()
{
	pauseMenu.buttons[0].setActive(false);
	pauseMenu.buttons[0].setButtonText("PAUZA", 2);
	pauseMenu.buttons[1].setButtonText("WROC", 1);
	pauseMenu.buttons[2].setButtonText("MENU", 1);
	for (int i = 0; i < pauseMenu.getButtonNumber(); i++)
	{
		pauseMenu.buttons[i].setTextType("files/font.ttf");
		pauseMenu.buttons[i].setButtonBackgroundTexture("files/buttonBackground.bmp");
		pauseMenu.buttons[i].setbuttonPosition(*window, i + 1);
		pauseMenu.buttons[i].scaleButton(*window);
	}
}

Game::Game()
{

}


Game::~Game()
{
}
