#pragma once

enum Type {
	Normal,
	Fire,
	Water,
	Grass,
};

float getMultiplier(Type attacker, Type defender);
