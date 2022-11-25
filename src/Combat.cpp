#include "../include/Combat.hpp"

Combat::Combat(Pokemon* ally, Pokemon* enemy)
{
	this->allies.push_back(ally);
	this->enemies.push_back(enemy);
	this->init();
}

Combat::Combat(std::vector<Pokemon*> allies, std::vector<Pokemon*> enemies)
{
	this->allies = allies;
	this->enemies = enemies;
	this->init();
}

void Combat::init()
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
bool Combat::start()
{
	return true;
}

Pokemon* Combat::getNextActive()
{
	// Sort roundPoints by asc then take the pokemon with the lowest score
	this->sortRoundPoints();
	Pokemon* next = std::get<0>(this->roundPoints[0]);
	// Adding 1000 over the pokemon's speed to their round points
	// This will make pokemon with higher speed to attack more often than other
	std::get<1>(this->roundPoints[0]) += 1000 / (*next).getSpd();

	return next;
}

void Combat::sortRoundPoints()
{
	std::sort(this->roundPoints.begin(), this->roundPoints.end(), sorttuple);
}