#pragma once

#include "SpriteEntity.hpp"

class Button : public Entity
{
public:
	Button(const sf::Texture& texture);
	void setButtonPosition(int x, int y);
	
	sf::Sprite& getButtonSprite();
	const sf::Sprite& getButtonSprite() const;
};
