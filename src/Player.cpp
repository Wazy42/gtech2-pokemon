#include "../include/Player.hpp"

Player::Player(const sf::Texture& texture) :
	AnimatedSpriteEntity(texture, PLAYER_ANIM_SPRITE_DOWN)
{
	this->spriteEntity.setScale(2, 2);
	this->nextFrameSprite();
}

void Player::faceRight()
{
	this->dir = Direction::Right;
	this->animationSprite = PLAYER_ANIM_SPRITE_RIGHT;
}

void Player::faceLeft()
{
	this->dir = Direction::Left;
	this->animationSprite = PLAYER_ANIM_SPRITE_LEFT;
}

void Player::faceUp()
{
	this->dir = Direction::Up;
	this->animationSprite = PLAYER_ANIM_SPRITE_UP;
}

void Player::faceDown()
{
	this->dir = Direction::Down;
	this->animationSprite = PLAYER_ANIM_SPRITE_DOWN;
}

void Player::run()
{
	// Move the player in the right direction
	switch (this->dir)
	{
	case Up:
		this->moveSprite(0, -PLAYER_MOVEMENT_STEP);
		break;
	case Down:
		this->moveSprite(0, PLAYER_MOVEMENT_STEP);
		break;
	case Left:
		this->moveSprite(-PLAYER_MOVEMENT_STEP, 0);
		break;
	case Right:
		this->moveSprite(PLAYER_MOVEMENT_STEP, 0);
		break;
	}
	
	// If the player is in the middle of a tile, the animation is stopped
	int x = (int)this->getSpritePosition().x;
	int y = (int)this->getSpritePosition().y;
	if (x % TILE_SIZE == 0 && y % TILE_SIZE == 0)
	{
		this->setMoving(false);
		this->setActualFrame(0);
	}
	else
	{
		this->runSprite();
	}		
}

void Player::handleKeyPressed(sf::Event event)
{
	if (this->isMoving())
		return;
	
	if (event.KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
		case sf::Keyboard::Z:
			this->setMoving(true);
			this->faceUp();
			break;

		case sf::Keyboard::Left:
		case sf::Keyboard::Q:
			this->setMoving(true);
			this->faceLeft();
			break;

		case sf::Keyboard::Down:
		case sf::Keyboard::S:
			this->setMoving(true);
			this->faceDown();
			break;

		case sf::Keyboard::Right:
		case sf::Keyboard::D:
			this->setMoving(true);
			this->faceRight();
			break;
		}
	}
	else if (event.KeyReleased)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
		case sf::Keyboard::Left:
		case sf::Keyboard::Down:
		case sf::Keyboard::Right:
		case sf::Keyboard::Z:
		case sf::Keyboard::Q:
		case sf::Keyboard::S:
		case sf::Keyboard::D:
			this->setMoving(false);
			this->setActualFrame(0);
		}
	}
}