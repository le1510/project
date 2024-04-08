#pragma once

#include "../Config.hpp"
#include "../components/Text.hpp"
#include "../scenes/BaseScene.hpp"

class GameOverScene : public BaseScene
{
private:
	Text* m_title;//  chữ hiện thị tiêu đề của cảnh game over
	Text* m_scoreText;//hiển thị chữ score

	std::string m_scoreStr;//lưu điểm số dưới dạng chuỗi

	float m_elapsedTime;//thời gian trôi qua từ khi cảnh game được hiển thị

public:
	GameOverScene(int);//hàm khởi tạo đối tượng manf hình game over
	~GameOverScene() = default;

	void HandleEvent(SDL_Event) override;
	void Update(float) override;
	void Render(SDL_Renderer*) override;

	void SaveScore(int);//lưu điểm số vào một tệp
};
