#include "../include/Ability.hpp"

// Resolve an attack cast by a Pokemon to deal damage to another
void Attack::resolve(Pokemon* caster, Pokemon* target)
{
	// Formula adapted from the original pokemon game gen 1
	// See: https://bulbapedia.bulbagarden.net/wiki/Damage
	float finalDamages = (
		((3.0f * (*caster).getLevel() / 2.0f + 2.0f) *
		(*caster).getAtk() / (*target).getDef() / 40.0f + 2.0f) *
		((*caster).getType() == this->type ? 1.5f : 1.0f) *
		getMultiplier(this->type, (*target).getType()) *
		(0.85f + rand() * 0.15f)
	);

	// TODO: Add animations and damage dealt on screen
	
	(*target).remHp((int)finalDamages);
}

/// Here are the definitions of Pokemon's methods that use Ability

// Returns the Pokemon's ability list
std::array<Ability*, 4> Pokemon::getAbilities()
{
	return this->abilities;
}

// Pokemon: Replace a known ability by a new one
void Pokemon::learn(Ability* a, int position)
{
	std::cout << this->name << " learned " << (*a).getName() << "." << std::endl;
}

// Pokemon: Use an ability
void Pokemon::use(int aNum, std::vector<Pokemon> targets)
{
	Ability* a = this->abilities[aNum];
	std::cout << this->name << " used " << (*a).getName() << "." << std::endl;
}