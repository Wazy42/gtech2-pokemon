#pragma once

#include "Types.hpp"
#include "AnimatedEntity.hpp"
#include <string>
#include <array>
#include <iostream>
#include <vector>

// Forward declaration (because Ability and Pokemon are dependent on each other)
class Ability;

class Pokemon : public AnimatedEntity
{
public:
	// GET STATS
	std::string getName() { return this->name; };
	Type getType() { return this->type; };
	int getLevel() { return this->level; };
	int getHp() { return this->hp; };
	int getMaxHp() { return this->maxHp; };
	int getAtk() { return this->atk; };
	int getDef() { return this->def; };
	int getSpd() { return this->spd; };
	// SET STATS
	void changeName(std::string n) { this->name = n; };
	void levelUp() { this->level += 1; };
	void addHp(int v);
	void remHp(int v);
	void setMaxHp(int v) { this->maxHp = v; };
	void setDef(int v) { this->def = v; };
	void setSpd(int v) { this->spd = v; };
	void revive();
	// ABILITIES (declared in "Abiliy.cpp" file)
	std::array<Ability*, 4> getAbilities();
	void learn(Ability* a, int position);
	void use(int aNum, std::vector<Pokemon> targets);

private:
	std::string name;
	Type type;
	int level;
	int hp, maxHp, atk, def, spd;
	std::array<Ability*, 4> abilities;
	bool alive;
};
