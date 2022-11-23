#include "Window.h"
#include "Const.h"

Window::Window() : gameWindow(sf::VideoMode(1600, 800), "Pokemon") {
	this->gameWindow.setFramerateLimit(FPS_LIMIT);
}

bool Window::isRunning() const
{
	return this->gameWindow.isOpen();
}

void Window::handleEvents()
{
	sf::Event event;
	while (this->gameWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->gameWindow.close();
		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		dir.y -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		dir.y += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		dir.x -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		dir.x += 1;
	}
}

void Window::update()
{
}

void Window::clear()
{
	this->gameWindow.clear();
}

void Window::render()
{
}

void Window::display()
{
	this->gameWindow.display();
}

void Window::drawSpriteEntity(const Entity& spriteEntity)
{
	this->gameWindow.draw(spriteEntity.getSprite());
}