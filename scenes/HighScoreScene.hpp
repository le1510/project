#pragma once

#include "../Config.hpp"
#include "../components/Text.hpp"
#include "../scenes/BaseScene.hpp"
//đại diện cho cảnh trong trò chơi hiển thị bảng xếp hạng cao nhát
class HighScoreScene final : public BaseScene
{
private:
	Text* m_title; //hiện thị tiêu đề của cảnh bảng xêos hạng
	std::vector<int> m_scores; //vector chứa các điểm số
	float m_elapsedTime;//thoiwf gian trôi qua

public:
	HighScoreScene();
	~HighScoreScene() = default;

	void HandleEvent(SDL_Event) override;
	void Update(float) override;
	void Render(SDL_Renderer*) override;

	void LoadFromFile();//tải dữ liệu điểm từ tệp lưu trữ
};
