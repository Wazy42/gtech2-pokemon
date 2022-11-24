#include "../include/Pokemon.hpp"

// Add HPs, can not exceed the maximum of HP
void Pokemon::addHp(int v)
{
	std::cout << this->name << " gained " << v << " HP." << std::endl;
	this->hp += v;
	if (this->hp > this->maxHp)
		this->hp = this->maxHp;
}

// Remove HPs, may cause the death of the Pokemon
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


// Bring back the Pokemon to life, and set it's HP to full
void Pokemon::revive()
{
	this->alive = true;
	this->hp = this->maxHp;
}

// Note: The definition of methods that need Ability are in the file "Ability.cpp"