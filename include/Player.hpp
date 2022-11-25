#pragma once

#include "Pokemon.hpp"
#include "AnimatedEntity.hpp"
#include <SFML/Graphics.hpp>
#include <array>
#include "Const.h"

class Player : public AnimatedEntity
{
public:
	Player(const sf::Texture& texture);
	void faceRight();
	void faceLeft();
	void faceUp();
	void faceDown();
	
	void move(sf::Vector2i);
	sf::Vector2i getPos() { return sf::Vector2i(this->posX, this->posY); }
	void setMoving(bool m) { moving = m; }
	bool isMoving() { return moving; }
	void run();
	
	void handleEvents();

private:
	std::array<Pokemon*, 4> team;
	int posX, posY;
	bool moving = false;
	sf::Keyboard::Key buffer = sf::Keyboard::Unknown;
};

