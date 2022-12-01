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
	g.loadMap();
	g.loadAbilities();
	g.loadPokemons();

	g.switchToInBattle();
	int frame = 0;
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
			g.manageAndDrawPlayer(frame);
			g.drawMapLayer(LAYER_DECORATIONS);
			g.drawMapLayer(LAYER_OBSTACLES);
			break;
		case GameState::InBattle:
			g.manageAndDrawBattle(frame);
			break;
		}
		
		g.display();
		frame = (frame + 1) % FPS_LIMIT;
	}
    return 0;
}