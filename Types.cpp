#include "Types.hpp"

// Returns the multiplier applied to the damage of an attack
float getMultiplier(Type attacker, Type defender)
{
	switch (attacker)
	{
	case Fire:
		switch (defender)
		{
		case Grass:
			return 2.0f;
		case Fire:
		case Water:
			return 0.5f;
		default:
			return 1.0f;
		}
	case Water:
		switch (defender)
		{
		case Fire:
			return 2.0f;
		case Water:
		case Grass:
			return 0.5f;
		default:
			return 1.0f;
		}
	case Grass:
		switch (defender)
		{
		case Water:
			return 2.0f;
		case Fire:
		case Grass:
			return 0.5f;
		default:
			return 1.0f;
		}
	default:
		return 1.0f;
	}
}