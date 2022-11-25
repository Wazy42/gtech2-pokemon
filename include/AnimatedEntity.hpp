#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class AnimatedEntity : public Entity
{
public:
	AnimatedEntity(const sf::Texture& texture, std::vector<sf::IntRect> framesCoords);
	
	void setFramesCoords(std::vector<sf::IntRect> framesCoords);

	// Frame management
	void gotoNextFrame();
	void setCurrentFrame(size_t frame);
	size_t getCurrentFrame() const;
	
protected:
	std::vector<sf::IntRect> framesCoords;
	size_t currentFrame;
};

