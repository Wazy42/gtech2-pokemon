#include "Pokemon.h"

void Pokemon::addHp(int v)
{
	std::cout << this->name << " gained " << v << " HP." << std::endl;
	this->hp += v;
	if (this->hp > this->maxHp)
		this->hp = this->maxHp;
}

void Pokemon::remHp(int v)
{
	std::cout << this->name << " lost " << v << " HP." << std::endl;
	this->hp -= v;
	if (this->hp <= 0)
	{
		this->hp = 0;
		this->alive = false;
	}
}

void Pokemon::revive()
{
	this->alive = true;
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