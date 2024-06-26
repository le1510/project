#pragma once

#include "Config.hpp"
class Resource
{
public:



    static TTF_Font*	FONT_24;
    static TTF_Font*	FONT_48;
    static TTF_Font*	FONT_96;


    static Mix_Chunk* SFX_SHOT;
    static Mix_Music* SFX_BACKGROUND;


    static SDL_Texture* TX_PLAYER;
    static SDL_Texture* TX_PLAYERRED;
    static SDL_Texture* TX_PLAYERGREEN;
    static SDL_Texture* TX_PLAYERYELLOW;
    static SDL_Texture* TX_PLAYERBLUE;

    static SDL_Texture* TX_PLAYER_GUN;
    static SDL_Texture* TX_PLAYER_BULLET;

    static SDL_Texture* TX_MAP_BACKGROUND;
    static SDL_Texture* TX_MAP_TOWER;
    static SDL_Texture* TX_MAP_CANNON;


    static SDL_Texture* TX_BACKGROUND_2;
    static SDL_Texture* TX_BACKGROUND_3;
    static SDL_Texture* TX_BACKGROUND_4;
    static SDL_Texture* TX_BACKGROUND_5;
    static SDL_Texture* TX_BACKGROUND_6;
    static SDL_Texture* TX_BACKGROUND_7;
    static SDL_Texture* TX_BACKGROUND_8;
    static SDL_Texture* TX_BACKGROUND_9;







    static SDL_Texture* TX_GOBLIN_ATTACK;
    static SDL_Texture* TX_GOBLIN_DEATH;
    static SDL_Texture* TX_GOBLIN_WALK;

    static SDL_Texture* TX_MUSHROOM_ATTACK;
    static SDL_Texture* TX_MUSHROOM_DEATH;
    static SDL_Texture* TX_MUSHROOM_WALK;

    static SDL_Texture* TX_SKELETON_ATTACK;
    static SDL_Texture* TX_SKELETON_DEATH;
    static SDL_Texture* TX_SKELETON_WALK;

    static bool IsSound;

    static SDL_Texture* TX_ON;
    static SDL_Texture* TX_OFF;
    static SDL_Texture* TX_PAUSE;
    static SDL_Texture* TX_CONTINUE;
    static SDL_Texture* TX_END;
public:
    static SDL_Texture* LoadTextureFromFile(const std::string& path, SDL_Renderer* renderer);

    static TTF_Font* LoadFontFromFile(const std::string& path, int size);

    static Mix_Music* LoadMusicFromFile(const std::string&path);
    static Mix_Chunk* LoadSFXFromFile(const std::string &path);
    static void LoadAllData(SDL_Renderer* renderer);
};

