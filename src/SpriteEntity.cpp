#include "SpriteEntity.hpp"

Entity::Entity(const sf::Texture& texture) : spriteEntity(texture), textureEntity(texture)
{
}

void Entity::setSpritePosition(int x, int y)
{
	this->spriteEntity.setPosition(sf::Vector2f(x, y));
}

void Entity::moveSprite(int x, int y)
{
	this->spriteEntity.move(sf::Vector2f(x, y));
}

sf::Sprite& Entity::getSprite()
{
	return this->spriteEntity;
}

const sf::Sprite& Entity::getSprite() const {
	return this->spriteEntity;
}