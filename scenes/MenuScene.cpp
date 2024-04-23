#include "MenuScene.hpp"
#include "PlayScene.hpp"
#include "HighScoreScene.hpp"
#include "../Resource.hpp"
#include "../Game.hpp"
#include "HelpScene.hpp"
#include "LevelScene.hpp"



MenuScene::MenuScene() :
   MenuAnimation(3,0.6f)

{
    this->m_texture = Resource::TX_BACKGROUND_3;
    this->m_rectSrc->w = 400   ;
    this->m_rectSrc->h = 216  ;

    this->m_rectDst->w = 1200;
    this->m_rectDst->h = 681;



    this->m_title = new Text(Resource::FONT_96);
    this->m_title->SetPosition({456, 130});
    this->m_title->SetColor({ 255, 0, 0, 255 });

    this->m_playText = new Text(Resource::FONT_96);
    this->m_playText->SetPosition({ 19, 200 });
    this->m_scoreText = new Text(Resource::FONT_96);
    this->m_scoreText->SetPosition({ 10, 270 });
    this->m_helpText = new Text(Resource::FONT_96);
    this->m_helpText->SetPosition({ 64, 340 });
    this->m_levelText = new Text(Resource::FONT_96);
    this->m_levelText->SetPosition({ 55, 410 });

    this->m_exitText = new Text(Resource::FONT_96);
    this->m_exitText->SetPosition({ 64, 480 });

    if(Resource::IsSound)
    {
        Mix_PlayMusic(Resource::SFX_BACKGROUND, -1);
    }

    this->m_soundRect=new SDL_Rect({15,570,64 ,64 });
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

        if (this->m_levelText->IsSelected(this->m_mousePosition))
        {
            Game::GetInstance()->SetScene(new LevelScene());
        }
        if (this->m_exitText->IsSelected(this->m_mousePosition))
        {
            Game::GetInstance()->Quit();
        }

        if (    this->m_mousePosition.x >= this->m_soundRect->x &&
                this->m_mousePosition.x <= this->m_soundRect->x + this->m_soundRect->w &&
                this->m_mousePosition.y >= this->m_soundRect->y &&
                this->m_mousePosition.y <= this->m_soundRect->y + this->m_soundRect->h)
        {
            Resource::IsSound = !Resource::IsSound;

            if (Resource::IsSound)
            {
                Mix_PlayMusic(Resource::SFX_BACKGROUND, -1);
            }
            else
            {
                Mix_HaltMusic();
            }
        }
    }
}

void MenuScene::Update(float delta)
{
     this->m_elapsedTime+=delta;
     this->UpdateAnimation(delta);


    this->m_playText->SetColor({ 0, 0, 0, 255 });
    this->m_scoreText->SetColor({ 0, 0, 0, 255 });
    this->m_helpText->SetColor({ 0, 0, 0, 255 });
    this->m_levelText->SetColor({ 0, 0, 0, 255 });
    this->m_exitText->SetColor({ 0, 0, 0, 255 });

    // Kiểm tra và cài đặt màu sắc cho các văn bản được chọn
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

    if (this->m_levelText->IsSelected(this->m_mousePosition))
    {
        this->m_levelText->SetColor({ 255, 0, 0, 255 });
    }

    if (this->m_exitText->IsSelected(this->m_mousePosition))
    {
        this->m_exitText->SetColor({ 255, 0, 0, 255 });
    }
}

void MenuScene::Render(SDL_Renderer* renderer)
{
    BaseObject::Render(renderer);
    SDL_RenderCopy(renderer, Resource::TX_BACKGROUND_7, nullptr, nullptr);
    this->m_playText->RenderText(renderer, "Play game");
    this->m_scoreText->RenderText(renderer, "High score");
    this->m_helpText->RenderText(renderer, "Help");
    this->m_levelText->RenderText(renderer, "Level");
    this->m_exitText->RenderText(renderer, "Exit");
    SDL_RenderCopy(renderer, Resource::IsSound ? Resource::TX_ON : Resource::TX_OFF, nullptr, this->m_soundRect);
}

