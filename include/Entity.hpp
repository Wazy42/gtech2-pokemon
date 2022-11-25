#pragma once

#include "Const.h"
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity(const sf::Texture& texture);

	// Sprite position
	void moveSprite(float x, float y);
	void moveSprite(sf::Vector2f);
	void setSpritePosition(float x, float y);
	void setSpritePosition(sf::Vector2f);
	sf::Vector2f getSpritePosition();

	// Sprite and texture
	sf::Sprite& getSprite();
	void setTexture(const sf::Texture& texture);
	sf::Texture& getTexture();
	
protected:
	sf::Sprite sprite;
	sf::Texture texture;
};