#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "SpriteEntity.hpp"

class AnimatedSpriteEntity : public Entity
{
protected:
	size_t actualAnim;
	std::vector<sf::IntRect> animationSprite;
	int intervalAnim = 2;
	int framCounter = 0;
	
public:
	AnimatedSpriteEntity(const sf::Texture&, std::vector <sf::IntRect>);
	void nextFrameSprite();
	void runSprite();
	void setActualFrame(int);
};

