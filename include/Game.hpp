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
	
	// Menus
	void switchToMainMenu();
	void switchToPauseMenu();
	void switchToInGame();
	void switchToInBattle();

	// Game
	bool isRunning() const;
	GameState getGameState() const;
	void handleEvents();
	void managePlayer();
	
	// Drawings
	void drawEntity(Entity& Entity);
	void drawText(sf::Text text);
	void drawMainMenu();
	void drawPauseMenu();
	void drawInGame();
	void drawInBattle();
	void clear();
	void display();

	// Text
	void changeFont(std::string fontPath);
	void changeFontSize(int size);
	void changeFontColor(sf::Color color);
	sf::Text createText(std::string text, int x, int y);
	
private:
	sf::RenderWindow gameWindow;
	GameState gameState;
	Player player;
	sf::Keyboard::Key buffer;

	// Text
	sf::Font font;
	int fontSize;
	sf::Color fontColor;
};

