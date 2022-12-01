#pragma once

#include "Pokemon.hpp"

class Battle
{
public:
	Battle(Pokemon* ally, Pokemon* enemy);
	Pokemon* getNextTurn();

private:
	Pokemon* ally;
	Pokemon* enemy;
	int round;
};

