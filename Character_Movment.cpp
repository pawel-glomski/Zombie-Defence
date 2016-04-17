#include "Character_Movment.h"

void Character_Movment::setMovmentMapSize(Vector2i mapSize)
{
	this->mapSize = mapSize;
}

void Character_Movment::move(View & view, int blockSize, int & charX, int & charY, float & charSpeed)
{
		if (Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S) && (charY - 1 >= 1 || (charY-1 < 1 && yFrameMoved < blockSize - blockSize / WALKING_SMOOTHNESS / 2.0 && yFrameMoved != 0 ) && !Keyboard::isKeyPressed(Keyboard::S)))
		{
			yTime += clock.getElapsedTime();
			animations.walking();
			if (yTime >= milliseconds(1000.0 / (charSpeed * charSpeed)))
			{
				yTime = milliseconds(0);
				view.move(0, -blockSize / WALKING_SMOOTHNESS);
				yFrameMoved += blockSize / WALKING_SMOOTHNESS;
				animations.setSpritePosition(view.getCenter());
			}
			if (yFrameMoved >= blockSize - blockSize / WALKING_SMOOTHNESS /2.0)
			{
				yFrameMoved = 0;
				charY -= 1;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::S) && !Keyboard::isKeyPressed(Keyboard::W) && (charY + 1 <= mapSize.y-2 || (charY + 1 > mapSize.y-2 && yFrameMoved > -blockSize + blockSize / WALKING_SMOOTHNESS / 2.0 && yFrameMoved != 0) && !Keyboard::isKeyPressed(Keyboard::W)))
		{
			yTime += clock.getElapsedTime();
			animations.walking();
			if (yTime >= milliseconds(1000.0 / (charSpeed * charSpeed)))
			{
				yTime = milliseconds(0);
				view.move(0, blockSize / WALKING_SMOOTHNESS);
				yFrameMoved -= blockSize / WALKING_SMOOTHNESS;
				animations.setSpritePosition(view.getCenter());
			}
			if (yFrameMoved <= -blockSize + blockSize / WALKING_SMOOTHNESS / 2.0)
			{
				yFrameMoved = 0;
				charY += 1;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) && (charX - 1 >= 1 || (charX - 1 < 1 && xFrameMoved < blockSize - blockSize / WALKING_SMOOTHNESS / 2.0 && xFrameMoved != 0) && !Keyboard::isKeyPressed(Keyboard::D)))
		{
			xTime += clock.getElapsedTime();
			animations.walking();
			if (xTime >= milliseconds(1000.0 / (charSpeed * charSpeed)))
			{
				xTime = milliseconds(0);
				view.move(-blockSize / WALKING_SMOOTHNESS, 0);
				xFrameMoved += blockSize / WALKING_SMOOTHNESS;
				animations.setSpritePosition(view.getCenter());
			}
			if (xFrameMoved >= blockSize - blockSize / WALKING_SMOOTHNESS / 2.0)
			{
				xFrameMoved = 0;
				charX -= 1;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A) && (charX + 1 <= mapSize.x-2 || (charX + 1 > mapSize.x-2 && xFrameMoved > -blockSize + blockSize / WALKING_SMOOTHNESS / 2.0 && xFrameMoved != 0) && !Keyboard::isKeyPressed(Keyboard::A)))
		{
			xTime += clock.getElapsedTime();
			animations.walking();
			if (xTime >= milliseconds(1000.0 / (charSpeed * charSpeed)))
			{
				xTime = milliseconds(0);
				view.move(blockSize / WALKING_SMOOTHNESS, 0);
				xFrameMoved -= blockSize / WALKING_SMOOTHNESS;
				animations.setSpritePosition(view.getCenter());
			}
			if (xFrameMoved <= -blockSize + blockSize / WALKING_SMOOTHNESS / 2.0)
			{
				xFrameMoved = 0;
				charX += 1;
			}
		}
		if(!Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S) && !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D))
		{
			animations.standing();
		}
		if (Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::S) && !Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A))
		{
			moveSoundTimer += clock.getElapsedTime();
			if (moveSoundTimer >= milliseconds(250) && !whichSound)
			{
				stepSound1.play();
				whichSound = true;
			}
			if (moveSoundTimer >= milliseconds(500) && whichSound)
			{
				whichSound = false;
				stepSound2.play();
				stepSound1.stop();
				moveSoundTimer = seconds(0);
			}
		}
	clock.restart();
}

void Character_Movment::lookAround(RenderWindow & window)
{
	float angle;
	if (Mouse::getPosition(window).x > window.getSize().x / 2.0 && Mouse::getPosition(window).y > window.getSize().y/2.0)	// prawa dolna æwiartka
	{
		angle = atan(abs((float)Mouse::getPosition(window).y - window.getSize().y / 2.0) / abs((float)Mouse::getPosition(window).x - window.getSize().x / 2.0)) * 180 / 3.14159265358979323846;
		animations.setSpriteRotation(angle);
	}
	else if (Mouse::getPosition(window).x < window.getSize().x / 2.0 && Mouse::getPosition(window).y > window.getSize().y / 2.0)	// lewa dolna æwiartka
	{
		angle = atan(abs((float)Mouse::getPosition(window).x - window.getSize().x / 2.0) / abs((float)Mouse::getPosition(window).y - window.getSize().y / 2.0)) * 180 / 3.14159265358979323846;
		animations.setSpriteRotation(90 + angle);
	}
	else if (Mouse::getPosition(window).x > window.getSize().x / 2.0 && Mouse::getPosition(window).y < window.getSize().y / 2.0)	// prawa gorna æwiartka
	{
		angle = atan(abs((float)Mouse::getPosition(window).y - window.getSize().y / 2.0) / abs((float)Mouse::getPosition(window).x - window.getSize().x / 2.0)) * 180 / 3.14159265358979323846;
		animations.setSpriteRotation(-angle);
	}
	else if (Mouse::getPosition(window).x < window.getSize().x / 2.0 && Mouse::getPosition(window).y < window.getSize().y / 2.0)	// lewa gorna æwiartka
	{
		angle = atan(abs((float)Mouse::getPosition(window).x - window.getSize().x / 2.0) / abs((float)Mouse::getPosition(window).y - window.getSize().y / 2.0)) * 180 / 3.14159265358979323846;
		animations.setSpriteRotation(-90 - angle);
	}
}

Character_Movment::Character_Movment()
{
	xFrameMoved = 0.0;
	yFrameMoved = 0.0;
	xTime = milliseconds(0);
	yTime = milliseconds(0);

	whichSound = false;

	stepSoundBuffer1.loadFromFile("files/WalkingSound1.wav");
	stepSound1.setBuffer(stepSoundBuffer1);
	stepSoundBuffer2.loadFromFile("files/WalkingSound2.wav");
	stepSound2.setBuffer(stepSoundBuffer2);
}


Character_Movment::~Character_Movment()
{
}
