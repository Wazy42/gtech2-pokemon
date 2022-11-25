#pragma once

#include "SpriteEntity.hpp"

class Button : public Entity
{
public:
	Button(const sf::Texture& texture);
	void setButtonPosition(int x, int y);
};
