#include "MenuScene.hpp"
#include "PlayScene.hpp"
#include "HighScoreScene.hpp"
#include "../Resource.hpp"
#include "../Game.hpp"

MenuScene::MenuScene() :
	m_mousePosition({0, 0})//thiết lập vị trí ban đầu của chuột là 0 0
{
	this->m_title = new Text(Resource::FONT_96);// tạo chữ menu font c96
	this->m_title->SetPosition({456, 130});//vị trí đặt tiêu đề game

	this->m_playText = new Text(Resource::FONT_48);//font 96
	this->m_playText->SetPosition({ 519, 270 });//vị trí đặt nơi chơi game

	this->m_scoreText = new Text(Resource::FONT_48);
	this->m_scoreText->SetPosition({ 510, 370 });

	this->m_exitText = new Text(Resource::FONT_48);
	this->m_exitText->SetPosition({ 564, 470 });

	Mix_PlayMusic(Resource::SFX_BACKGROUND, -1);//phát nhạc nền trong trò chơi tuwf tệp âm hanh(teeoj tin âm thanh,-1 :âm thanh phát vô hạn )
}

void MenuScene::HandleEvent(SDL_Event e)
{
	this->m_mousePosition.x = e.button.x;// cập nhật vị trí của chuột trong cửa sổ winddow và lưu trữ tọa độ x y của sự kiện chuột
	this->m_mousePosition.y = e.button.y;

	if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)//có phải nhấn chuột và nhấn chuột trái hay không
	{
		if (this->m_playText->IsSelected(this->m_mousePosition))//kiểm tra xem vị trí chuọt có nằm trong vùng chọn playgame không
		{
			Game::GetInstance()->SetScene(new PlayScene());// nếu có thì chuyển sang chế độ chơi game
;		}

		if (this->m_scoreText->IsSelected(this->m_mousePosition))//kiẻm tra xem chọn điẻm cao hất không để chuyển cảnh sang bảng xếp hạng
		{
			Game::GetInstance()->SetScene(new HighScoreScene());
		}

		if (this->m_exitText->IsSelected(this->m_mousePosition))// nhấn ẽxit thì thoát trò chơi
		{
			Game::GetInstance()->Quit();
		}
	}
}

void MenuScene::Update(float delta)
{
	this->m_playText->SetColor({ 255, 255, 255, 255 });
	this->m_scoreText->SetColor({ 255, 255, 255, 255 });
	this->m_exitText->SetColor({ 255, 255, 255, 255 });

	if (this->m_playText->IsSelected(this->m_mousePosition))
	{
		this->m_playText->SetColor({ 255, 0, 0, 255 });
	}

	if (this->m_scoreText->IsSelected(this->m_mousePosition))
	{
		this->m_scoreText->SetColor({ 255, 0, 0, 255 });
	}

	if (this->m_exitText->IsSelected(this->m_mousePosition))
	{
		this->m_exitText->SetColor({ 255, 0, 0, 255 });
	}
}

void MenuScene::Render(SDL_Renderer* renderer)
{
	this->m_title->RenderText(renderer, WINDOW_TITLE);
	this->m_playText->RenderText(renderer, "Play game");
	this->m_scoreText->RenderText(renderer, "High score");
	this->m_exitText->RenderText(renderer, "Exit");
}
