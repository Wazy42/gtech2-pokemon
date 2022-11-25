#include "../include/AnimatedSpriteEntity.hpp"

AnimatedSpriteEntity::AnimatedSpriteEntity(const sf::Texture& texture, std::vector<sf::IntRect> animationSprite) : Entity(texture)
{
	this->actualAnim = 0;
	this->animationSprite = animationSprite;
	if (animationSprite.size() <= 0)
		throw;
}

void AnimatedSpriteEntity::nextFrameSprite()
{
	// Sprite is set to the next frame
	this->spriteEntity.setTextureRect(this->animationSprite[this->actualAnim]);
	// If the actual frame is the last one, the animation restarts
	this->actualAnim = (this->actualAnim + 1) % this->animationSprite.size();
}

// Called each frame
void AnimatedSpriteEntity::runSprite()
{
	// If the frame counter is equal to the interval, the sprite is set to the next frame
	this->frameCounter = (this->frameCounter + 1) % this->intervalAnim;
	if (this->frameCounter == 0)
		this->nextFrameSprite();
}

void AnimatedSpriteEntity::setActualFrame(int frame)
{
	this->actualAnim = frame;
	this->nextFrameSprite();
}