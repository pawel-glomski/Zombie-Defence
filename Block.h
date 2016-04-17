#pragma once
enum blockTypes
{
	noBlock,
	wall
};
class Block
{
	char blockType;	// rodzaj tekstury bloku
	bool collision;	// czy z blokiem mozliwa jest kolizja
public:
	Block();
	~Block();
	void setBlockTexture(char textureNumber);			// zmienia teksture
	void setCollison(bool collision);		// zmienia mo¿liwoœæ kolziji
	
	char getBlockType();
	bool getCollsion();
};

