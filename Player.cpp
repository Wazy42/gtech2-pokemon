#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Const.h"

Louis::Louis(const sf::Texture& texture) :
	AnimatedSpriteEntity(texture, std::vector<sf::IntRect>(LOUIS_ANIM))
{
	this->spriteEntity.scale(32, 32);
}