#include "../include/Player.hpp"

Player::Player(const sf::Texture& texture) :
	AnimatedEntity(texture, PLAYER_ANIM_SPRITE_DOWN)
{
	this->setSpritePosition((WINDOW_WIDTH - PLAYER_SPRITE_SIZE * PLAYER_SIZE_SCALE) / 2, (WINDOW_HEIGHT - PLAYER_SPRITE_SIZE * PLAYER_SIZE_SCALE) / 2);
	this->sprite.setScale(PLAYER_SIZE_SCALE, PLAYER_SIZE_SCALE);
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

void Player::move(sf::Vector2i movement)
{
	this->posX += movement.x;
	this->posY += movement.y;
}

void Player::run()
{
	// Move the player in the right direction
	switch (this->dir)
	{
	case Up:
		this->move(sf::Vector2i(0, -PLAYER_MOVEMENT_STEP));
		break;
	case Down:
		this->move(sf::Vector2i(0, PLAYER_MOVEMENT_STEP));
		break;
	case Left:
		this->move(sf::Vector2i(-PLAYER_MOVEMENT_STEP, 0));
		break;
	case Right:
		this->move(sf::Vector2i(PLAYER_MOVEMENT_STEP, 0));
		break;
	}
	
	// If the player is in the middle of a tile, the animation is stopped
	if (this->posX % TILE_SIZE == 0 && this->posY % TILE_SIZE == 0)
	{
		this->setMoving(false);
		this->setActualFrame(0);
	}
	else
	{
		this->runSprite();
	}		
}

void Player::handleEvents()
{	
	if (!this->moving) {
		if (Z_PRESSED || UP_PRESSED)
		{
			this->faceUp();
			this->setMoving(true);
		}
		else if (S_PRESSED || DOWN_PRESSED)
		{
			this->faceDown();
			this->setMoving(true);
		}
		else if (Q_PRESSED || LEFT_PRESSED)
		{
			this->faceLeft();
			this->setMoving(true);
		}
		else if (D_PRESSED || RIGHT_PRESSED)
		{
			this->faceRight();
			this->setMoving(true);
		}
	}
	else {
		this->run();
	}
}