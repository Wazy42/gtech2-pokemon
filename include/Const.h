#pragma once
//Constants file

// Window
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define FPS_LIMIT 60

#define TILE_SIZE 64

// Main menu
#define MAIN_MENU_TEXTURE_PATH "assets/gui/main_menu.png"
#define PLAY_BUTTON_RECT sf::IntRect(543, 478, 834, 125)
#define SETTINGS_BUTTON_RECT sf::IntRect(638, 640, 645, 125)
#define QUIT_BUTTON_RECT sf::IntRect(638, 801, 645, 125)

// Map
#define MAP_TILE_SIZE 16
#define MAP_TILE_SCALE TILE_SIZE / MAP_TILE_SIZE
#define MAP_GLOBAL_TEXTURE_PATH "assets/map/global.png"
#define MAP_NATURE_TEXTUTE_PATH "assets/map/nature.png"
#define MAP_SPRITE_COORDS(id) sf::IntRect((id % 148) * MAP_TILE_SIZE, (int)(id / 148) * MAP_TILE_SIZE, MAP_TILE_SIZE, MAP_TILE_SIZE)
#define MAP_SPAWN_PATH "data/spawn.map"

// Player
#define SPRITE_SIZE 32
#define SPRITE_SCALE TILE_SIZE / SPRITE_SIZE
#define PLAYER_TEXTURE_PATH "assets/player.png"
#define PLAYER_ANIM_COORDS(dir) { sf::IntRect(0, dir * 32, 32, 32), sf::IntRect(32, dir * 32, 32, 32), sf::IntRect(64, dir * 32, 32, 32), sf::IntRect(96, dir * 32, 32, 32), sf::IntRect(128, dir * 32, 32, 32), sf::IntRect(160, dir * 32, 32, 32), sf::IntRect(192, dir * 32, 32, 32), sf::IntRect(224, dir * 32, 32, 32)}
#define PLAYER_MOVEMENT_STEP 2

// Keys
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

// Font
#define FONT_POKEMON_HOLLOW_PATH "assets/font/PokemonHollow.ttf"
#define FONT_POKEMON_SOLID_PATH "assets/font/PokemonSolid.ttf"
#define FONT_SPINWERAD_PATH "assets/font/spinwerad.ttf"
#define FONT_SPINWERAD_C_PATH "assets/font/spinweradC.ttf"
#define FONT_SIZE 20
#define FONT_COLOR sf::Color::Black
