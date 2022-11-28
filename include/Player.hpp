#pragma once

#include "Pokemon.hpp"
#include "AnimatedEntity.hpp"
#include <SFML/Graphics.hpp>
#include <array>
#include "Const.h"

enum Direction
{
	South,
	North,
	East,
	West
};

class Player : public AnimatedEntity
{
public:
	Player(const sf::Texture& texture);
	
	// Player position
	void moveOnMap(int x, int y);
	void moveOnMap(sf::Vector2f);
	void setPositionOnMap(sf::Vector2f);
	sf::Vector2f getPositionOnMap() const;
	bool isOnATile() const;
	
	// Player direction and movement
	void setFacing(Direction dir, bool moove = false);
	Direction getFacing() const;
	void stopMoving();
	bool isMoving() const;
	
private:
	sf::Vector2f position; // Position in the map
	Direction direction; // Direction the player is facing
	bool moving = false;
};

