#include "MenuScene.hpp"
#include "PlayScene.hpp"
#include "HighScoreScene.hpp"
#include "../Resource.hpp"
#include "../Game.hpp"
#include "HelpScene.hpp"


MenuScene::MenuScene() :
    m_mousePosition({0, 0})
{
    this->m_title = new Text(Resource::FONT_96);
    this->m_title->SetPosition({456, 130});
    this->m_title->SetColor({ 255, 0, 0, 255 });

    this->m_playText = new Text(Resource::FONT_48);
    this->m_playText->SetPosition({ 519, 250 });
    this->m_scoreText = new Text(Resource::FONT_48);
    this->m_scoreText->SetPosition({ 510, 325 });
    this->m_helpText = new Text(Resource::FONT_48);
    this->m_helpText->SetPosition({ 564, 400 });

    this->m_exitText = new Text(Resource::FONT_48);
    this->m_exitText->SetPosition({ 564, 475 });

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
        }

        if (this->m_scoreText->IsSelected(this->m_mousePosition))
        {
            Game::GetInstance()->SetScene(new HighScoreScene());
        }
        if (this->m_helpText->IsSelected(this->m_mousePosition))
        {
            Game::GetInstance()->SetScene(new HelpScene());
        }

        if (this->m_exitText->IsSelected(this->m_mousePosition))
        {
            Game::GetInstance()->Quit();
        }
    }
}

void MenuScene::Update(float delta)
{
    this->m_playText->SetColor({ 0, 0, 0, 255 });
    this->m_scoreText->SetColor({ 0, 0, 0, 255 });
    this->m_helpText->SetColor({ 0, 0, 0, 255 });

    this->m_exitText->SetColor({ 0, 0, 0, 255 });

    if (this->m_playText->IsSelected(this->m_mousePosition))
    {
        this->m_playText->SetColor({ 255, 0, 0, 255 });
    }

    if (this->m_scoreText->IsSelected(this->m_mousePosition))
    {
        this->m_scoreText->SetColor({ 255, 0, 0, 255 });
    }
    if (this->m_helpText->IsSelected(this->m_mousePosition))
    {
        this->m_helpText->SetColor({ 255, 0, 0, 255 });
    }

    if (this->m_exitText->IsSelected(this->m_mousePosition))
    {
        this->m_exitText->SetColor({ 255, 0, 0, 255 });
    }

}

void MenuScene::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, Resource::TX_BACKGROUND_3, nullptr, nullptr);

    this->m_title->RenderText(renderer, WINDOW_TITLE);
    this->m_playText->RenderText(renderer, "Play game");
    this->m_scoreText->RenderText(renderer, "High score");
    this->m_helpText->RenderText(renderer, "Help");

    this->m_exitText->RenderText(renderer, "Exit");
}
