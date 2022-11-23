#include <SFML/Graphics.hpp>

#include "SpriteEntity.h"

Entity::Entity(const sf::Texture& texture) : spriteEntity(texture), textureEntity(texture)
{
}

sf::Sprite& Entity::getSprite()
{
	return this->spriteEntity;
}

const sf::Sprite& Entity::getSprite() const {
	return this->spriteEntity;
}