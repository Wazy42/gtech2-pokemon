#include "../include/Game.hpp"

Game::Game(Player& player) : 
	gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pokemon Dazzled", sf::Style::Close),
	gameState(GameState::MainMenu), 
	player(player)
{
	gameWindow.setFramerateLimit(FPS_LIMIT);
}

bool Game::isRunning() const
{
	return this->gameWindow.isOpen();
}

GameState Game::getGameState() const
{
	return this->gameState;
}

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

		if ((int)(this->player.getPosition().x + this->player.getPosition().y) % 8 == 0)
			this->player.gotoNextFrame();
	}

	// Draw player
	this->gameWindow.draw(this->player.getSprite());
}

void Game::drawEntity(Entity& Entity)
{
	this->gameWindow.draw(Entity.getSprite());
}

void Game::drawMap()
{
	sf::RectangleShape rectangle(sf::Vector2f((float)TILE_SIZE, (float)TILE_SIZE));

	// Draw a grid of black and white rectangles, in function of the player position
	for (int i = 0; i < TILE_SIZE; i++)
	{
		for (int j = 0; j < TILE_SIZE; j++)
		{
			if ((i + j) % 2 == 0)
				rectangle.setFillColor(sf::Color::White);
			else
				rectangle.setFillColor(sf::Color::Black);
			rectangle.setPosition(-this->player.getPosition().x - WINDOW_WIDTH / 2 + (i + 0.5) * TILE_SIZE, -this->player.getPosition().y - WINDOW_HEIGHT / 2 + j * TILE_SIZE);
			this->gameWindow.draw(rectangle);
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