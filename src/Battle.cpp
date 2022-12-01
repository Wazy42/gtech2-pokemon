#include "../include/Battle.hpp"

Battle::Battle(Pokemon* ally, Pokemon* enemy)
{
	this->ally = ally;
	this->enemy = enemy;
	this->round = 0;
}

// Returns the Pokemon that will play next
Pokemon* Battle::getNextTurn()
{
	if (this->round == 0 && this->enemy->getSpd() > this->ally->getSpd() || this->round % 2 == 1)
	{
		this->round++;
		return this->enemy;
	}
	else
	{
		this->round++;
		return this->ally;
	}
}