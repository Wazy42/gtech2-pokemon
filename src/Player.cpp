#include "../include/Player.hpp"

Player::Player(const sf::Texture& texture) :
	AnimatedSpriteEntity(texture, PLAYER_ANIM_SPRITE_DOWN)
{
	this->spriteEntity.setScale(2, 2);
	this->nextFrameSprite();
	speed = 0.25;
}

void Player::setCoords(float x, float y)
{
	x = 0;
	y = 0;
	this->setSpritePosition(x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void Player::faceRight()
{
	this->dir = Direction::Right;
	this->animationSprite = PLAYER_ANIM_SPRITE_RIGHT;
}

void Player::faceLeft()
{
	this->dir = Direction::Left;
	this->animationSprite = PLAYER_ANIM_SPRITE_LEFT;
}

void Player::faceUp()
{
	this->dir = Direction::Up;
	this->animationSprite = PLAYER_ANIM_SPRITE_UP;
}

void Player::faceDown()
{
	this->dir = Direction::Down;
	this->animationSprite = PLAYER_ANIM_SPRITE_DOWN;
}

void Player::run()
{
	if (actualAnim + 1 >= this->animationSprite.size())
	{
		this->moving = false;
		this->setActualFrame(0);
	}
		
	this->runSprite();
}