#pragma once

#include <SFML/Graphics.hpp>
#include "Pokemon.hpp"
#include "Entity.hpp"

class Battle
{
public:
	Battle(Pokemon* ally, Pokemon* enemy);

	// Battle
	Pokemon* getNextTurn();
	Pokemon* getAlly() { return this->ally; };
	Pokemon* getEnemy() { return this->enemy; };
	

private:
	Pokemon* ally;
	Pokemon* enemy;
	int round;
};

