#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Const.h"
#include "Player.h"
#include "AnimatedSpriteEntity.h"
#include "SpriteEntity.h"
#include <iostream>



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