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
	static SDL_Texture* TX_PLAYER_GUN;
	static SDL_Texture* TX_PLAYER_BULLET;//dan

	static SDL_Texture* TX_MAP_BACKGROUND;
	static SDL_Texture* TX_MAP_TOWER;

	static SDL_Texture* TX_GOBLIN_ATTACK;
	static SDL_Texture* TX_GOBLIN_DEATH;
	static SDL_Texture* TX_GOBLIN_WALK;

	static SDL_Texture* TX_MUSHROOM_ATTACK;
	static SDL_Texture* TX_MUSHROOM_DEATH;
	static SDL_Texture* TX_MUSHROOM_WALK;

	static SDL_Texture* TX_SKELETON_ATTACK;
	static SDL_Texture* TX_SKELETON_DEATH;
	static SDL_Texture* TX_SKELETON_WALK;

public:
	static SDL_Texture* LoadTextureFromFile(const std::string& path, SDL_Renderer* renderer);

	static TTF_Font* LoadFontFromFile(const std::string& path, int size);

    static Mix_Music* LoadMusicFromFile(const std::string&path);
    static Mix_Chunk* LoadSFXFromFile(const std::string &path);
	static void LoadAllData(SDL_Renderer* renderer);
};
