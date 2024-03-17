#pragma once

#include "Config.hpp"

class Resource
{
public:
	static TTF_Font*	FONT_24;

	static SDL_Texture* TX_PLAYER;
	static SDL_Texture* TX_PLAYER_GUN;
	static SDL_Texture* TX_PLAYER_BULLET;

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

	//static TTF_Font* LoadFontFromFile(const std::string& path, int size);

	static void LoadAllData(SDL_Renderer* renderer);
};
