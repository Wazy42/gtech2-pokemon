#include "../include/Player.hpp"

Player::Player(const sf::Texture& texture) : AnimatedEntity(texture, PLAYER_ANIM_COORDS(South))
{
	this->position = sf::Vector2f(0, 0);
	this->direction = South;
	this->moving = false;
	this->setSpritePosition(
		(WINDOW_WIDTH - PLAYER_SIZE * PLAYER_SCALE) / 2, 
		(WINDOW_HEIGHT - PLAYER_SIZE * PLAYER_SCALE) / 2
	);
	this->sprite.setScale(PLAYER_SCALE, PLAYER_SCALE);
}

// Move the player on the map by x and y (movement)
void Player::moveOnMap(int x, int y)
{
	this->position.x += x;
	this->position.y += y;
}

void Player::moveOnMap(sf::Vector2f pos)
{
	this->position += pos;
}

// Set the player coordinates on the map (teleportation)
void Player::setPositionOnMap(sf::Vector2f pos)
{
	this->position = pos;
}

// Get position of the player on the map
sf::Vector2f Player::getPositionOnMap() const
{
	return this->position;
}

// True if the player is on the center of a tile
bool Player::isOnATile() const
{
	return ((int)this->position.x % TILE_SIZE == 0 && (int)this->position.y % TILE_SIZE == 0);
}

// Set the facing of the player (affect his sprite)
void Player::setFacing(Direction dir, bool moove)
{
	this->direction = dir;
	this->moving = moove;
	this->setFramesCoords(PLAYER_ANIM_COORDS(dir));
}

// Get the direction the player is facing
Direction Player::getFacing() const
{
	return this->direction;
}

// Stop the movement
void Player::stopMoving()
{
	this->moving = false;
}

// Returns if the player is moving or not
bool Player::isMoving() const
{
	return this->moving;
}
