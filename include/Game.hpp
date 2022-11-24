#pragma once

#include <SFML/Graphics.hpp>
#include "Const.h"
#include "SpriteEntity.hpp"
#include "Button.h"
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
	void drawButton(const Button &);
	
private:
	sf::RenderWindow gameWindow;
	sf::Texture btexture;
	sf::Sprite bsprite;
	sf::Keyboard::Key lastKeyPressed;
};

