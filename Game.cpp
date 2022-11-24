#include "Game.h"

Game::Game() : gameWindow(sf::VideoMode(1600, 800), "Pokemon Dazzled") {
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
		if (event.type == sf::Event::Closed)
		{
			this->gameWindow.close();

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			(*p).moveLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			(*p).moveRight();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			(*p).moveUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			(*p).moveDown();
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

void Game::drawSpriteEntity(const Entity& spriteEntity)
{
	this->gameWindow.draw(spriteEntity.getSprite());
}