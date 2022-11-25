#include <SFML/Graphics.hpp>
#include "include/Game.hpp"
#include "include/Button.h"
#include "include/Const.h"
#include "include/Player.hpp"
#include "include/AnimatedSpriteEntity.hpp"
#include "include/SpriteEntity.hpp"
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
	
	Player louis = Player(texture);

	while (g.isRunning())
	{
		g.clear();
		g.handleEvents(&louis);
		if (louis.isMoving())
			louis.run();
		g.drawTest();
		g.drawSpriteEntity(louis);
		g.display();
	}
    return 0;
}