#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <vector>
#include "Projectiles.h"
#include "Ai_Manager.h"

using namespace std;
using namespace sf;


struct WeaponDamage
{
	int min;
	int max;
};

class Weapons
{
protected:
	string name;
	int maxAmmo;
	int currentAmmo;
	WeaponDamage dmg;

	bool shooted;	// czy wystrzelono - do kontroli czestotliwosci strzalow

	Texture weaponPicture;
	Sprite weaponSprite;
	RectangleShape bulletShape;

	SoundBuffer shootSoundBuffer;
	Sound shootSound;
	SoundBuffer reloadSoundBuffer;
	Sound reloadSound;
	SoundBuffer gettingHitBuffer;
	Sound gettingHitSound;

	Clock reloadClock;
	Time reloadingTime;		// czas jaki jest potrzebny na przeladowanie broni
	bool reloading;

	Clock fireClock;
	Time fireSpeed;			// okres automatycznego ataku - sta³a
	Time fireTimer;			// do automatycznego ataku

	vector <Projectiles> bullets;

	bool detectedHit(Projectiles & projectile, Enemies & enemies, Vector2f charPosition);

public:
	void setWeaponPicture(RenderWindow & window);
	Sprite getWeaponPicture();
	int getAmmo();
	void drawBullets(RenderWindow & window);

	void shoot(Vector2f charPosition, RenderWindow & window);
	void reload();
	void manageProjectiles(Enemies & enemies, RenderWindow & window, Vector2f charPosition);
	Weapons();
	~Weapons();
};

