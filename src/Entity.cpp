#include "../include/Entity.hpp"

Entity::Entity(const sf::Texture& texture) : sprite(texture), texture(texture)
{
}

void Entity::setSpritePosition(int x, int y)
{
	this->sprite.setPosition(sf::Vector2f((float)x, (float)y));
}

void Entity::moveSprite(int x, int y)
{
	this->sprite.move(sf::Vector2f((float)x, (float)y));
}

sf::Sprite& Entity::getSprite()
{
	return this->sprite;
}