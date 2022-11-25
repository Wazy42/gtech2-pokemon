#pragma once

#include "Const.h"
#include <SFML/Graphics.hpp>

enum Direction
{
	Up,
	Down,
	Left,
	Right
};

class Entity
{
protected:
	sf::Sprite sprite;
	const sf::Texture &texture;
	Direction dir;

public:
	Entity(const sf::Texture &texture);

	void setSpritePosition(int x, int y);
	sf::Vector2f getSpritePosition() { return this->sprite.getPosition(); }
	void moveSprite(int x, int y);
	Direction getDirection() { return dir; }

	sf::Sprite &getSprite();
};