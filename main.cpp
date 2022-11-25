#include <SFML/Graphics.hpp>
#include "include/Game.hpp"
#include "include/Button.h"
#include "include/Const.h"
#include "include/Player.hpp"
#include "include/AnimatedEntity.hpp"
#include "include/Entity.hpp"
#include <iostream>
#include "include/Pokemon.hpp"
#include "include/Ability.hpp"


int main()
{
    Game g;
	
    sf::Texture texture;
    if (!texture.loadFromFile(PLAYER_TEXTURE_PATH))
    {
		std::cout << "Error loading texture" << std::endl;
    }
	
	// Our player
	Player louis = Player(texture);

	while (g.isRunning())
	{
		g.clear();
		g.handleEvents();
		if (g.isInGame())
		{
			louis.handleEvents();
			g.drawMap(louis.getPos());
			g.drawEntity(louis);
		}
		else if (g.isInBattle())
		{
			
		}
		g.display();
	}
    return 0;
}