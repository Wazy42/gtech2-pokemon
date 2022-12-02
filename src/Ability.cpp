#include "../include/Ability.hpp"

Ability::Ability(std::string name, int power, Type type)
{
	this->name = name;
	this->power = power;
	this->type = type;
}

// Resolve an attack cast by a Pokemon to deal damage to another
void Ability::resolve(Pokemon* caster, Pokemon* target)
{
	// Formula adapted from the original pokemon game gen 1
	// See: https://bulbapedia.bulbagarden.net/wiki/Damage
	float finalDamages = (
		((2.0f * caster->getLevel() / 5.0f + 2.0f) *
		this->power * (caster->getAtk() / target->getDef()) / 50.0f + 2.0f) *
		(caster->getType() == this->type ? 1.5f : 1.0f) *
		getMultiplier(this->type, target->getType()) *
		(0.85f + (rand() % 15) / 100)
	);

	// TODO: Add animations and damage dealt on screen
	(*target).remHp((int)finalDamages);
}

/// Here are the definitions of Pokemon's methods that use Ability

// Returns the Pokemon's ability list
std::vector<Ability*> Pokemon::getAbilities()
{
	return this->abilities;
}

// Pokemon: Use an ability
void Pokemon::use(int aNum, Pokemon* target)
{
	Ability* a = this->abilities[aNum];
	a->resolve(this, target);
}