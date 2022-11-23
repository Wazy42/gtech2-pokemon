#include "Window.h"
#include "Player.h"
#include <iostream>

int main()
{
    Window w;
	
    sf::Texture texture;
    if (!texture.loadFromFile("assets/char1_walk.png"))
    {
		std::cout << "Error loading texture" << std::endl;
    }
	
    Louis louis = Louis(texture);

	int posSprite = 0;
	while (w.isRunning())
	{
		w.clear();
		if (posSprite % 20 == 0)
		{
			louis.nextAnimationSprite();
			posSprite = 0;
		}
		posSprite++;
		w.drawSpriteEntity(louis);
		w.display();
	}
    return 0;
}