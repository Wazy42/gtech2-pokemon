#pragma once

class Ability
{
public:
	std::string getName() { return this->name; };
	Type getType() { return this->type; };
protected:
	std::string name;
	Type type;
};

class Attack : public Ability
{
public:
	void resolve(Pokemon caster, Pokemon target);
	void resolve(Pokemon caster, std::vector<Pokemon> targets);
private:
};

class Effect : public Ability
{
public:
	void resolve(Pokemon caster, Pokemon target);
	void resolve(Pokemon caster, std::vector<Pokemon> targets);
private:
};
