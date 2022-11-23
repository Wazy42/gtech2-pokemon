#include "AnimatedSpriteEntity.h"

class Louis : public AnimatedSpriteEntity
{
public:
	Louis(const sf::Texture& texture);
private:
	int speed = 5;
	int pos;
	int velocity = 0;
};

