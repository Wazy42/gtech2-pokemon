#pragma once

#include "AnimatedSpriteEntity.h"
#include <SFML/Graphics.hpp>
#include "Const.h"


class Player : public AnimatedSpriteEntity
{
public:
	Player(const sf::Texture& texture);
	void setCoords(int x, int y);
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

private:
	int x, y;
};

