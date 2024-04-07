#pragma once

//include sdl2
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mixer.h>
#include<SDL2/SDL_ttf.h>

#include<iostream>
#include<vector>
#include <ctime>
#define WINDOW_TITLE "Dino Gun" // tiêu đề cửa sổ trò
#define WINDOW_WIDTH 1200 //chiều rộng cửa sổ trò chơi
#define WINDOW_HEIGHT 680 // chiều cao cửa sổ trò chơi

#define RES_FONT "res/fonts/monogram-extended.ttf" // đường dẫn tới tệp tin

#define RES_SFX_SHOT "res/sfx/shot.mp3"
#define RES_SFX_BACKGROUND "res/sfx/background_music.mp3"

#define RES_TX_PLAYER "res/textures/player/dino.png"
#define RES_TX_PLAYER_GUN "res/textures/player/gun.png"
#define RES_TX_PLAYER_BULLET "res/textures/player/bullet.png"

#define RES_TX_MAP_BACKGROUND "res/textures/map/background.jpg"
#define RES_TX_MAP_TOWER "res/textures/map/tower.png"

#define RES_TX_GOBLIN_ATTACK "res/textures/monsters/goblin/attack.png"
#define RES_TX_GOBLIN_DEATH "res/textures/monsters/goblin/death.png"
#define RES_TX_GOBLIN_WALK "res/textures/monsters/goblin/walk.png"

#define RES_TX_MUSHROOM_ATTACK "res/textures/monsters/mushroom/attack.png"
#define RES_TX_MUSHROOM_DEATH "res/textures/monsters/mushroom/death.png"
#define RES_TX_MUSHROOM_WALK "res/textures/monsters/mushroom/walk.png"

#define RES_TX_SKELETON_ATTACK "res/textures/monsters/skeleton/attack.png"
#define RES_TX_SKELETON_DEATH "res/textures/monsters/skeleton/death.png"
#define RES_TX_SKELETON_WALK "res/textures/monsters/skeleton/walk.png"
