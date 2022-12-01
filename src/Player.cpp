#include "../include/Player.hpp"

Player::Player(const sf::Texture& texture) : AnimatedEntity(texture, PLAYER_ANIM_COORDS(South))
{
	this->position = sf::Vector2f(0, 0);
	this->direction = South;
	this->moving = false;
	this->setSpritePosition(0, 0);
	this->sprite.setScale(PLAYER_SCALE, PLAYER_SCALE);
}

// Move the player on the map by x and y (movement)
void Player::moveOnMap(float x, float y)
{
	this->position.x = roundf((this->position.x + x) * 100) / 100;
	this->position.y = roundf((this->position.y + y) * 100) / 100;
	this->moveSprite(x * TILE_SIZE, y * TILE_SIZE);
}

void Player::moveOnMap(sf::Vector2f pos)
{
	this->moveOnMap(pos.x, pos.y);
}

// Set the player coordinates on the map (teleportation)
void Player::setPositionOnMap(sf::Vector2f pos)
{
	this->position = pos;
	this->setSpritePosition((float)(pos.x * TILE_SIZE - PLAYER_SCALE), (float)(pos.y * TILE_SIZE));
}

// Get position of the player on the map
sf::Vector2f Player::getPositionOnMap() const
{
	return this->position;
}

// True if the player is on the center of a tile
bool Player::isOnATile() const
{
	return (this->position.x == roundf(this->position.x) && this->position.y == roundf(this->position.y));
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
	this->position.x = floorf(this->position.x);
	this->position.y = floorf(this->position.y);
}

// Returns if the player is moving or not
bool Player::isMoving() const
{
	return this->moving;
}

// Add a pokemon to the player team
void Player::addPokemon(Pokemon* pokemon)
{
	this->team.push_back(pokemon);
}

// Get the player team
std::vector<Pokemon*> Player::getTeam()
{
	return this->team;
}

// Get the highest level pokemon in the team
Pokemon* Player::getHighestLvlPokemon()
{
	Pokemon* highestLvl = this->team[0];
	for (int i = 1; i < this->team.size(); i++)
	{
		if (this->team[i]->getLevel() > highestLvl->getLevel())
			highestLvl = this->team[i];
	}
	return highestLvl;
}