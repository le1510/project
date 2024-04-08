#include "GameOverScene.hpp"
#include "MenuScene.hpp"
#include "../Game.hpp"
#include "../Resource.hpp"
#include "../misc/Utils.hpp"


GameOverScene::GameOverScene(int score) :
	m_elapsedTime(0.f)//thời gian trôi qua khi cảnh gameover được hiển thi
{
	this->m_scoreStr = "Score: " + toFiveDigitString(score);//điểm: điểm dưới dạng string 5 chữ số

	this->m_title = new Text(Resource::FONT_96);//kích thước chữ tiêu đêf là 96
	this->m_title->SetPosition({ 438, 180 });//vị trí đăt tiêu đề

	this->m_scoreText = new Text(Resource::FONT_48);//kích thước đặt chữ điểm
	this->m_scoreText->SetPosition({ 492, 300 });//vị trí đặt

	this->SaveScore(score);//lưu điểm
}

void GameOverScene::HandleEvent(SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT && this->m_elapsedTime > 0.5f)//nếu con chuột nhấn chột xuuoosng và nhấn nút trái, thời gian trôi qua hơn 0.5 s
		{
			Game::GetInstance()->SetScene(new MenuScene());// chuyển màn hình ra menu
		}
	}
}

void GameOverScene::Update(float delta)
{
	this->m_elapsedTime += delta;//thời gian trôi qua khi cảnh được hiển thị
}

void GameOverScene::Render(SDL_Renderer* renderer)//vẽ đói tượng và chữ lên gameover
{
	this->m_title->RenderText(renderer, "GAME OVER");

	this->m_scoreText->RenderText(renderer, this->m_scoreStr);
}

void GameOverScene::SaveScore(int score)
{
	std::vector<int> scores;
	std::ifstream inputFile("scores.txt");//mở  tệp tin điểm
	int tempScore;

	while (inputFile >> tempScore)
	{
		scores.push_back(tempScore);//thêm điểm vào tệp tin
	}

	inputFile.close();

	scores.push_back(score);//điểm số mới đc thêm vào vector

	std::sort(scores.rbegin(), scores.rend());// sắp xếp điểm theo thứ tự giảm dần

	std::ofstream outputFile("scores.txt");//ghi vào tệp tin
	for (size_t i = 0; i < std::min(scores.size(), static_cast<size_t>(5)); ++i)
	{
		outputFile << scores[i] << std::endl;//chỉ ra 5 điểm số cao nhất được ghi vào tệp tin
	}
	outputFile.close();//đóng tệp tin
}
