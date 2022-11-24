#include <string>
#include <array>
#include <functional>
#include "Types.hpp"
#include "Ability.h"
#include "Pokemon.h"
#include <iostream>

void Pokemon::addHp(int v)
{
	std::cout << this->name << " gained " << v << " HP." << std::endl;
	this->hp += v;
	if (this->hp > this->maxHp)
		this->hp = this->maxHp;
}

// Learn a new ability
void Pokemon::learn(Ability a, int position)
{
	std::cout << this->name << " learned " << a.getName() << "." << std::endl;
}

// Use an ability
void Pokemon::use(int aNum)
{
	Ability* a = this->abilities[aNum];
	std::cout << this->name << " used " << (*a).getName() << "." << std::endl;
}