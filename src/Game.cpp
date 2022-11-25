#include "../include/Game.hpp"

Game::Game() : gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pokemon Dazzled") {
	this->gameWindow.setFramerateLimit(FPS_LIMIT);
}

bool Game::isRunning() const
{
	return this->gameWindow.isOpen();
}

void Game::handleEvents(Player* p)
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
			if (this->inGame)
				p->handleKeyPressed(event);
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

void Game::drawSpriteEntity(Entity& spriteEntity)
{
	this->gameWindow.draw(spriteEntity.getSprite());
}

void Game::drawButton(Button& button)
{
	this->gameWindow.draw(button.getSprite());
}

void Game::drawTest()
{
	sf::RectangleShape rectangle(sf::Vector2f(TILE_SIZE, TILE_SIZE));
	//draw a grid 32x32 pixels with alternance yellow and blue
	for (int i = 0; i < TILE_SIZE; i++)
	{
		for (int j = 0; j < TILE_SIZE; j++)
		{
			if ((i + j) % 2 == 0)
				rectangle.setFillColor(sf::Color::White);
			else
				rectangle.setFillColor(sf::Color::Black);
			rectangle.setPosition((float)i * TILE_SIZE, (float)j * TILE_SIZE);
			this->gameWindow.draw(rectangle);
		}
	}
}