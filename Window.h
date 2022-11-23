#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "SpriteEntity.h"


class Window
{
public:
	Window();
	bool isRunning() const;
	void handleEvents();
	void update();
	void clear();
	void render();
	void display();
	void drawSpriteEntity(const Entity &);
	
private:
	sf::RenderWindow gameWindow;
};

