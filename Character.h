#pragma once
#include "Glock.h"
#include "AK.h"
#include "Character_Movment.h"

struct BoughtWeapons
{
	bool ak = 0;
};

class Character : public Drawable
{
	struct charWeapons
	{
		Glock glock;
		AK ak;
	};
	Sprite * spritePointer;
	Texture characterTexture;

	int hp;
	int x;
	int y;
	float speed;
	int cash;

	BoughtWeapons boughtWeapons;

	Weapons * weaponInHand;
	charWeapons weapons;

	Character_Movment movment;

	SoundBuffer loosingHpSoundBuffer;
	Sound loosingHpSound;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:

	int getHp();
	int getAmmo();
	int & getCash();
	void setCharacter(int mapSizeX, int mapSizeY, float blockSize, RenderWindow & window);
	void setWeaponPicture(RenderWindow & window);
	Sprite getWeaponPicture();
	Sprite & getSprite();

	void attack(RenderWindow & window);
	void manageProjectiles(RenderWindow & window, Enemies & enemies);
	void drawProjectiles(RenderWindow & window);
	void switchWeapon();
	void move(int blockSize, View & gameView);
	void lookAround(RenderWindow & window);
	void getDMG(Enemies & enemies);
	BoughtWeapons & getBoughtWeapons();


	int & getX();
	int & getY();
	float  getSpeed();


	Character();
	~Character();
};

