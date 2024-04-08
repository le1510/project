#pragma once

#include "../Config.hpp"
#include "../components/Text.hpp"
#include "../scenes/BaseScene.hpp"

class MenuScene final : public BaseScene
{
private:
	Text* m_title;//tiêu đề
	Text* m_playText;//chơi
	Text* m_scoreText;//điểm số cao nhất
	Text* m_exitText;//thóat
	SDL_Point m_mousePosition;//điểm chuột hiện tại trên màn hình

public:
	MenuScene();
	~MenuScene() = default;

	void HandleEvent(SDL_Event) override;//xử lý sự kiện
	void Update(float) override;//cập nhật
	void Render(SDL_Renderer*) override;//vẽ cảnh lên màn hình
};
