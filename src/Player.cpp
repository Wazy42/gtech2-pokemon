#include "../include/Player.hpp"

Player::Player(const sf::Texture& texture) : AnimatedEntity(texture, PLAYER_ANIM_COORDS(South))
{
	this->position = sf::Vector2f(0, 0);
	this->direction = South;
	this->moving = false;
	this->setSpritePosition(
		(WINDOW_WIDTH - SPRITE_SIZE * SPRITE_SCALE) / 2, 
		(WINDOW_HEIGHT - SPRITE_SIZE * SPRITE_SCALE) / 2
	);
	this->sprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
}

void Player::moveOnMap(int x, int y)
{
	this->position.x += x;
	this->position.y += y;
}

void Player::moveOnMap(sf::Vector2f pos)
{
	this->position += pos;
}

void Player::setPosition(sf::Vector2f pos)
{
	this->position = pos;
}

sf::Vector2f Player::getPosition() const
{
	return this->position;
}

bool Player::isOnATile() const
{
	return ((int)this->position.x % TILE_SIZE == 0 && (int)this->position.y % TILE_SIZE == 0);
}

void Player::setFacing(Direction dir, bool moove)
{
	this->direction = dir;
	this->moving = moove;
	this->setFramesCoords(PLAYER_ANIM_COORDS(dir));
}

Direction Player::getFacing() const
{
	return this->direction;
}

void Player::stopMoving()
{
	this->moving = false;
}

bool Player::isMoving() const
{
	return this->moving;
}
