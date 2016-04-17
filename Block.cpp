#include "Block.h"

Block::Block()
{
	blockType = noBlock;
	collision = false;
}


Block::~Block()
{
}

void Block::setBlockTexture(char textureNumber)
{
	blockType = textureNumber;
}

void Block::setCollison(bool collision)
{
	this->collision = collision;
}

char Block::getBlockType()
{
	return blockType;
}

bool Block::getCollsion()
{
	return collision;
}
