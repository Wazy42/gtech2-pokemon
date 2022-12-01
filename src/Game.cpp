#include "../include/Game.hpp"

#include <fstream>

Game::Game(Player& player) : 
	gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pokemon Dazzled"),
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

	this->textsToDraw.clear();
	
	// Create the battle
	this->battle = new Battle(
		this->player.getTeam()[0],
		this->createRandomPokemon()
	);
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
					this->loadMap();
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
					this->saveGame(std::string{ SAVE_FILE_PATH });
					this->switchToMainMenu();
				}
				else if (SAVE_AND_QUIT_BUTTON_RECT.contains(mousePosition))
				{
					this->saveGame(std::string{ SAVE_FILE_PATH });
					this->gameWindow.close();
				}
			}
		}
	}
}

void Game::manageAndDrawPlayer(int frame)
{
	// Player has to end his movement
	if (this->player.isMoving() && this->player.isOnATile())
	{
		this->player.stopMoving();
		
		// If player is on a spawn tile, he may encounter a wild pokemon
		if (this->spawnMap[LAYER_SPAWN][this->player.getPositionOnMap().y][this->player.getPositionOnMap().x] != 0)
		{
			int random = rand() % 100;
			if (random < SPAWN_CHANCE) {
				this->switchToInBattle();
			}
		}
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
		if (frame % 4 == 0)
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

void Game::manageAndDrawBattle(int frame)
{
	this->gameWindow.draw(sf::Sprite(this->backgroundTexture));
	for (int i = 0; i < this->textsToDraw.size(); i++)
	{
		this->drawText(this->textsToDraw[i]);
	}
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
	file.open(MAP_SPAWN_PATH, std::ios::in);
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
	this->spawnMap.clear(); // reset map
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

void Game::loadPokemons() {
	std::string data;
	std::string line;
	std::fstream file;
	
	//Open the file in read mode
	file.open(POKEMON_LIST_PATH, std::ios::in);
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

	// Fill the pokemon list
	this->pokemonList.clear();
	std::string temp = "";
	std::vector<std::string> pokemonStats = std::vector<std::string>();
	for (int i = 0; i < data.size(); i++)
	{
		// new pokemon
		if (data[i] == ';')
		{
			if (pokemonStats != std::vector<std::string>())
			{
				this->pokemonList.push_back(pokemonStats);
				pokemonStats = std::vector<std::string>();
			}
		}
		// new stat
		else if (data[i] == ',')
		{
			if (temp != "")
			{
				pokemonStats.push_back(temp);
				temp = "";
			}
		}
		else
			temp += data[i];
	}
	
	// Get the player his first pokemon Eevee
	sf::Texture texture;
	texture.loadFromFile(POKEMON_TEXTURE_PATH + std::string("133.png"));
	std::string name = "Eevee";
	int lvl = 1;
	int hp = 55;
	int atk = 55;
	int def = 50;
	int spd = 55;
	Type type = Type::Normal;
	std::vector<Ability*> abilities = std::vector<Ability*>();
	abilities.push_back(this->abilityList[2]);
	this->player.addPokemon(new Pokemon(texture, name, lvl, hp, atk, def, spd, abilities, type));
}

void Game::loadAbilities()
{
	std::string data;
	std::string line;
	std::fstream file;

	//Open the file in read mode
	file.open(ABILITY_LIST_PATH, std::ios::in);
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

	// Fill the ability list
	this->abilityList.clear();
	std::string temp = "";
	std::vector<std::string> abilityData = std::vector<std::string>();
	for (int i = 0; i < data.size(); i++)
	{
		// new ability
		if (data[i] == ';')
		{
			if (abilityData != std::vector<std::string>())
			{
				// Create the ability
				std::string name = abilityData[0];
				int power = std::stoi(abilityData[1]);
				Type type;
				if (abilityData[2] == "Normal")
					type = Type::Normal;
				else if (abilityData[2] == "Fire")
					type = Type::Fire;
				else if (abilityData[2] == "Water")
					type = Type::Water;
				else if (abilityData[2] == "Grass")
					type = Type::Grass;
				
				this->abilityList.push_back(new Ability(name, power, type));
				abilityData = std::vector<std::string>();
			}
		}
		// new stat
		else if (data[i] == ',')
		{
			if (temp != "")
			{
				abilityData.push_back(temp);
				temp = "";
			}
		}
		else
			temp += data[i];
	}
}

Pokemon* Game::createRandomPokemon()
{
	// create random pokemon with a lvl similar to the player's lvl:
	int random = rand() % this->pokemonList.size();
	// Get the texture
	sf::Texture texture;
	texture.loadFromFile(POKEMON_TEXTURE_PATH + this->pokemonList[random][1] + ".png");
	// Get the type
	Type type;
	if (this->pokemonList[random][2] == "Normal")
		type = Type::Normal;
	else if (this->pokemonList[random][2] == "Fire")
		type = Type::Fire;
	else if (this->pokemonList[random][2] == "Water")
		type = Type::Water;
	else if (this->pokemonList[random][2] == "Grass")
		type = Type::Grass;
	// Create a lvl based on the team highest level pokemon
	int lvl = this->player.getHighestLvlPokemon()->getLevel() + rand() % 5 - 2;
	// Get the base stats
	std::string name = this->pokemonList[random][0];
	int hp = std::stoi(this->pokemonList[random][3]);
	hp = hp * lvl / 50 + lvl + 10 + rand() % 16;
	
	int atk = std::stoi(this->pokemonList[random][4]);
	atk = atk * lvl / 50 + 5 + rand() % 16;
	int def = std::stoi(this->pokemonList[random][5]);
	def = def * lvl / 50 + 5 + rand() % 16;
	int spd = std::stoi(this->pokemonList[random][6]);
	spd = spd * lvl / 50 + 5 + rand() % 16;

	// Get 4 random abilities
	std::vector<Ability*> abilities = std::vector<Ability*>();
	random = rand() % 4;
	random = std::min(random + (int)(lvl / 20), 4);
	for (int i = 0; i < random; i++)
		abilities.push_back(this->abilityList[rand() % this->abilityList.size()]);
	
	return new Pokemon(texture, name, lvl, hp, atk, def, spd, abilities, type);
}

void Game::moveViewToPlayer()
{
	// Set the camera on top of the player except when it allows us to see the outside of the map
    this->gameView.setCenter(
        // Camera X:
        std::min(
            std::max(
                this->player.getPositionOnMap().x * TILE_SIZE,
                this->gameView.getSize().x / 2
            ), this->spawnMap[0][0].size() * TILE_SIZE - (this->gameView.getSize().x + TILE_SIZE) / 2
        ) + TILE_SIZE / 2,
        // Camera Y
        std::min(
            std::max(
                this->player.getPositionOnMap().y * TILE_SIZE,
                this->gameView.getSize().y / 2
            ), this->spawnMap[0].size() * TILE_SIZE - (this->gameView.getSize().y + TILE_SIZE) / 2
        ) + TILE_SIZE / 2
    );
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

	// see moveViewToPlayer() to understand the following lines
	int camX = (int)(std::min(std::max(this->player.getPositionOnMap().x * TILE_SIZE, this->gameView.getSize().x / 2), this->spawnMap[0][0].size() * TILE_SIZE - this->gameView.getSize().x / 2) / TILE_SIZE);
	int camY = (int)(std::min(std::max(this->player.getPositionOnMap().y * TILE_SIZE, this->gameView.getSize().y / 2), this->spawnMap[0].size() * TILE_SIZE - this->gameView.getSize().y / 2) / TILE_SIZE);

	int top = std::max(0, camY - (int)this->gameView.getSize().y / TILE_SIZE / 2);
	int bot = std::min((int)this->spawnMap[layer].size(), camY + (int)this->gameView.getSize().y / TILE_SIZE / 2 + 2);
	for (int y = top; y < bot; y++)
	{
		int left = std::max(0, camX - (int)this->gameView.getSize().x / TILE_SIZE / 2);
		int right = std::min((int)this->spawnMap[layer][y].size(), camX + (int)this->gameView.getSize().x / TILE_SIZE / 2 + 2);
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

void Game::clear()
{
	this->gameWindow.clear();
}


void Game::display()
{
	this->gameWindow.display();
}


/// Save the game

void Game::saveGame(std::string fileName, bool rewrite)
{
	// Open the file
	std::ofstream file;
	file.open(SAVE_FILE_PATH);

	if (rewrite)
	{
		// Write the player's position
		file << this->player.getPositionOnMap().x << " " << this->player.getPositionOnMap().y << std::endl;
		// Write the player's team
		file << this->player.getTeam().size() << std::endl;
		for (int i = 0; i < this->player.getTeam().size(); i++)
		{
			file << this->player.getTeam()[i]->getName() << " " << this->player.getTeam()[i]->getLevel() << " " << this->player.getTeam()[i]->getHp() << " " << this->player.getTeam()[i]->getAtk() << " " << this->player.getTeam()[i]->getDef() << " " << this->player.getTeam()[i]->getSpd() << std::endl;
			file << this->player.getTeam()[i]->getAbilities().size() << std::endl;
			for (int j = 0; j < this->player.getTeam()[i]->getAbilities().size(); j++)
			{
				file << this->player.getTeam()[i]->getAbilities()[j]->getName() << std::endl;
			}
		}
	}
	else
	{
		// Write the player's position
		file << this->player.getPositionOnMap().x << ", " << this->player.getPositionOnMap().y << ";" << std::endl;
		// Write the player's team
		file << this->player.getTeam().size() << ";" << std::endl;
		for (int i = 0; i < this->player.getTeam().size(); i++)
		{
			file << this->player.getTeam()[i]->getName() << " " << this->player.getTeam()[i]->getLevel() << " " << this->player.getTeam()[i]->getHp() << " " << this->player.getTeam()[i]->getAtk() << " " << this->player.getTeam()[i]->getDef() << " " << this->player.getTeam()[i]->getSpd() << std::endl;
			file << this->player.getTeam()[i]->getAbilities().size() << std::endl;
			for (int j = 0; j < this->player.getTeam()[i]->getAbilities().size(); j++)
			{
				file << this->player.getTeam()[i]->getAbilities()[j]->getName() << ";" << std::endl;
			}
		}
	}
	
	file.close();
}

/// Load the game

void Game::loadGame(std::string fileName)
{
	// Open the file
	std::ifstream file;
	file.open(SAVE_FILE_PATH);

	if (file.is_open())
	{
		// Read coordinates
		std::ifstream file;
		int x, y;
		file >> x >> y;
		this->player.setPositionOnMap(sf::Vector2f(x, y));
	}
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