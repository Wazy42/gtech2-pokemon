#pragma once
//Constants file

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 800

#define FPS_LIMIT 60

#define TILE_SIZE 64

// Map
#define MAP_TILE_SIZE 16
#define MAP_TILE_SCALE TILE_SIZE / MAP_TILE_SIZE

// Player
#define SPRITE_SIZE 32
#define SPRITE_SCALE TILE_SIZE / SPRITE_SIZE
#define PLAYER_TEXTURE_PATH "assets/char1_walk.png"
#define PLAYER_ANIM_COORDS(dir) { sf::IntRect(0, dir * 32, 32, 32), sf::IntRect(32, dir * 32, 32, 32), sf::IntRect(64, dir * 32, 32, 32), sf::IntRect(96, dir * 32, 32, 32), sf::IntRect(128, dir * 32, 32, 32), sf::IntRect(160, dir * 32, 32, 32), sf::IntRect(192, dir * 32, 32, 32), sf::IntRect(224, dir * 32, 32, 32)}
#define PLAYER_MOVEMENT_STEP 2

#define isPressed(a) sf::Keyboard::isKeyPressed(a)
#define Z_PRESSED isPressed(sf::Keyboard::Z)
#define Q_PRESSED isPressed(sf::Keyboard::Q)
#define S_PRESSED isPressed(sf::Keyboard::S)
#define D_PRESSED isPressed(sf::Keyboard::D)
#define UP_PRESSED isPressed(sf::Keyboard::Up)
#define LEFT_PRESSED isPressed(sf::Keyboard::Left)
#define DOWN_PRESSED isPressed(sf::Keyboard::Down)
#define RIGHT_PRESSED isPressed(sf::Keyboard::Right)
#define ESC_PRESSED isPressed(sf::Keyboard::Escape)