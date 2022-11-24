#include "Player.hpp"

Player::Player(const sf::Texture& texture) :
	AnimatedSpriteEntity(texture, PLAYER_ANIM_POS)
{
	this->spriteEntity.setScale(2, 2);
	this->nextAnimationSprite();
}

void Player::setCoords(int x, int y)
{
	x = 0;
	y = 0;
	this->setSpritePosition(x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void Player::moveRight()
{
	x += 1;
	this->moveSprite(1 * SPRITE_SIZE, 0);
}

void Player::moveLeft()
{
	x -= 1;
	this->moveSprite(-1 * SPRITE_SIZE, 0);
}

void Player::moveUp()
{
	y -= 1;
	this->moveSprite(0, -1 * SPRITE_SIZE);
}

void Player::moveDown()
{
	y += 2;
	this->moveSprite(0, 1 * SPRITE_SIZE);
}