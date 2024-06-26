#include "Resource.hpp"
TTF_Font* Resource::FONT_24;
TTF_Font* Resource::FONT_48;
TTF_Font* Resource::FONT_96;
Mix_Chunk* Resource::SFX_SHOT;
Mix_Music* Resource::SFX_BACKGROUND;

SDL_Texture* Resource::TX_PLAYER;
SDL_Texture* Resource::TX_PLAYERRED;
SDL_Texture* Resource::TX_PLAYERBLUE;
SDL_Texture* Resource::TX_PLAYERGREEN;
SDL_Texture* Resource::TX_PLAYERYELLOW;

SDL_Texture* Resource::TX_PLAYER_GUN;
SDL_Texture* Resource::TX_PLAYER_BULLET;

SDL_Texture* Resource::TX_MAP_BACKGROUND;
SDL_Texture* Resource::TX_MAP_TOWER;
SDL_Texture* Resource::TX_MAP_CANNON;


SDL_Texture* Resource::TX_BACKGROUND_2;
SDL_Texture* Resource::TX_BACKGROUND_3;
SDL_Texture* Resource::TX_BACKGROUND_4;
SDL_Texture* Resource::TX_BACKGROUND_5;
SDL_Texture* Resource::TX_BACKGROUND_6;
SDL_Texture* Resource::TX_BACKGROUND_7;
SDL_Texture* Resource::TX_BACKGROUND_8;
SDL_Texture* Resource::TX_BACKGROUND_9;






SDL_Texture* Resource::TX_GOBLIN_ATTACK;
SDL_Texture* Resource::TX_GOBLIN_DEATH;
SDL_Texture* Resource::TX_GOBLIN_WALK;

SDL_Texture* Resource::TX_MUSHROOM_ATTACK;
SDL_Texture* Resource::TX_MUSHROOM_DEATH;
SDL_Texture* Resource::TX_MUSHROOM_WALK;

SDL_Texture* Resource::TX_SKELETON_ATTACK;
SDL_Texture* Resource::TX_SKELETON_DEATH;
SDL_Texture* Resource::TX_SKELETON_WALK;
SDL_Texture* Resource::TX_ON;
SDL_Texture* Resource::TX_OFF;
SDL_Texture* Resource::TX_CONTINUE;
SDL_Texture* Resource::TX_PAUSE;
SDL_Texture* Resource::TX_END;





bool Resource::IsSound=true;

SDL_Texture* Resource::LoadTextureFromFile(const std::string& path, SDL_Renderer* renderer)
{
    SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());

    std::cout << "Loaded texture from " << path << std::endl;

    return texture;
}

TTF_Font* Resource::LoadFontFromFile(const std::string& path, int size)
{
    std::cout << "Loaded font from " << path << std::endl;

    return TTF_OpenFont(path.c_str(), size);
}

Mix_Music* Resource::LoadMusicFromFile(const std::string& path)
{
    std::cout << "Loaded music from " << path << std::endl;

    return Mix_LoadMUS(path.c_str());
}

Mix_Chunk* Resource::LoadSFXFromFile(const std::string& path)
{
    std::cout << "Loaded SFX from " << path << std::endl;

    return Mix_LoadWAV(path.c_str());
}

void Resource::LoadAllData(SDL_Renderer* renderer)
{
    FONT_24					= LoadFontFromFile(RES_FONT, 24);
    FONT_48					= LoadFontFromFile(RES_FONT, 48);
    FONT_96					= LoadFontFromFile(RES_FONT, 96);


    SFX_SHOT                =LoadSFXFromFile(RES_SFX_SHOT);
    SFX_BACKGROUND          =LoadMusicFromFile(RES_SFX_BACKGROUND);

    TX_PLAYER				= LoadTextureFromFile(RES_TX_PLAYER, renderer);
    TX_PLAYERRED			= LoadTextureFromFile(RES_TX_PLAYERRED, renderer);
    TX_PLAYERBLUE			= LoadTextureFromFile(RES_TX_PLAYERBLUE, renderer);
    TX_PLAYERYELLOW			= LoadTextureFromFile(RES_TX_PLAYERYELLOW, renderer);
    TX_PLAYERGREEN			= LoadTextureFromFile(RES_TX_PLAYERGREEN, renderer);

    TX_PLAYER_GUN			= LoadTextureFromFile(RES_TX_PLAYER_GUN, renderer);
    TX_PLAYER_BULLET		= LoadTextureFromFile(RES_TX_PLAYER_BULLET, renderer);

    TX_MAP_BACKGROUND		= LoadTextureFromFile(RES_TX_MAP_BACKGROUND, renderer);
    TX_MAP_TOWER			= LoadTextureFromFile(RES_TX_MAP_TOWER, renderer);
    TX_MAP_CANNON			= LoadTextureFromFile(RES_TX_MAP_CANNON, renderer);


    TX_BACKGROUND_2         = LoadTextureFromFile(RES_TX_BACKGROUND_2, renderer);
    TX_BACKGROUND_3         = LoadTextureFromFile(RES_TX_BACKGROUND_3, renderer);
    TX_BACKGROUND_4         = LoadTextureFromFile(RES_TX_BACKGROUND_4, renderer);
    TX_BACKGROUND_5         = LoadTextureFromFile(RES_TX_BACKGROUND_5, renderer);
    TX_BACKGROUND_6         = LoadTextureFromFile(RES_TX_BACKGROUND_6, renderer);
    TX_BACKGROUND_7         = LoadTextureFromFile(RES_TX_BACKGROUND_7, renderer);
    TX_BACKGROUND_8         = LoadTextureFromFile(RES_TX_BACKGROUND_8, renderer);
    TX_BACKGROUND_9         = LoadTextureFromFile(RES_TX_BACKGROUND_9, renderer);









    TX_GOBLIN_ATTACK		= LoadTextureFromFile(RES_TX_GOBLIN_ATTACK, renderer);
    TX_GOBLIN_DEATH			= LoadTextureFromFile(RES_TX_GOBLIN_DEATH, renderer);
    TX_GOBLIN_WALK			= LoadTextureFromFile(RES_TX_GOBLIN_WALK, renderer);

    TX_MUSHROOM_ATTACK		= LoadTextureFromFile(RES_TX_MUSHROOM_ATTACK, renderer);
    TX_MUSHROOM_DEATH		= LoadTextureFromFile(RES_TX_MUSHROOM_DEATH, renderer);
    TX_MUSHROOM_WALK		= LoadTextureFromFile(RES_TX_MUSHROOM_WALK, renderer);

    TX_SKELETON_ATTACK		= LoadTextureFromFile(RES_TX_SKELETON_ATTACK, renderer);
    TX_SKELETON_DEATH		= LoadTextureFromFile(RES_TX_SKELETON_DEATH, renderer);
    TX_SKELETON_WALK		= LoadTextureFromFile(RES_TX_SKELETON_WALK, renderer);
    TX_ON                   = LoadTextureFromFile(RES_TX_ON, renderer);
    TX_OFF                  = LoadTextureFromFile(RES_TX_OFF, renderer);
    TX_CONTINUE             = LoadTextureFromFile(RES_TX_CONTINUE, renderer);
    TX_PAUSE                = LoadTextureFromFile(RES_TX_PAUSE, renderer);
    TX_END                  = LoadTextureFromFile(RES_TX_END, renderer);







}
