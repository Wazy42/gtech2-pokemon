#include "../include/Game.hpp"

Game::Game(Player& player) : 
	gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pokemon Dazzled", sf::Style::Fullscreen),
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

/// Drawings

// Draw an entity on the window
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
	// Draw the map
	sf::RectangleShape rectangle(sf::Vector2f((float)TILE_SIZE, (float)TILE_SIZE));
	for (int i = 0; i < TILE_SIZE; i++)
	{
		for (int j = 0; j < TILE_SIZE; j++)
		{
			if ((i + j) % 2 == 0)
				rectangle.setFillColor(sf::Color::White);
			else
				rectangle.setFillColor(sf::Color::Black);
			rectangle.setPosition(-this->player.getPositionOnMap().x - WINDOW_WIDTH / 2 + (i + 0.5) * TILE_SIZE, -this->player.getPositionOnMap().y - WINDOW_HEIGHT / 2 + j * TILE_SIZE);
			this->gameWindow.draw(rectangle);
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