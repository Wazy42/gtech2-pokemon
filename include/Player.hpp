#pragma once

#include "AnimatedSpriteEntity.hpp"
#include <SFML/Graphics.hpp>
#include "Const.h"


class Player : public AnimatedSpriteEntity
{
public:
	Player(const sf::Texture& texture);
	void faceRight();
	void faceLeft();
	void faceUp();
	void faceDown();
	bool isMoving() { return moving; }
	void setMoving(bool m) { moving = m; }
	void run();
	void handleKeyPressed(sf::Event event);

private:
	int posX, posY;
	bool moving = false;
};

