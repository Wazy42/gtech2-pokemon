#include "../include/Game.hpp"

#include <fstream>

Game::Game(Player& player) : 
	gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pokemon Dazzled", sf::Style::Close),
	gameState(GameState::MainMenu), 
	player(player)
{
	gameWindow.setFramerateLimit(FPS_LIMIT);
}

/// Menus

// Change game state to MainMenu
void Game::switchToMainMenu()
{
	this->gameState = GameState::MainMenu;
}

void Game::switchToPauseMenu()
{
	this->gameState = GameState::PauseMenu;
}

void Game::switchToInGame()
{
	this->gameState = GameState::InGame;
}

void Game::switchToInBattle()
{
	this->gameState = GameState::InBattle;
}

/// Game

// Returns true if the game is running
bool Game::isRunning() const
{
	return this->gameWindow.isOpen();
}

GameState Game::getGameState() const
{
	return this->gameState;
}


void Game::handleEvents()
{
	sf::Event event;
	while (this->gameWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->gameWindow.close();
			break;
		case sf::Event::KeyPressed:
			if (this->gameState == PauseMenu && ESC_PRESSED)
			{
				this->gameState = InGame;
			}
			else if (this->gameState == InGame && ESC_PRESSED)
			{
				// TODO: Pause menu
			}
			break;
		case sf::Event::MouseButtonPressed:
			sf::Vector2i mousePosition = sf::Mouse::getPosition(this->gameWindow);
			if (this->gameState == MainMenu)
			{
				if (PLAY_BUTTON_RECT.contains(mousePosition))
				{
					this->switchToInGame();
				}
				else if (SETTINGS_BUTTON_RECT.contains(mousePosition))
				{
					this->gameWindow.close();
				}
				else if (QUIT_BUTTON_RECT.contains(mousePosition))
				{
					this->gameWindow.close();
				}
			}
		}
	}
}

void Game::managePlayer()
{
	// Player has to end his movement
	if (this->player.isMoving() && this->player.isOnATile())
	{
		this->player.stopMoving();
	}

	// Check if player wants to move
	if (!player.isMoving())
	{// TODO: Check collisions before moving
		if (Z_PRESSED || UP_PRESSED)
		{
			this->player.setFacing(Direction::North, true);
		}
		else if (Q_PRESSED || LEFT_PRESSED)
		{
			this->player.setFacing(Direction::West, true);
		}
		else if (S_PRESSED || DOWN_PRESSED)
		{
			this->player.setFacing(Direction::South, true);
		}
		else if (D_PRESSED || RIGHT_PRESSED)
		{
			this->player.setFacing(Direction::East, true);
		}
		else
		{
			this->player.setCurrentFrame(0);
		}
	}

	// Animate the walk
	if (player.isMoving())
	{
		switch (this->player.getFacing())
		{
		case Direction::North:
			this->player.moveOnMap(0, -PLAYER_MOVEMENT_STEP);
			break;
		case Direction::West:
			this->player.moveOnMap(-PLAYER_MOVEMENT_STEP, 0);
			break;
		case Direction::South:
			this->player.moveOnMap(0, PLAYER_MOVEMENT_STEP);
			break;
		case Direction::East:
			this->player.moveOnMap(PLAYER_MOVEMENT_STEP, 0);
			break;
		}

		if ((int)(this->player.getPositionOnMap().x + this->player.getPositionOnMap().y) % 8 == 0)
			this->player.gotoNextFrame();
	}
}

void Game::loadMap()
{
	// Load textures
	this->globalTexture.loadFromFile("assets/map/global.png");
	this->natureTexture.loadFromFile("assets/map/nature.png");
	

	// Load map
	std::string data;
	std::string line;
	std::fstream file;
	//Open the file in read mode
	file.open("data/spawn.map", std::ios::in);
	if (file.is_open())
	{
		while (getline(file, line))
			data += line;
		file.close();
	}
	else
	{
		std::cout << "Error while opening the file" << std::endl;
	}

	// Create the map
	std::string temp = ""; 
	std::vector<int> row = std::vector<int>();
	std::vector<std::vector<int>> layer = std::vector<std::vector<int>>();
	this->spawnMap = std::vector<std::vector<std::vector<int>>>(); // reset map
	for (int i = 0; i < data.size(); i++)
	{
		// new tile
		if (data[i] == ',')
		{
			temp = "";
		}
		// new tile line
		else if (data[i] == ';')
		{
			if (row != std::vector<int>())
			{
				layer.push_back(row);
				row = std::vector<int>();
			}
		}
		// new layer
		else if (data[i] == '!')
		{
			if (layer != std::vector<std::vector<int>>())
			{
				this->spawnMap.push_back(layer);
				layer = std::vector<std::vector<int>>();
			}
		}
		else
			temp += data[i];

		#define PUSH_ID_ON_STR(str, id) if (temp == str) row.push_back(id)
		
		PUSH_ID_ON_STR("grass", 163);
		PUSH_ID_ON_STR("spawn", 6686);
		PUSH_ID_ON_STR("void", -1);
	}

}

void Game::drawEntity(Entity& Entity)
{
	this->gameWindow.draw(Entity.getSprite());
}

// Draw a text on the window
void Game::drawText(sf::Text text)
{
	this->gameWindow.draw(text);
}

void Game::drawMainMenu()
{
	// Get the background
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile(MAIN_MENU_TEXTURE_PATH);
	
	// Create the text
	sf::Text playText = this->createText("JOUER", 100, 100);
	sf::Text settingsText = this->createText("OPTIONS", 100, 200);
	sf::Text quitText = this->createText("QUITTER", 100, 300);

	// Draw
	this->gameWindow.draw(sf::Sprite(backgroundTexture));
	this->drawText(playText);
	this->drawText(settingsText);
	this->drawText(quitText);
}

void Game::drawPauseMenu()
{
}

void Game::drawInGame()
{
	sf::Sprite sprite;
	sprite.setTexture(this->globalTexture);
	
	// Draw the map
	for (int layer_i = 0; layer_i > this->spawnMap.size(); layer_i++)
	{
		// Draw each layer
		std::vector<std::vector<int>> layer = this->spawnMap[layer_i];
		for (int row_i = 0; row_i > layer.size(); row_i++)
		{
			// Draw each row
			std::vector<int> row = layer[row_i];
			for (int tile_i = 0; tile_i > row.size(); tile_i++)
			{
				
				int tileID = row[tile_i];
				if (tileID == -1)
					continue;

				sprite.setTextureRect(MAP_SPRITE_COORDS(tileID));
				sprite.setPosition(row_i * TILE_SIZE, layer_i * TILE_SIZE);
				sprite.setScale(MAP_TILE_SCALE, MAP_TILE_SCALE);
				this->gameWindow.draw(sprite);
			}
		}
	}

	// Draw player
	this->gameWindow.draw(this->player.getSprite());
}

void Game::drawInBattle()
{
}

void Game::clear()
{
	this->gameWindow.clear();
}


void Game::display()
{
	this->gameWindow.display();
}

/// Text

// Change the font
void Game::changeFont(std::string fontPath)
{
	this->font.loadFromFile(fontPath);
}

void Game::changeFontSize(int fontSize)
{
	this->fontSize = fontSize;
}

void Game::changeFontColor(sf::Color color)
{
	this->fontColor = color;
}

sf::Text Game::createText(std::string text, int x, int y)
{
	sf::Text textToReturn;
	textToReturn.setFont(this->font);
	textToReturn.setString(text);
	textToReturn.setCharacterSize(this->fontSize);
	textToReturn.setFillColor(this->fontColor);
	textToReturn.setPosition(x, y);
	return textToReturn;
}