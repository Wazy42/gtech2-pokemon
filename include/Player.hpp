#pragma once

#include "AnimatedSpriteEntity.hpp"
#include <SFML/Graphics.hpp>
#include "Const.h"


class Player : public AnimatedSpriteEntity
{
public:
	Player(const sf::Texture& texture);
	void setCoords(float x, float y);
	void faceRight();
	void faceLeft();
	void faceUp();
	void faceDown();
	bool isMoving() { return moving; }
	void setMoving(bool m) { moving = m; }
	void run();

private:
	float x, y;
	int speed;
	bool moving = false;
};

