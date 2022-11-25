#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class AnimatedEntity : public Entity
{
protected:
	size_t actualFrame;
	std::vector<sf::IntRect> animationSprite;
	int intervalBFrames = 4;
	int frameCounter = 0;
	
public:
	AnimatedEntity(const sf::Texture&, std::vector <sf::IntRect>);
	void nextFrameSprite();
	void runSprite();
	void setActualFrame(int);
};

