#include <string>
#include <vector>
#include "Types.hpp"
#include "Pokemon.h"
#include "Ability.h"

void Attack::resolve(Pokemon caster, Pokemon target)
{
	// Formula adapted from the original pokemon game gen 1
	// See: https://bulbapedia.bulbagarden.net/wiki/Damage
	int finalDamages = (
		((3 * caster.getLevel() / 2 + 2) *
		caster.getAtk() / target.getDef() / 40 + 2) *
		(caster.getType() == this->type ? 1.5 : 1) *
		getMultiplier(this->type, target.getType()) *
		(0.85 + rand() * 0.15)
	);

	// TODO: Add animations and damage dealt on screen

	target.remHp(finalDamages);
}

void Attack::resolve(Pokemon caster, std::vector<Pokemon> targets)
{
	for (Pokemon target : targets)
	{
		this->resolve(caster, target);
	}
}

void Effect::resolve(Pokemon caster, Pokemon target)
{
	// TODO: effects
}

void Effect::resolve(Pokemon caster, std::vector<Pokemon> targets)
{
	for (Pokemon target : targets)
	{
		this->resolve(caster, target);
	}
}
