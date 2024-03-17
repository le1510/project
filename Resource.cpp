#include "Resource.hpp"

TTF_Font* Resource::FONT_24;

SDL_Texture* Resource::TX_PLAYER;
SDL_Texture* Resource::TX_PLAYER_GUN;
SDL_Texture* Resource::TX_PLAYER_BULLET;

SDL_Texture* Resource::TX_MAP_BACKGROUND;
SDL_Texture* Resource::TX_MAP_TOWER;

SDL_Texture* Resource::TX_GOBLIN_ATTACK;
SDL_Texture* Resource::TX_GOBLIN_DEATH;
SDL_Texture* Resource::TX_GOBLIN_WALK;

SDL_Texture* Resource::TX_MUSHROOM_ATTACK;
SDL_Texture* Resource::TX_MUSHROOM_DEATH;
SDL_Texture* Resource::TX_MUSHROOM_WALK;

SDL_Texture* Resource::TX_SKELETON_ATTACK;
SDL_Texture* Resource::TX_SKELETON_DEATH;
SDL_Texture* Resource::TX_SKELETON_WALK;

SDL_Texture* Resource::LoadTextureFromFile(const std::string& path, SDL_Renderer* renderer)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());

	std::cout << "Loaded texture from " << path << std::endl;

	return texture;
}
/*
TTF_Font* Resource::LoadFontFromFile(const std::string& path, int size)
{
	std::cout << "Loaded font from " << path << std::endl;

	return TTF_OpenFont(path.c_str(), size);
}
*/
void Resource::LoadAllData(SDL_Renderer* renderer)
{
	//FONT_24					= LoadFontFromFile(RES_FONT, 24);

	TX_PLAYER				= LoadTextureFromFile(RES_TX_PLAYER, renderer);
	TX_PLAYER_GUN			= LoadTextureFromFile(RES_TX_PLAYER_GUN, renderer);
	TX_PLAYER_BULLET		= LoadTextureFromFile(RES_TX_PLAYER_BULLET, renderer);

	TX_MAP_BACKGROUND		= LoadTextureFromFile(RES_TX_MAP_BACKGROUND, renderer);
	TX_MAP_TOWER			= LoadTextureFromFile(RES_TX_MAP_TOWER, renderer);

	TX_GOBLIN_ATTACK		= LoadTextureFromFile(RES_TX_GOBLIN_ATTACK, renderer);
	TX_GOBLIN_DEATH			= LoadTextureFromFile(RES_TX_GOBLIN_DEATH, renderer);
	TX_GOBLIN_WALK			= LoadTextureFromFile(RES_TX_GOBLIN_WALK, renderer);

	TX_MUSHROOM_ATTACK		= LoadTextureFromFile(RES_TX_MUSHROOM_ATTACK, renderer);
	TX_MUSHROOM_DEATH		= LoadTextureFromFile(RES_TX_MUSHROOM_DEATH, renderer);
	TX_MUSHROOM_WALK		= LoadTextureFromFile(RES_TX_MUSHROOM_WALK, renderer);

	TX_SKELETON_ATTACK		= LoadTextureFromFile(RES_TX_SKELETON_ATTACK, renderer);
	TX_SKELETON_DEATH		= LoadTextureFromFile(RES_TX_SKELETON_DEATH, renderer);
	TX_SKELETON_WALK		= LoadTextureFromFile(RES_TX_SKELETON_WALK, renderer);
}
