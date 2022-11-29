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
	void loadMap();
	
	// Drawings
	void drawEntity(Entity& Entity);
	void drawText(sf::Text text);
	void drawMenu();
	void drawInGame();
	void drawInBattle();
	void clear();
	void display();

	// Text
	void changeFont(std::string fontPath);
	void changeFontSize(int size);
	void changeFontColor(sf::Color color);
	sf::Text createText(std::string text, sf::IntRect rect);
	
private:
	// Game
	sf::RenderWindow gameWindow;
	GameState gameState;
	Player player;
	sf::Keyboard::Key buffer;

	// Text
	sf::Font font;
	int fontSize;
	sf::Color fontColor;
	
	// Map
	sf::Texture globalTexture;
	sf::Texture natureTexture;
	std::vector<std::vector<std::vector<int>>> spawnMap;

	// Menus
	std::vector<sf::Text> textsToDraw;
	sf::Texture backgroundTexture;
};

