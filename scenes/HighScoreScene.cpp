#include "MenuScene.hpp"
#include "HighScoreScene.hpp"
#include "HighScoreScene.hpp"
#include "../Resource.hpp"
#include "../Game.hpp"

HighScoreScene::HighScoreScene() :
	m_elapsedTime(0.f)//thời gian trôi qua khi bảng xép hạng hiển thị
{
	this->m_title = new Text(Resource::FONT_96);//phông chữ của game
	this->m_title->SetPosition({ 420, 120 });//vị trí đặt phông chữ

	this->LoadFromFile();//tải dữ liệu từ tệp tin và lưu trữ vào vector m_scores
}

void HighScoreScene::HandleEvent(SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)//kiểm tra xem phải nháan chuột không
	{
		if (e.button.button == SDL_BUTTON_LEFT && this->m_elapsedTime > 0.5f)//xem phải nhấn chuột trái và thời gin trôi qua có lớn hơn 0.5s không
		{
			Game::GetInstance()->SetScene(new MenuScene());//trở về menu
		}
	}
}

void HighScoreScene::Update(float delta)
{
	this->m_elapsedTime += delta;//update thời gian trôi qua
}

void HighScoreScene::Render(SDL_Renderer* renderer)//vẽ đối tượng lên màn hinhf
{
	this->m_title->RenderText(renderer, "High Score");

	int startY = 250;//vị trí của điểm số dầu tiên
	int lineHeight = 60;//khoảng cách giữa các điểm số

	for (size_t i = 0; i < m_scores.size(); ++i)
	{
		std::string scoreText = "Score " + std::to_string(i + 1) + ": " + std::to_string(m_scores[i]);//gọi ra điểm sôs có xếp hạng

		Text* scoreDisplay = new Text(Resource::FONT_48);//viết theo font chữ 48
		scoreDisplay->SetPosition({ 492, startY + static_cast<int>(i) * lineHeight });//dặt vị tí tên bắt đầu từ statrt y và các chữ tiếp theo thì +60
		scoreDisplay->RenderText(renderer, scoreText);//vẽ điểm lên màn hình
	}
}

void HighScoreScene::LoadFromFile()//tải load dữ liệu từ file
{
	std::ifstream inputFile("scores.txt");

	int score;
	while (inputFile >> score)
	{
		m_scores.push_back(score);//đọc điểm mơi svaf thêm vào
	}

	inputFile.close();
}
