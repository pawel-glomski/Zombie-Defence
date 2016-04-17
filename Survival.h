#pragma once
#include "Game.h"



class Survival : public Game
{
	enum shopItemsIDs { AK_SHOP_ID = 1 };
	enum shopItemsPrices { AK_PRICE = 1500 };

	Map<50, 50> map;
	Ai_Manager zombieManager;
	Menu <3> shopMenu;
	void setShopMenuButtons();

	int killedEnemiesNumber;

	void drawGame(View & guiView, View & gameView);
	void gameEvents(View & gameView);
public:
	virtual void run(RenderWindow & window);

	Survival();
	~Survival();
};

