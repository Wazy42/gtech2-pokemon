#pragma once

#include "Pokemon.hpp"
#include <vector>

class Combat
{
public:
	Combat(Pokemon* ally, Pokemon* enemy);
	Combat(std::vector<Pokemon*> allies, std::vector<Pokemon*> enemies);
	// TODO: Combat system

private:
	std::vector<Pokemon*> allies;
	std::vector<Pokemon*> enemies;
};

