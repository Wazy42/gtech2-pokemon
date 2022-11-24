#pragma once

#include "Types.hpp"
#include "Pokemon.h"
#include <string>
#include <vector>

// Base abstract class
class Ability
{
public:
	// GET METHODS
	std::string getName() { return this->name; };
	Type getType() { return this->type; };

	virtual void resolve() {};
	void resolve(Pokemon caster, std::vector<Pokemon> targets);
protected:
	std::string name;
	Type type;
};

// Derived classes
class Attack : public Ability
{
public:
	void resolve(Pokemon caster, Pokemon target);
private:
};

class Effect : public Ability
{
public:
	void resolve(Pokemon caster, Pokemon target);
private:
};
