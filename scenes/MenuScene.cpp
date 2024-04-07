#include "MenuScene.hpp"
#include "PlayScene.hpp"
#include "HighScoreScene.hpp"
#include "../Resource.hpp"
#include "../Game.hpp"

MenuScene::MenuScene() :
	m_mousePosition({0, 0})
{
	this->m_title = new Text(Resource::FONT_96);
	this->m_title->SetPosition({456, 130});

	this->m_playText = new Text(Resource::FONT_48);
	this->m_playText->SetPosition({ 519, 270 });

	this->m_scoreText = new Text(Resource::FONT_48);
	this->m_scoreText->SetPosition({ 510, 370 });

	this->m_exitText = new Text(Resource::FONT_48);
	this->m_exitText->SetPosition({ 564, 470 });

	Mix_PlayMusic(Resource::SFX_BACKGROUND, -1);
}

void MenuScene::HandleEvent(SDL_Event e)
{
	this->m_mousePosition.x = e.button.x;
	this->m_mousePosition.y = e.button.y;

	if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
	{
		if (this->m_playText->IsSelected(this->m_mousePosition))
		{
			Game::GetInstance()->SetScene(new PlayScene());
;		}

		if (this->m_scoreText->IsSelected(this->m_mousePosition))
		{
			Game::GetInstance()->SetScene(new HighScoreScene());
		}

		if (this->m_exitText->IsSelected(this->m_mousePosition))
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
