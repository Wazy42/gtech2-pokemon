#pragma once

#include "Pokemon.hpp"
#include <vector>
#include <tuple>

typedef std::tuple<Pokemon*, int> tpi;

class Battle
{
public:
	Battle(Pokemon* ally, Pokemon* enemy);
	Battle(std::vector<Pokemon*> allies, std::vector<Pokemon*> enemies);
	void init();
	bool start();
	static bool sorttuple(const tpi& a, const tpi& b);

private:
	std::vector<Pokemon*> allies;
	std::vector<Pokemon*> enemies;
	std::vector<tpi> roundPoints;
	Pokemon* getNextActive();
	void sortRoundPoints();
};

