#pragma once

#include "Config.hpp"
//chứa các thông tin như font chữ âm thanh hình ảnh phương thức tải tài nguyên từ tệp tin trên đĩa vào bộ nhớ và sử dụng trong trò chơi
class Resource
{
public:
	static TTF_Font*	FONT_24;//con trỏ đến đối tượng ttf font trong kiẻu dữ liệu thư viện sdl2
    static TTF_Font*	FONT_48;
    static TTF_Font*	FONT_96;

    static Mix_Chunk* SFX_SHOT;//con trỏ trỏ đến thư viện sdl mixer xử lý âm thanh trong ssld, shot là âm thanh súng, background là âm thanh nhạc nền
    static Mix_Music* SFX_BACKGROUND;


	static SDL_Texture* TX_PLAYER;//đại diện óch hình ảnh được tải lên bộ nhớ vẽ đồ họa
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
	static SDL_Texture* LoadTextureFromFile(const std::string& path, SDL_Renderer* renderer);//tải 1 hình ảnh từ tệp tin trên đĩa vào bộ nhứo dưới dạng1 đói tượng, aht; đường dãn tới tệp tin, con trỏ đến dl_renderer để tạo và quản lý các đối tượng sdl_texture

	static TTF_Font* LoadFontFromFile(const std::string& path, int size);// tải font chữ từ 1 tệp tin dưới đường dẫn là patth, kích thước font chữ

    static Mix_Music* LoadMusicFromFile(const std::string&path);
    static Mix_Chunk* LoadSFXFromFile(const std::string &path);// tải 1 file âm thanh từ 1 đường trên đĩa để tải âm thanh lên
	static void LoadAllData(SDL_Renderer* renderer);// tải tất cả tai fnguyeen âm thanh hình ảnh font chữ âm thanh nhận đầu vào là con trỏ đến dl_renderer để tạo và quản lý đối tượng dl_texture, tải tất cả lên bộ
};
