#pragma once

#include <SFML/Graphics.hpp>
#include "Const.h"
#include "Entity.hpp"
#include "Player.hpp"

enum GameState
{
	MainMenu,
	PauseMenu,
	InGame,
	InBattle
};

class Game
{
public:
	Game(Player& player);
	
	// Game
	bool isRunning() const;
	GameState getGameState() const;
	void switchToMainMenu();
	void switchToPauseMenu();
	void switchToInGame();
	void switchToInBattle();
	void handleEvents();
	void managePlayer();
	
	// Drawings
	void drawEntity(Entity& Entity);
	void drawMap();
	void clear();
	void display();
	
private:
	sf::RenderWindow gameWindow;
	GameState gameState;
	Player player;
	sf::Keyboard::Key buffer;
};

