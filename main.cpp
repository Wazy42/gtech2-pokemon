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
		throw std::runtime_error("Error while loading texture");
    }
	
	Player louis = Player(texture);
	
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
			g.managePlayer();
			g.drawInGame();
			break;
		case GameState::InBattle:
			g.drawInBattle();
			break;
		}
		
		g.display();
	}
    return 0;
}