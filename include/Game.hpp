#pragma once

#include <SFML/Graphics.hpp>
#include "Const.h"
#include "SpriteEntity.hpp"
#include "Player.hpp"


class Game
{
public:
	Game();
	bool isRunning() const;
	void handleEvents(Player* p);
	void clear();
	void display();
	void drawSpriteEntity(const Entity &);
	
private:
	sf::RenderWindow gameWindow;
};

