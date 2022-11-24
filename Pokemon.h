#pragma once

class Pokemon
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
	// ABILITIES
	void learn(Ability a, int position);
	void use(int aNum);

private:
	std::string name;
	Type type;
	int level;
	int hp, maxHp, atk, def, spd;
	std::array<Ability*, 4> abilities;
};

