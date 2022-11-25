#pragma once

#include "Pokemon.hpp"
#include <vector>

typedef std::tuple<Pokemon*, int> tpi;
bool sorttuple(const tpi& a, const tpi& b)
{
	return (std::get<1>(a) < std::get<1>(b));
}

class Combat
{
public:
	Combat(Pokemon* ally, Pokemon* enemy);
	Combat(std::vector<Pokemon*> allies, std::vector<Pokemon*> enemies);
	void init();
	bool start();

private:
	std::vector<Pokemon*> allies;
	std::vector<Pokemon*> enemies;
	std::vector<tpi> roundPoints;
	Pokemon* getNextActive();
	void sortRoundPoints();
};

