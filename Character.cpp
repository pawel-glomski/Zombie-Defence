#include "Character.h"

void Character::attack(RenderWindow & window)
{
	weaponInHand->shoot(Vector2f(movment.getWalkingSprite().getPosition()), window);
	weaponInHand->reload();
}

void Character::manageProjectiles(RenderWindow & window, Enemies & enemies)
{
	weapons.glock.manageProjectiles(enemies, window, movment.getWalkingSprite().getPosition());
	weapons.ak.manageProjectiles(enemies, window, movment.getWalkingSprite().getPosition());
}

void Character::drawProjectiles(RenderWindow & window)
{
	weaponInHand->drawBullets(window);
}

void Character::switchWeapon()
{
	if (Keyboard::isKeyPressed(Keyboard::Num1))
	{
		weaponInHand = &weapons.glock;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Num2) && boughtWeapons.ak)
	{
		weaponInHand = &weapons.ak;
	}
}

void Character::move(int blockSize, View & gameView)
{
	movment.move(gameView, blockSize, x, y, speed);
}

void Character::lookAround(RenderWindow & window)
{
	movment.lookAround(window);
}

void Character::getDMG(Enemies & enemies)
{
	for (size_t i = 0; i < enemies.normalZombies.size(); i++)
	{
		if (enemies.normalZombies[i].getWalkingSprite().getGlobalBounds().intersects(movment.getWalkingSprite().getGlobalBounds()))
		{
			int damage =  enemies.normalZombies[i].getDamage();
			hp -= damage;
			if(damage != 0)
				loosingHpSound.play();
		}
	}
}

BoughtWeapons & Character::getBoughtWeapons()
{
	return boughtWeapons;
}

void Character::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*spritePointer);
}

int Character::getHp()
{
	return hp;
}

int Character::getAmmo()
{
	return weaponInHand->getAmmo();
}

int & Character::getCash()
{
	return cash;
}

void Character::setCharacter(int mapSizeX, int mapSizeY, float blockSize, RenderWindow & window)
{
	x = mapSizeX/2;
	y = mapSizeY/2;
	movment.setSpritePosition(Vector2f(x*blockSize, y*blockSize));
	movment.setWalkingTexture(characterTexture, blockSize);
	movment.setMovmentMapSize(Vector2i(mapSizeX, mapSizeY));
	weapons.glock.setWeaponPicture(window);
	weapons.ak.setWeaponPicture(window);
}

void Character::setWeaponPicture(RenderWindow & window)
{
	weaponInHand->setWeaponPicture(window);
}

Sprite Character::getWeaponPicture()
{
	return weaponInHand->getWeaponPicture();
}

Sprite & Character::getSprite()
{
	return movment.getWalkingSprite();
}

int & Character::getX()
{
	return x;
}

int & Character::getY()
{
	return y;
}

float  Character::getSpeed()
{
	return speed;
}


Character::Character()
{
	hp = 25;
	speed = 10.0;
	weaponInHand = &weapons.glock;
	cash = 0;
	characterTexture.loadFromFile("files/charWalkingAnimation.png");
	loosingHpSoundBuffer.loadFromFile("files/LoosingHpSound.wav");
	loosingHpSound.setBuffer(loosingHpSoundBuffer);
	spritePointer = &movment.getWalkingSprite();

} 


Character::~Character()
{
}
