#include "../include/Game.hpp"

#include <fstream>

Game::Game(Player& player) : 
	gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pokemon Dazzled", sf::Style::Close),
	gameState(GameState::MainMenu), 
	player(player)
{
	gameView = gameWindow.getView();
	gameWindow.setFramerateLimit(FPS_LIMIT);
}

/// Menus

// Change game state to MainMenu
void Game::switchToMainMenu()
{
	// Get the background
	this->backgroundTexture.loadFromFile(MAIN_MENU_TEXTURE_PATH);
	
	// Create the text
	this->changeFont(FONT_POKEMON_SOLID_PATH);
	this->changeFontColor(sf::Color::Blue);
	this->changeFontSize(FONT_SIZE_MENU);

	this->textsToDraw.clear();
	this->textsToDraw.push_back(this->createText("Play", PLAY_BUTTON_RECT));
	this->textsToDraw.push_back(this->createText("Settings", SETTINGS_BUTTON_RECT));
	this->textsToDraw.push_back(this->createText("Quit", QUIT_BUTTON_RECT));
	
	this->resetView();
	this->gameState = GameState::MainMenu;
}

void Game::switchToPauseMenu()
{
	// Get the background
	this->backgroundTexture.loadFromFile(PAUSE_MENU_TEXTURE_PATH);
	
	// Create the text
	this->changeFont(FONT_SPINWERAD_PATH);
	this->changeFontColor(sf::Color::Yellow);
	this->changeFontSize(FONT_SIZE_MENU);

	this->textsToDraw.clear();
	this->textsToDraw.push_back(this->createText("Resume", RESUME_BUTTON_RECT));
	this->textsToDraw.push_back(this->createText("Save to main menu", MAIN_MENU_BUTTON_RECT));
	this->textsToDraw.push_back(this->createText("Save and quit", SAVE_AND_QUIT_BUTTON_RECT));
	
	this->resetView();
	this->gameState = GameState::PauseMenu;
}

void Game::switchToInGame()
{
	this->resetView();
	this->gameState = GameState::InGame;
}

void Game::switchToInBattle()
{
	// Get the background
	this->backgroundTexture.loadFromFile(BATTLE_TEXTURE_PATH);

	this->resetView();
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

		// Keyboard events
		case sf::Event::KeyPressed:
			if (this->gameState == PauseMenu && ESC_PRESSED)
			{
				this->switchToInGame();
			}
			else if (this->gameState == InGame && ESC_PRESSED)
			{
				this->switchToPauseMenu();
			}
			break;

		// Mouse events
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
			else if (this->gameState == PauseMenu)
			{
				if (RESUME_BUTTON_RECT.contains(mousePosition))
				{
					this->switchToInGame();
				}
				else if (MAIN_MENU_BUTTON_RECT.contains(mousePosition))
				{
					this->switchToMainMenu();
				}
				else if (SAVE_AND_QUIT_BUTTON_RECT.contains(mousePosition))
				{
					this->gameWindow.close();
				}
			}
		}
	}
}

void Game::manageAndDrawPlayer()
{
	// Player has to end his movement
	if (this->player.isMoving() && this->player.isOnATile())
	{
		this->player.stopMoving();
		
		//// If player is on a spawn tile, he may encounter a wild pokemon
		//if (this->spawnMap[LAYER_SPAWN][this->player.getPositionOnMap().y][this->player.getPositionOnMap().x] != 0)
		//{
		//	// Generate ennemies
		//	std::vector<Pokemon*> ennemies;
		//	ennemies.push_back(this->getRandomPokemon());
		//	
		//	this->switchToInBattle();
		//}
	}

	// Check if player wants to move
	if (!player.isMoving()) 
	{
		if (Z_PRESSED || UP_PRESSED)
		{
			this->player.setFacing(Direction::North, this->spawnMap[LAYER_OBSTACLES][(int)this->player.getPositionOnMap().y - 1][(int)this->player.getPositionOnMap().x] == 0);
		}
		else if (S_PRESSED || DOWN_PRESSED)
		{
			this->player.setFacing(Direction::South, this->spawnMap[LAYER_OBSTACLES][(int)this->player.getPositionOnMap().y + 1][(int)this->player.getPositionOnMap().x] == 0);
		}
		else if (Q_PRESSED || LEFT_PRESSED)
		{
			this->player.setFacing(Direction::West, this->spawnMap[LAYER_OBSTACLES][(int)this->player.getPositionOnMap().y][(int)this->player.getPositionOnMap().x - 1] == 0);
		}
		else if (D_PRESSED || RIGHT_PRESSED)
		{
			this->player.setFacing(Direction::East, this->spawnMap[LAYER_OBSTACLES][(int)this->player.getPositionOnMap().y][(int)this->player.getPositionOnMap().x + 1] == 0);
		}
		if (!this->player.isMoving())
		{
			this->player.setCurrentFrame(0);
		}
	}

	// Animate the walk
	if (player.isMoving())
	{
		if (player.getPositionOnMap().x == (int)player.getPositionOnMap().x && player.getPositionOnMap().y == (int)player.getPositionOnMap().y)
			this->player.gotoNextFrame();
		
		switch (this->player.getFacing())
		{
		case Direction::North:
			this->player.moveOnMap(0, (float)(-0.1 * PLAYER_WALK_SPEED));
			break;
		case Direction::South:
			this->player.moveOnMap(0, (float)(0.1 * PLAYER_WALK_SPEED));
			break;
		case Direction::West:
			this->player.moveOnMap((float)(-0.1 * PLAYER_WALK_SPEED), 0);
			break;
		case Direction::East:
			this->player.moveOnMap((float)(0.1 * PLAYER_WALK_SPEED), 0);
			break;
		}
	}

	// Draw player
	this->gameWindow.draw(this->player.getSprite());
}

void Game::loadMap()
{
	// Load textures
	this->globalTexture.loadFromFile(MAP_TEXTURE_PATH);	

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
		throw std::runtime_error("Error while opening the file");
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
			if (temp != "")
			{
				int tile = std::stoi(temp);
				row.push_back(tile);
				temp = "";
			}
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
	}
}

Pokemon* Game::getRandomPokemon()
{
	// TODO: get a random pokemon with a lvl similar to the player's lvl
	return new Pokemon(sf::Texture(), "Test", 0, 0, 0, 0, 0, std::array<Ability*, 4>(), Normal);
}

void Game::moveViewToPlayer()
{
	// Move the view to the player
	this->gameView.setCenter(this->player.getPositionOnMap().x * TILE_SIZE + TILE_SIZE / 2, this->player.getPositionOnMap().y * TILE_SIZE + TILE_SIZE / 2);
	gameWindow.setView(gameView);
}

void Game::resetView()
{
	// Reset the view
	this->gameView.setCenter(floorf((float)this->gameWindow.getSize().x / 2), floorf((float)this->gameWindow.getSize().y / 2));
	gameWindow.setView(gameView);
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

void Game::drawMenu()
{
	this->gameWindow.draw(sf::Sprite(this->backgroundTexture));
	for (int i = 0; i < this->textsToDraw.size(); i++)
	{
		this->drawText(this->textsToDraw[i]);
	}
}

// Draw the map in function of the player's coordinates
void Game::drawMapLayer(int layer)
{
	sf::Sprite sprite;
	sprite.setTexture(this->globalTexture);
	int playerX = (int)(this->player.getPositionOnMap().x);
	int playerY = (int)(this->player.getPositionOnMap().y);

	int top = std::max(0, playerY - WINDOW_HEIGHT / TILE_SIZE / 2);
	int bot = std::min((int)this->spawnMap[layer].size(), playerY + WINDOW_HEIGHT / TILE_SIZE / 2 + 2);
	for (int y = top; y < bot; y++)
	{
		int left = std::max(0, playerX - WINDOW_WIDTH / TILE_SIZE / 2);
		int right = std::min((int)this->spawnMap[layer][y].size(), playerX + WINDOW_WIDTH / TILE_SIZE / 2 + 2);
		for (int x = left; x < right; x++)
		{
			int id = this->spawnMap[layer][y][x] - 1;
			if (id != -1)
			{
				sprite.setTextureRect(sf::IntRect(
					(id % 148) * MAP_TILE_SIZE,
					(id / 148) * MAP_TILE_SIZE,
					16,
					16
				));
				sprite.setPosition((float)(x * TILE_SIZE), (float)(y * TILE_SIZE));
				sprite.setScale(MAP_TILE_SCALE, MAP_TILE_SCALE);
				this->gameWindow.draw(sprite);
			}
		}
	}
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

// Create and return a text centered in a rect
sf::Text Game::createText(std::string text, sf::IntRect rect)
{
	sf::Text textToReturn;
	textToReturn.setFont(this->font);
	textToReturn.setString(text);
	textToReturn.setCharacterSize(this->fontSize);
	textToReturn.setFillColor(this->fontColor);
	textToReturn.setPosition(
		rect.left + rect.width / 2 - textToReturn.getGlobalBounds().width / 2,
		rect.top + rect.height / 2 - textToReturn.getGlobalBounds().height / 2
	);
	return textToReturn;
}