#pragma once

#include "Pokemon.hpp"
#include "Types.hpp"
#include <vector>

// Base abstract class
class Ability
{
public:
	Ability(std::string name, int power, Type type);
	// GET METHODS
	std::string getName() { return this->name; };
	int getPower() { return this->power; };
	Type getType() { return this->type; };

	void resolve(Pokemon* caster, Pokemon* target);
protected:
	std::string name;
	int power;
	Type type;
};