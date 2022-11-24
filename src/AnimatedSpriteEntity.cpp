#include "../include/AnimatedSpriteEntity.hpp"

AnimatedSpriteEntity::AnimatedSpriteEntity(const sf::Texture& texture, std::vector<sf::IntRect> animationPos) : Entity(texture)
{
	this->actualAnim = 0;
	this->animationSprite = animationPos;
	if (animationPos.size() <= 0)
		throw;
}

void AnimatedSpriteEntity::nextFrameSprite()
{
	this->spriteEntity.setTextureRect(this->animationSprite[this->actualAnim]);
	this->actualAnim++;

	if (this->actualAnim >= this->animationSprite.size())
		this->actualAnim = 0;
}

void AnimatedSpriteEntity::runSprite()
{
	if (this->framCounter >= this->intervalAnim)
	{
		this->nextFrameSprite();
		this->framCounter = 0;
	}
	else
		this->framCounter++;
}

void AnimatedSpriteEntity::setActualFrame(int frame)
{
	this->actualAnim = frame;
}