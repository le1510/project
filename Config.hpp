#pragma once

//include sdl2
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mixer.h>
#include<SDL2/SDL_ttf.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#define WINDOW_TITLE "Dino Gun"
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 680

#define RES_FONT "res/fonts/monogram-extended.ttf"

#define RES_SFX_SHOT "res/sfx/shot.mp3"
#define RES_SFX_BACKGROUND "res/sfx/background_music.mp3"

#define RES_TX_PLAYER "res/textures/player/dino.png"
#define RES_TX_PLAYER_GUN "res/textures/player/gun.png"
#define RES_TX_PLAYER_BULLET "res/textures/player/bullet.png"

#define RES_TX_MAP_BACKGROUND "res/textures/map/background.jpg"
#define RES_TX_MAP_TOWER "res/textures/map/tower.png"

#define RES_TX_BACKGROUND_2 "res/textures/map/background-2.png"
#define RES_TX_BACKGROUND_3 "res/textures/map/background-3.png"
#define RES_TX_BACKGROUND_4 "res/textures/map/background-4.png"
#define RES_TX_BACKGROUND_5 "res/textures/map/background-5.png"


#define RES_TX_GOBLIN_ATTACK "res/textures/monsters/goblin/attack.png"
#define RES_TX_GOBLIN_DEATH "res/textures/monsters/goblin/death.png"
#define RES_TX_GOBLIN_WALK "res/textures/monsters/goblin/walk.png"

#define RES_TX_MUSHROOM_ATTACK "res/textures/monsters/mushroom/attack.png"
#define RES_TX_MUSHROOM_DEATH "res/textures/monsters/mushroom/death.png"
#define RES_TX_MUSHROOM_WALK "res/textures/monsters/mushroom/walk.png"

#define RES_TX_SKELETON_ATTACK "res/textures/monsters/skeleton/attack.png"
#define RES_TX_SKELETON_DEATH "res/textures/monsters/skeleton/death.png"
#define RES_TX_SKELETON_WALK "res/textures/monsters/skeleton/walk.png"

#define RES_TX_ON "res/textures/icon/on.png"
#define RES_TX_OFF "res/textures/icon/off.png"
