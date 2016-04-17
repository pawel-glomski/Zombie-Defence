#include <iostream>
#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "Survival.h"

using namespace std;
using namespace sf;

void setMainMenuButtons(Button buttons[], int buttonNumber, RenderWindow & window)
{
	buttons[0].setActive(false);
	buttons[0].setButtonText("Zombie Defence", 2);
	buttons[1].setButtonText("Nowa Gra", 1);
	buttons[2].setButtonText("Wczytaj", 1);
	buttons[3].setButtonText("Ustawienia", 1);
	buttons[4].setButtonText("Wyjscie", 1);
	for (int i = 0; i < buttonNumber; i++)
	{
		buttons[i].setTextType("files/font.ttf");
		buttons[i].setButtonBackgroundTexture("files/buttonBackground.bmp");
		buttons[i].setbuttonPosition(window, i + 1);
		buttons[i].scaleButton(window);
	}
}
int runMainMenu(RenderWindow & window)
{
	Menu <5> mainMenu;
	setMainMenuButtons(mainMenu.buttons, mainMenu.getButtonNumber(), window);
	return mainMenu.runMenu(window);
}

void setGameTypeMenuButtons(Button buttons[], int buttonNumber, RenderWindow & window)
{
	buttons[0].setActive(false);
	buttons[0].setButtonText("TRYBY", 2);
	buttons[1].setButtonText("SURVIVAL", 1);
	buttons[2].setButtonText("WROC", 1);
	for (int i = 0; i < buttonNumber; i++)
	{
		buttons[i].setTextType("files/font.ttf");
		buttons[i].setButtonBackgroundTexture("files/buttonBackground.bmp");
		buttons[i].setbuttonPosition(window, i + 1);
		buttons[i].scaleButton(window);
	}
}
void gameTypeMenu(RenderWindow & window, GameType & gameType)
{
	int gameTypeChoice = -1;		// wybór w wyborze trybu gry
	Menu <3> gameTypeMenu;
	setGameTypeMenuButtons(gameTypeMenu.buttons, gameTypeMenu.getButtonNumber(), window);

	gameTypeChoice = gameTypeMenu.runMenu(window);
	if (gameTypeChoice == 1)
	{
		gameType = survivalType;
	}
}

void changeResolutionSettings(int chosenResolution, Button buttons[])
{
	string resolution[4];
	resolution[0] = "ROZDZIELCZOSC - 1024x600";
	resolution[1] = "ROZDZIELCZOSC - 1280x720";
	resolution[2] = "ROZDZIELCZOSC - 1600x900";
	resolution[3] = "ROZDZIELCZOSC - 1920x1080";
	buttons[1].setButtonText(resolution[chosenResolution], 1);
}
void changeAntialisingSettings(int chosenAntialiasing, Button buttons[])
{
	string antialiasingLevel[5];
	antialiasingLevel[0] = "WYGLADZANIE KRAWEDZI - 0";
	antialiasingLevel[1] = "WYGLADZANIE KRAWEDZI - 2";
	antialiasingLevel[2] = "WYGLADZANIE KRAWEDZI - 4";
	antialiasingLevel[3] = "WYGLADZANIE KRAWEDZI - 8";
	buttons[2].setButtonText(antialiasingLevel[chosenAntialiasing], 1);
}
void changeFullScrreenSettings(bool isFullScreen, Button buttons[])
{
	char fullScreen[25];
	if (isFullScreen)
		sprintf_s(fullScreen, "FULLSCREEN - TAK");
	else
		sprintf_s(fullScreen, "FULLSCREEN - NIE");
	buttons[3].setButtonText(fullScreen, 1);
}
void setSettingsButtons(Button buttons[], int buttonNumber, RenderWindow & window, bool isFullScreen)
{
	char resolution[28];
	if(window.getSize().x == 1024 || window.getSize().x == VideoMode::getDesktopMode().width)
		sprintf_s(resolution, "ROZDZIELCZOSC - %ix%i", window.getSize().x, window.getSize().y);
	else sprintf_s(resolution, "ROZDZIELCZOSC - %ix%i", window.getSize().x+1, window.getSize().y);
	char antialiasing[25];
	sprintf_s(antialiasing, "WYGLADZANIE KRAWEDZI - %i", window.getSettings().antialiasingLevel);

	char fullScreen[25];
	if (isFullScreen)
		sprintf_s(fullScreen, "FULLSCREEN - TAK");
	else
		sprintf_s(fullScreen, "FULLSCREEN - NIE");

	buttons[0].setActive(false);
	buttons[0].setButtonText("USTAWIENIA", 2);
	buttons[1].setButtonText(resolution, 1);
	buttons[2].setButtonText(antialiasing, 1);
	buttons[3].setButtonText(fullScreen, 1);
	buttons[4].setButtonText("WROC", 1);
	for (int i = 0; i < buttonNumber; i++)
	{
		buttons[i].setTextType("files/font.ttf");
		buttons[i].setButtonBackgroundTexture("files/buttonBackground.bmp");
		buttons[i].setbuttonPosition(window, i + 1);
		buttons[i].scaleButton(window);
	}
}
void runSettingsMenu(RenderWindow & window)
{
	Menu <5> settingsMenu;
	Vector2f resolution[4];
	int antialiasingLevel[5];
	resolution[0].x = 1023; resolution[0].y = 600;
	resolution[1].x = 1279; resolution[1].y = 720;
	resolution[2].x = 1599; resolution[2].y = 900;
	resolution[3].x = 1919; resolution[3].y = 1080;
	antialiasingLevel[0] = 0;
	antialiasingLevel[1] = 2;
	antialiasingLevel[2] = 4;
	antialiasingLevel[3] = 8;

	int settingsChoice = -1;
	int chosenResolution;
	int chosenAntialiasing;
	int style;						// czy fullscreen, czy closed - style okna
									// nadanie poprawnej poczaktowej wartosci ustawieniom w menu

	for (int i = 0; i < 4; i++)
	{
		if (resolution[i].x + 1 == window.getSize().x || resolution[i].x == window.getSize().x) chosenResolution = i;
		if (antialiasingLevel[i] == window.getSettings().antialiasingLevel) chosenAntialiasing = i;
	}
	if (window.getSize().x == VideoMode::getDesktopMode().width && window.getSize().y == VideoMode::getDesktopMode().height)
		settingsMenu.isFullScreen = 1;

	setSettingsButtons(settingsMenu.buttons, settingsMenu.getButtonNumber(), window, settingsMenu.isFullScreen);

	// osbluga wyborów
	while (settingsChoice != 4)
	{

		settingsChoice = settingsMenu.runMenu(window);
		if (settingsChoice == 1)
		{
			chosenResolution++;
			if (chosenResolution > 3) chosenResolution = 0;
			changeResolutionSettings(chosenResolution, settingsMenu.buttons);
		}
		else if (settingsChoice == 2)
		{
			chosenAntialiasing++;
			if (chosenAntialiasing > 3) chosenAntialiasing = 0;
			changeAntialisingSettings(chosenAntialiasing, settingsMenu.buttons);
		}
		else if (settingsChoice == 3)
		{
			if (settingsMenu.isFullScreen) settingsMenu.isFullScreen = 0;
			else settingsMenu.isFullScreen = 1;
			changeFullScrreenSettings(settingsMenu.isFullScreen, settingsMenu.buttons);
		}
	}

	if (settingsMenu.isFullScreen) style = 8;	// fullscreen
	else style = 4;								// closed
	window.create(VideoMode(resolution[chosenResolution].x, resolution[chosenResolution].y), "Zombie Defender", style, ContextSettings(0, 0, antialiasingLevel[chosenAntialiasing]));
}

void runMenu(RenderWindow & window, GameType & gameType)
{
	int mainChoice = -1;			// wybor w menu g³ównym

	while (mainChoice != 4)
	{
		mainChoice = runMainMenu(window);
		if (mainChoice == 1)
		{
			gameTypeMenu(window, gameType);
			if (gameType != 0) break;
		}
		else if (mainChoice == 3)
		{
			runSettingsMenu(window);
		}
	}
	if (mainChoice == 4) window.close();
}

int main()
{
	const int screenWidth = 1024;
	const int screenHeight = 600;
	RenderWindow window(VideoMode(screenWidth, screenHeight), "Zombie Defence", Style::Close);

	GameType gameType;		// jaki tryb gry
	Game * game = NULL;
	while (window.isOpen())
	{
		Survival *survival = new Survival;
		gameType = noType;
		runMenu(window, gameType);
		if (gameType == survivalType)
			game = survival;

		if (gameType != noType)
			game->run(window);

		delete survival;
	}


	return 0;
}