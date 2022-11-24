#include "AnimatedSpriteEntity.h"

AnimatedSpriteEntity::AnimatedSpriteEntity(const sf::Texture& texture, std::vector<sf::IntRect> animationPos) : Entity(texture)
{
	this->frameCount = 0;
	this->animationPos = animationPos;
	if (animationPos.size() <= 0)
		throw;
	
	//this->spriteEntity.setTextureRect(this->animationPos[this->frameCount]);
}

void AnimatedSpriteEntity::nextAnimationSprite()
{
	this->spriteEntity.setTextureRect(this->animationPos[this->frameCount]);
	this->frameCount++;

	if (this->frameCount >= this->animationPos.size())
		this->frameCount = 0;

}