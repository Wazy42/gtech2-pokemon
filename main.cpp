#include <SFML/Graphics.hpp>
#include "include/Game.hpp"
#include "include/Const.h"
#include "include/Player.hpp"
#include "include/AnimatedEntity.hpp"
#include "include/Entity.hpp"
#include <iostream>
#include "include/Pokemon.hpp"
#include "include/Ability.hpp"


int main()
{
    sf::Texture texture;
    if (!texture.loadFromFile(PLAYER_TEXTURE_PATH))
    {
		std::cout << "Error loading texture" << std::endl;
    }
	
	Player louis = Player(texture);
	
	Game g(louis);
	g.switchToInGame();

	while (g.isRunning())
	{
		g.clear();
		g.handleEvents();
		if (g.getGameState() == GameState::InGame)
		{
			g.drawMap();
			g.managePlayer();
		}
		g.display();
	}
    return 0;
}