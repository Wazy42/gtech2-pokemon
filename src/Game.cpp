#include "../include/Game.hpp"

Game::Game() : gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pokemon Dazzled") {
	this->gameWindow.setFramerateLimit(FPS_LIMIT);
	this->inBattle = false;
	this->inGame = true;
	this->menuOpen = false;
}

bool Game::isRunning() const
{
	return this->gameWindow.isOpen();
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

void Game::drawEntity(Entity& Entity)
{
	this->gameWindow.draw(Entity.getSprite());
}

void Game::drawButton(Button& button)
{
	this->gameWindow.draw(button.getSprite());
}

void Game::drawMap(sf::Vector2i playerPosition)
{
	/*sf::Texture mapTexture;
	if (!mapTexture.loadFromFile(MAP_TEXTURE_PATH))
	{
		std::cout << "Error loading map texture" << std::endl;
	}

	sf::Sprite mapSprite;
	mapSprite.setTexture(mapTexture);
	mapSprite.setPosition(playerPosition.x - WINDOW_WIDTH / 2, playerPosition.y - WINDOW_HEIGHT / 2);
	this->gameWindow.draw(mapSprite);*/
	sf::RectangleShape rectangle(sf::Vector2f(TILE_SIZE, TILE_SIZE));
	
	// Draw a grid of black and white rectangles, in function of the player position
	for (int i = 0; i < TILE_SIZE; i++)
	{
		for (int j = 0; j < TILE_SIZE; j++)
		{
			if ((i + j) % 2 == 0)
				rectangle.setFillColor(sf::Color::White);
			else
				rectangle.setFillColor(sf::Color::Black);
			rectangle.setPosition((float)-playerPosition.x - WINDOW_WIDTH / 2 + (i + 0.5) * TILE_SIZE, (float)-playerPosition.y - WINDOW_HEIGHT / 2 + j * TILE_SIZE);
			this->gameWindow.draw(rectangle);
		}
	}
}