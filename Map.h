#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Block.h"

#define VISION_RANGE 30.0

using namespace sf;

template < int mapXsize, int mapYsize >
class Map
{
	Texture blockTexture[2];
	Sprite sprite;
	int blockSize;			// wiekosc blokow w pikselach
	int xNumber;			// maksymalna ilosc blokow wyswietlona na ekranie na osi X
public:	
	const float visionRange = VISION_RANGE;
	Block map[mapYsize][mapXsize];

	void setMap(RenderWindow & window);
	void drawMap(RenderWindow & window, int characterX, int characterY);
	Vector2i getMapSize();
	Map();
	~Map();

};

template<int mapXsize, int mapYsize>
void Map<mapXsize, mapYsize>::setMap(RenderWindow & window)								// setMap
{
	sprite.setOrigin(blockTexture[0].getSize().x/2.0,blockTexture[0].getSize().y/2.0);
	sprite.setScale(window.getSize().y/ visionRange /blockTexture[0].getSize().x, window.getSize().y/ visionRange / blockTexture[0].getSize().y);	
	map[mapYsize / 2][mapXsize / 2].setBlockTexture(wall);

	blockSize = window.getSize().y / visionRange;
	xNumber = window.getSize().x / blockSize;	// ilosc blokow mieszczacych sie na ekranie na osi X
	
}

template<int mapXsize, int mapYsize>
void Map<mapXsize, mapYsize>::drawMap(RenderWindow & window, int characterX, int characterY)							// drawMap
{
	int n = characterY + visionRange/2 + 2;
	int k = characterX + xNumber / 2 + 2;
	for (int i = characterY - visionRange/2; i <n ; i++)
	{
		for (int j = characterX - xNumber / 2 - 1; j < k; j++)
		{
			if (j <= mapXsize - 1 && j >= 0 && i <= mapYsize - 1 && i >= 0)
			{
				if (map[i][j].getBlockType() != noBlock)
				{
					sprite.setPosition(j*blockSize, i*blockSize);
					if (map[i][j].getBlockType() == wall)
					{
						sprite.setTexture(blockTexture[wall]);
					}
					window.draw(sprite);
				}
			}
		}
	}
}

template<int mapXsize, int mapYsize>
Vector2i Map<mapXsize, mapYsize>::getMapSize()					// getMapSize
{
	return Vector2i(mapXsize,mapYsize);
}

template<int mapXsize, int mapYsize>
Map<mapXsize, mapYsize>::Map()									// Map
{
	blockTexture[0].loadFromFile("files/BlockTexture0.bmp");
	blockTexture[1].loadFromFile("files/BlockTexture1.bmp");
	for (int i = 0; i < mapYsize; i++)
	{
		map[i][0].setBlockTexture(wall);
		map[i][mapXsize-1].setBlockTexture(wall);
		for (int j = 0; j < mapXsize; j++)
		{
			if (i == 0 || i == mapYsize - 1)
				map[i][j].setBlockTexture(wall);
		}
	}
}

template<int mapXsize, int mapYsize>
Map<mapXsize, mapYsize>::~Map()									// ~Map
{
}