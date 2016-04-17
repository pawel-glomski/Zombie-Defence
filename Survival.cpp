#include "Survival.h"

void Survival::setShopMenuButtons()
{
	shopMenu.buttons[0].setActive(false);
	shopMenu.buttons[0].setButtonText("SKLEP", 2);
	shopMenu.buttons[1].setButtonText("AK - 1500", 1);
	shopMenu.buttons[2].setButtonText("WROC", 1);
	for (int i = 0; i < shopMenu.getButtonNumber(); i++)
	{
		shopMenu.buttons[i].setTextType("files/font.ttf");
		shopMenu.buttons[i].setButtonBackgroundTexture("files/buttonBackground.bmp");
		shopMenu.buttons[i].setbuttonPosition(*window, i + 1);
		shopMenu.buttons[i].scaleButton(*window);
	}
}

void Survival::drawGame(View & guiView, View & gameView)
{
	window->clear();

	window->setView(gameView);

	map.drawMap(*window, character.getX(), character.getY());
	zombieManager.drawDeadZombies(*window);
	zombieManager.drawZombies(*window);
	window->draw(character);
	character.drawProjectiles(*window);



	window->setView(guiView);

	gui.drawGui();

	window->display();
}

void Survival::gameEvents(View & gameView)
{
	character.move(window->getSize().y / map.visionRange, gameView);
	character.lookAround(*window);
	character.attack(*window);
	character.switchWeapon();
	while (window->pollEvent(event))
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			int mainChoice = pauseMenu.runMenu(*window);
			if (mainChoice == 2) isPlaying = false;
		}
	}
}

void Survival::run(RenderWindow & win)
{
	window = &win;
	const float blockSize = window->getSize().y / map.visionRange;

	setPauseButtons();
	setShopMenuButtons();

	character.setCharacter(map.getMapSize().x, map.getMapSize().y, blockSize, *window);

	gui.setGui(*window, character, stage);

	map.setMap(*window);

	zombieManager.setManager(map.getMapSize().x, map.getMapSize().y, blockSize);

	View guiView(Vector2f(window->getSize().x/2,window->getSize().y/2),Vector2f(window->getSize().x,window->getSize().y));

	View gameView(Vector2f(map.getMapSize().x/2* blockSize,map.getMapSize().y/2* blockSize), Vector2f(window->getSize().x, window->getSize().y));

	music.play();

	while (window->isOpen() && isPlaying && character.getHp() > 0)
	{
		if (Mouse::getPosition(*window).x > 0 && Mouse::getPosition(*window).x < window->getSize().x && Mouse::getPosition(*window).y > 0 && Mouse::getPosition(*window).y < window->getSize().y)
		{
			gameEvents(gameView);

			character.getDMG(zombieManager.getEnemies());

			character.manageProjectiles(*window, zombieManager.getEnemies());

			zombieManager.manage(stage, character.getSprite().getPosition(), character.getCash(), killedEnemiesNumber);

			if (killedEnemiesNumber == stage * 10)
			{
				zombieManager.nextStage();
				killedEnemiesNumber = 0;
				stage++;
				int choice = -1;
				while (choice != shopMenu.getButtonNumber() - 1)
				{
					choice = shopMenu.runMenu(*window);
					if (choice == AK_SHOP_ID && character.getCash() >= AK_PRICE && character.getBoughtWeapons().ak == false)
					{
						character.getCash() -= AK_PRICE;
						character.getBoughtWeapons().ak = true;
					}
					
				}
				
			}

			if (isPlaying)
				drawGame(guiView, gameView);
			
		}
	}
	
}


Survival::Survival()
{
	stage = 1;
	isPlaying = true;
	killedEnemiesNumber = 0;
	music.openFromFile("files/Music.ogg");
	music.setLoop(true);
}


Survival::~Survival()
{
}
