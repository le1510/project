#include "MenuScene.hpp"
#include "LevelScene.hpp"
#include "../Resource.hpp"
#include "../Game.hpp"
#include "PlayScene.hpp"
#include"ColorDinoScene.hpp"

ColorDinoScene::ColorDinoScene(PlayScene* playScene) :
    m_playScene(playScene),
    m_elapsedTime(0.f),
    m_mousePosition({0, 0}),
    MenuAnimation(3,0.1f)
{
    this->m_texture = Resource::TX_BACKGROUND_9;
    this->m_rectSrc->w = 400   ;
    this->m_rectSrc->h = 226  ;

    this->m_rectDst->w = 1200;
    this->m_rectDst->h = 680;
    this->yellowText = new Text(Resource::FONT_48);
    this->yellowText->SetPosition({ 640, 520 });
    this->greenText = new Text(Resource::FONT_48);
    this->greenText->SetPosition({ 70, 520 });
    this->blueText = new Text(Resource::FONT_48);
    this->blueText->SetPosition({ 930, 450 });
    this->redText = new Text(Resource::FONT_48);
    this->redText->SetPosition({ 380, 450 });

}

void ColorDinoScene::HandleEvent(SDL_Event e)
{
    if (e.type == SDL_MOUSEMOTION)
    {
        m_mousePosition.x = e.motion.x;
        m_mousePosition.y = e.motion.y;
    }

    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
    {
        if (this->yellowText->IsSelected(this->m_mousePosition))
        {
            Resource::TX_PLAYERYELLOW = Resource::TX_PLAYERYELLOW;
            Game::GetInstance()->SetScene(m_playScene);

        }
        else if (this->redText->IsSelected(this->m_mousePosition))
        {
//            Game::GetInstance()->SetScene(m_playScene);
            Resource::TX_PLAYERYELLOW = Resource::TX_PLAYERRED;
            Game::GetInstance()->SetScene(m_playScene);


        }
        else if (this->blueText->IsSelected(this->m_mousePosition))
        {

            Resource::TX_PLAYERYELLOW = Resource::TX_PLAYERBLUE;
            Game::GetInstance()->SetScene(m_playScene);


        }
        else if (this->greenText->IsSelected(this->m_mousePosition))
        {

            Resource::TX_PLAYERYELLOW = Resource::TX_PLAYERGREEN;

            Game::GetInstance()->SetScene(m_playScene);

        }
        else
        {
            LevelScene* levelScene = new LevelScene();
            Game::GetInstance()->SetScene(levelScene);
        }

    }
}


void ColorDinoScene::Update(float delta)
{
    this->m_elapsedTime+=delta;
    this->UpdateAnimation(delta);
    this->greenText->SetColor({ 0, 128, 0, 255 });
    this->yellowText->SetColor({ 255, 255, 0, 255 });
    this->blueText->SetColor({ 0, 0, 255, 255 });
    this->redText->SetColor({ 255, 0, 0, 255 });

    if (this->greenText->IsSelected(this->m_mousePosition))
    {
        this->greenText->SetColor({255, 192, 203, 255 });
    }
    if (this->yellowText->IsSelected(this->m_mousePosition))
    {
        this->yellowText->SetColor({ 255, 192, 203, 255});
    }
    if (this->blueText->IsSelected(this->m_mousePosition))
    {
        this->blueText->SetColor({ 255, 192, 203, 255 });
    }
    if (this->redText->IsSelected(this->m_mousePosition))
    {
        this->redText->SetColor({ 255, 192, 203, 255});
    }
}

void ColorDinoScene::Render(SDL_Renderer* renderer)
{
    BaseObject::Render(renderer);
        SDL_RenderCopy(renderer, Resource::TX_BACKGROUND_7, nullptr, nullptr);

    this->redText->RenderText(renderer, "DINO RED");
    this->blueText->RenderText(renderer, "DINO BLUE");
    this->greenText->RenderText(renderer, "DINO GREEN");
    this->yellowText->RenderText(renderer, "DINO YELLOW");




}

