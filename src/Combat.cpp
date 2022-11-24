#include "Combat.hpp"

Combat::Combat(Pokemon* ally, Pokemon* enemy)
{
	this->allies.push_back(ally);
	this->enemies.push_back(enemy);
}

Combat::Combat(std::vector<Pokemon*> allies, std::vector<Pokemon*> enemies)
{
	this->allies = allies;
	this->enemies = enemies;
}