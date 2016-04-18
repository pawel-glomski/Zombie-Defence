#include "Weapons.h"


void Weapons::setWeaponPicture(RenderWindow & window)
{
	weaponSprite.setTexture(weaponPicture);
	weaponSprite.setScale(window.getSize().x/ 15.0/weaponPicture.getSize().x, window.getSize().y / 20.0 / weaponPicture.getSize().y);
	weaponSprite.setPosition(Vector2f(window.getSize().x - window.getSize().x / 5, window.getSize().y - window.getSize().y / 10));
}

Sprite Weapons::getWeaponPicture()
{
	return weaponSprite;
}

int Weapons::getAmmo()
{
	return currentAmmo;
}

void Weapons::drawBullets(RenderWindow & window)
{
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bulletShape.setPosition(bullets[i].getProjectilePosition());
		window.draw(bulletShape);
	}
}


void Weapons::shoot(Vector2f charPosition, RenderWindow & window)
{
	if (currentAmmo > 0 && !reloading)
	{
		if (Mouse::isButtonPressed(Mouse::Left) && !shooted)
		{
			Projectiles bullet(charPosition, window);
			bullets.push_back(bullet);
			shooted = true;
			currentAmmo--;
			shootSound.play();
		}
		else if (!Mouse::isButtonPressed(Mouse::Left))
		{
			shooted = false;
			fireTimer = milliseconds(0);
		}
		else
		{
			fireTimer += fireClock.getElapsedTime();
			if (fireTimer >= fireSpeed)
			{
				fireTimer = seconds(0);
				shooted = false;
			}
		}
	}
	fireClock.restart();

}

void Weapons::reload()
{
	if (currentAmmo == 0 || (Keyboard::isKeyPressed(Keyboard::R) && currentAmmo != maxAmmo))
		reloading = true;

	if (reloading)
	{
		if(reloadSound.getStatus() == Sound::Stopped)
			reloadSound.play();
		if (reloadClock.getElapsedTime() >= reloadingTime)
		{
			reloading = false;
			currentAmmo = maxAmmo;
		}
	}
	else reloadClock.restart();
}

bool Weapons::detectedHit(Projectiles & projectile, Enemies & enemies, Vector2f charPosition)
{

	for (int i = 0; i < enemies.normalZombies.size(); i++)
	{
		if (enemies.normalZombies[i].getWalkingSprite().getGlobalBounds().contains(projectile.getProjectilePosition()))
		{
			int randomDamage = rand() % (dmg.max - dmg.min) + dmg.min;

			enemies.normalZombies[i].takeDamage(randomDamage);
			gettingHitSound.play();
			enemies.normalZombies[i].knockBackOnHit(charPosition);
			return true;
		}
	}
	return false;
}

void Weapons::manageProjectiles(Enemies & enemies, RenderWindow & window, Vector2f charPosition)
{
	if (!bullets.empty())
	{
		for (int i = 0; i < bullets.size(); i++)
		{
			bullets[i].fly();
			if (detectedHit(bullets[i], enemies, charPosition)
				|| (bullets[i].getProjectilePosition().x < charPosition.x - window.getSize().x / 2
				|| bullets[i].getProjectilePosition().y < charPosition.y - window.getSize().y / 2
				|| bullets[i].getProjectilePosition().x > charPosition.x + window.getSize().x / 2
				|| bullets[i].getProjectilePosition().y > charPosition.y + window.getSize().y / 2))
			{
				bullets.erase(bullets.begin() + i);
			}
		}
	}
}

Weapons::Weapons()
{
	reloading = false;
	shooted = false;
	fireTimer = seconds(0);
	gettingHitBuffer.loadFromFile("files/ZombieGotHitSound.wav");
	gettingHitSound.setBuffer(gettingHitBuffer);
	bulletShape.setSize(Vector2f(1, 1));
	bulletShape.setFillColor(Color::White);

	srand(time(NULL));	// do randomowego dmg
}


Weapons::~Weapons()
{
}
