#include "../include/Button.h"

Button::Button(const sf::Texture& texture) : Entity(texture)
{
}

void Button::setButtonPosition(int x, int y)
{
	this->setButtonPosition(x, y);
}

sf::Sprite& Button::getButtonSprite()
{
	return this->getSprite();
}

const sf::Sprite& Button::getButtonSprite() const
{
	return this->getSprite();
}
