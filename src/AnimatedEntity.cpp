#include "../include/AnimatedEntity.hpp"

AnimatedEntity::AnimatedEntity(const sf::Texture& texture, std::vector<sf::IntRect> animationSprite) : Entity(texture)
{
	this->actualFrame = 0;
	this->animationSprite = animationSprite;
	if (animationSprite.size() <= 0)
		throw;
}

void AnimatedEntity::nextFrameSprite()
{
	// Sprite is set to the next frame
	this->sprite.setTextureRect(this->animationSprite[this->actualFrame]);
	// If the actual frame is the last one, the animation restarts
	this->actualFrame = (this->actualFrame + 1) % this->animationSprite.size();
}

// Called each frame
void AnimatedEntity::runSprite()
{
	// If the frame counter is equal to the interval, the sprite is set to the next frame
	this->frameCounter = (this->frameCounter + 1) % this->intervalBFrames;
	if (this->frameCounter == 0)
		this->nextFrameSprite();
}

void AnimatedEntity::setActualFrame(int frame)
{
	this->actualFrame = frame;
	this->nextFrameSprite();
}