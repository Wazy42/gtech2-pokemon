#include "../include/AnimatedEntity.hpp"

AnimatedEntity::AnimatedEntity(const sf::Texture& texture, std::vector<sf::IntRect> framesCoords) : Entity(texture), framesCoords(framesCoords)
{
	this->setCurrentFrame(0);
}

void AnimatedEntity::setFramesCoords(std::vector<sf::IntRect> framesCoords)
{
	this->framesCoords = framesCoords;
}

void AnimatedEntity::gotoNextFrame()
{
	this->currentFrame = (this->currentFrame + 1) % this->framesCoords.size();
	this->sprite.setTextureRect(this->framesCoords[this->currentFrame]);
}

void AnimatedEntity::setCurrentFrame(size_t frame)
{
	this->currentFrame = frame;
	this->sprite.setTextureRect(this->framesCoords[frame]);
}

size_t AnimatedEntity::getCurrentFrame() const
{
	return this->currentFrame;
}