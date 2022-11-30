#include <SFML/Graphics.hpp>

#include "include/Game.hpp"
#include "include/Const.h"
#include "include/Player.hpp"
#include <iostream>


int main()
{
    sf::Texture texture;
    if (!texture.loadFromFile(PLAYER_TEXTURE_PATH))
    {
		throw std::runtime_error("Error while loading texture");
    }
	
	Player louis = Player(texture);
	louis.setPositionOnMap(sf::Vector2f(40, 53));
	
	Game g(louis);
	g.switchToMainMenu();
	g.loadMap();

	while (g.isRunning())
	{
		g.handleEvents();
		g.clear();
		
		switch (g.getGameState())
		{
		case GameState::MainMenu:
		case GameState::PauseMenu:
			g.drawMenu();
			break;
		case GameState::InGame:
			g.drawMapLayer(LAYER_GROUD);
			g.drawMapLayer(LAYER_WALKABLE);
			g.drawMapLayer(LAYER_SPAWN);
			g.manageAndDrawPlayer();
			g.drawMapLayer(LAYER_DECORATIONS);
			g.drawMapLayer(LAYER_OBSTACLES);
			g.moveViewToPlayer();
			break;
		case GameState::InBattle:
			g.drawInBattle();
			break;
		}
		
		g.display();
	}
    return 0;
}