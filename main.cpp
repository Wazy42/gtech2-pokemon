#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Const.h"
#include "Player.hpp"
#include "AnimatedSpriteEntity.hpp"
#include "SpriteEntity.hpp"
#include <iostream>

#include "Pokemon.hpp"
#include "Ability.hpp"



int main()
{
    Game g;

    sf::Texture texture;
    if (!texture.loadFromFile(PLAYER_TEXTURE_PATH))
    {
		std::cout << "Error loading texture" << std::endl;
    }
	
	Player louis = Player(texture);

	int posSprite = 0;
	while (g.isRunning())
	{
		g.clear();
		g.handleEvents(&louis);
		if (posSprite == 10)
		{
			louis.nextAnimationSprite();
			posSprite = 0;
		}
		posSprite++;
		g.drawSpriteEntity(louis);
		g.display();
	}
    return 0;
}