#pragma once

#include "Const.h"
#include <SFML/Graphics.hpp>

class Entity
{
protected:
	sf::Sprite spriteEntity;
	const sf::Texture &textureEntity;

public:
	Entity(const sf::Texture &texture);

	void setSpritePosition(int x, int y);
	void moveSprite(int x, int y);

	sf::Sprite &getSprite();
	const sf::Sprite &getSprite() const;
};