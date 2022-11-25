#pragma once

#include <SFML/Graphics.hpp>
#include "Const.h"
#include "Entity.hpp"
#include "Button.h"
#include "Player.hpp"


class Game
{
public:
	Game();
	bool isRunning() const;
	void handleEvents();
	void clear();
	void display();
	
	void draw(sf::Drawable& drawable) { this->gameWindow.draw(drawable); }
	void drawEntity(Entity &);
	void drawButton(Button &);
	void drawMap(sf::Vector2i playerPosition);
	
	void openMenu() { this->menuOpen = true; }
	void closeMenu() { this->menuOpen = false; }
	bool isMenuOpen() { return this->menuOpen; }
	
	void openBattle() { this->inBattle = true; }
	void closeBattle() { this->inBattle = false; }
	bool isInBattle() { return this->inBattle; }

	void openGame() { this->inGame = true; }
	void closeGame() { this->inGame = false; }
	bool isInGame() { return this->inGame; }
	
private:
	bool menuOpen;
	bool inGame;
	bool inBattle;
	sf::RenderWindow gameWindow;
	sf::Keyboard::Key lastKeyPressed;
};

