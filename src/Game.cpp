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
			switch (event.key.code)
			{
			case sf::Keyboard::D:
				printf("D");
				if (p->isMoving())
					break;
				p->setMoving(true);
				p->faceRight();
				break;

			case sf::Keyboard::Q:
				printf("Q");
				if (p->isMoving())
					break;
				p->setMoving(true);
				p->faceLeft();
				break;

			case sf::Keyboard::Z:
				printf("Z");
				if (p->isMoving())
					break;
				p->setMoving(true);
				p->faceUp();
				break;

			case sf::Keyboard::S:
				printf("S");
				if (p->isMoving())
					break;
				p->setMoving(true);
				p->faceDown();
				break;
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

void Game::drawSpriteEntity(const Entity& spriteEntity)
{
	this->gameWindow.draw(spriteEntity.getSprite());
}

void Game::drawButton(const Button& button)
{
	this->gameWindow.draw(button.getSprite());
}