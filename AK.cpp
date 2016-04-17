#include "AK.h"



AK::AK()
{
	dmg = 50;
	maxAmmo = 30;
	currentAmmo = maxAmmo;
	reloadingTime = seconds(1.5);
	fireSpeed = milliseconds(100);

	weaponPicture.loadFromFile("files/AK.png");
	shootSoundBuffer.loadFromFile("files/AKShootSound.wav");
	shootSound.setBuffer(shootSoundBuffer);
	reloadSoundBuffer.loadFromFile("files/AKReloadSound.wav");
	reloadSound.setBuffer(reloadSoundBuffer);
}


AK::~AK()
{
}
