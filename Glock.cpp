#include "Glock.h"

Glock::Glock()
{
	dmg = 25;
	maxAmmo = 20;
	currentAmmo = maxAmmo;
	reloadingTime = seconds(1);
	fireSpeed = milliseconds(500);

	weaponPicture.loadFromFile("files/Glock.png");
	shootSoundBuffer.loadFromFile("files/GlockShootSound.wav");
	shootSound.setBuffer(shootSoundBuffer);
	reloadSoundBuffer.loadFromFile("files/GlockReloadSound.wav");
	reloadSound.setBuffer(reloadSoundBuffer);
}


Glock::~Glock()
{
}
