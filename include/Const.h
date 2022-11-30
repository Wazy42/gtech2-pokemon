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

// Pause menu
#define PAUSE_MENU_TEXTURE_PATH "assets/gui/pause_menu.png"
#define RESUME_BUTTON_RECT sf::IntRect(253, 426, 716, 86)
#define MAIN_MENU_BUTTON_RECT sf::IntRect(253, 542, 716, 86)
#define SAVE_AND_QUIT_BUTTON_RECT sf::IntRect(253, 658, 716, 86)

// Map
#define MAP_TILE_SIZE 16
#define MAP_TILE_SCALE (TILE_SIZE / MAP_TILE_SIZE)
#define MAP_TEXTURE_PATH "assets/map/global.png"
#define MAP_SPRITE_COORDS(id) sf::IntRect((id % 148) * MAP_TILE_SIZE, (int)(id / 148) * MAP_TILE_SIZE, MAP_TILE_SIZE, MAP_TILE_SIZE)
#define MAP_SPAWN_PATH "data/spawn.map"
#define LAYER_OBSTACLES 4 // Rendered above the player
#define LAYER_DECORATIONS 3 // Rendered above the player
#define LAYER_SPAWN 2 // Rendered below the player
#define LAYER_WALKABLE 1 // Rendered below the player
#define LAYER_GROUD 0 // Rendered below the player

// Battle
#define BATTLE_TEXTURE_PATH "assets/gui/combat.png"
#define SPAWN_CHANCE 0.5f
#define DOUBLE_CHANCE 0.3f
#define TRIPLE_CHANCE 0.1f
// TODO: Add abilities rect coordinates
#define ABILITY_ONE_BUTON_RECT sf::IntRect(0, 0, 0, 0)
#define ABILITY_TWO_BUTON_RECT sf::IntRect(0, 0, 0, 0)
#define ABILITY_THREE_BUTON_RECT sf::IntRect(0, 0, 0, 0)
#define ABILITY_FOUR_BUTON_RECT sf::IntRect(0, 0, 0, 0)

// Player
#define PLAYER_SIZE 64
#define PLAYER_SCALE (TILE_SIZE / PLAYER_SIZE)
#define PLAYER_TEXTURE_PATH "assets/player/player.png"
#define PLAYER_ANIM_COORDS(dir) { sf::IntRect(0, dir * 64, 64, 64), sf::IntRect(64, dir * 64, 64, 64), sf::IntRect(128, dir * 64, 64, 64), sf::IntRect(192, dir * 64, 64, 64)}
#define PLAYER_WALK_SPEED 1
#define PLAYER_RUN_SPEED 2

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
#define FONT_SIZE_GAME 20
#define FONT_SIZE_MENU 50
#define FONT_COLOR sf::Color::Black
