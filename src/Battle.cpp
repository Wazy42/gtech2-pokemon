#include "../include/Battle.hpp"

Battle::Battle(Pokemon* ally, Pokemon* enemy)
{
	this->allies.push_back(ally);
	this->enemies.push_back(enemy);
	this->init();
}

Battle::Battle(std::vector<Pokemon*> allies, std::vector<Pokemon*> enemies)
{
	this->allies = allies;
	this->enemies = enemies;
	this->init();
}

void Battle::init()
{
	for (Pokemon* p : this->allies)
	{
		this->roundPoints.push_back({ p, 1000/(*p).getSpd() });
	}
	for (Pokemon* p : this->enemies)
	{
		this->roundPoints.push_back({ p, 1000/(*p).getSpd() });
	}
}

// returns true if the player wins, false otherwise
bool Battle::start()
{
	// TODO: Battle!
	return true;
}

Pokemon* Battle::getNextActive()
{
	// Sort roundPoints by asc then take the pokemon with the lowest score
	this->sortRoundPoints();
	Pokemon* next = std::get<0>(this->roundPoints[0]);
	// Adding 1000 over the pokemon's speed to their round points
	// This will make pokemon with higher speed to attack more often than other
	std::get<1>(this->roundPoints[0]) += 1000 / (*next).getSpd();

	return next;
}

void Battle::sortRoundPoints()
{
	std::sort(this->roundPoints.begin(), this->roundPoints.end(), sorttuple);
}

 bool Battle::sorttuple(const tpi& a, const tpi& b)
{
	return std::get<1>(a) < std::get<1>(b);
}