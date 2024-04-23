// Trong LevelScene.cpp
#include "MenuScene.hpp"
#include "LevelScene.hpp"
#include "../Resource.hpp"
#include "../Game.hpp"
#include "PlayScene.hpp"
LevelScene::LevelScene() :
    m_elapsedTime(0.f),
    m_mousePosition({0, 0})
{
    this->easyText = new Text(Resource::FONT_48);
    this->easyText->SetPosition({ 20, 150 });
    this->mediumText = new Text(Resource::FONT_48);
    this->mediumText->SetPosition({ 5, 235 });
    this->hardText = new Text(Resource::FONT_48);
    this->hardText->SetPosition({ 20, 320 });

}

void LevelScene::HandleEvent(SDL_Event e)
{
    if (e.type == SDL_MOUSEMOTION)
    {
        m_mousePosition.x = e.motion.x;
        m_mousePosition.y = e.motion.y;
    }

    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
    {
        if (this->easyText->IsSelected(this->m_mousePosition))
        {
            PlayScene* playScene = new PlayScene();
            playScene->SetEasySpawnTime();
            Game::GetInstance()->SetScene(playScene);
        }
        else if (this->mediumText->IsSelected(this->m_mousePosition))
        {
            PlayScene* playScene = new PlayScene();
            playScene->SetMediumSpawnTime();
            Game::GetInstance()->SetScene(playScene);
        }
        else if (this->hardText->IsSelected(this->m_mousePosition))
        {
            PlayScene* playScene = new PlayScene();
            playScene->SetHardSpawnTime();
            Game::GetInstance()->SetScene(playScene);
        }
        else
        {
            MenuScene* menuScene = new MenuScene();
            Game::GetInstance()->SetScene(menuScene);
        }
    }
}


void LevelScene::Update(float delta)
{
    this->easyText->SetColor({ 0, 0, 0, 255 });
    this->mediumText->SetColor({ 0, 0, 0, 255 });
    this->hardText->SetColor({ 0, 0, 0, 255 });
    if (this->easyText->IsSelected(this->m_mousePosition))
    {
        this->easyText->SetColor({ 255, 0, 0, 255 });
    }
    if (this->mediumText->IsSelected(this->m_mousePosition))
    {
        this->mediumText->SetColor({ 255, 0, 0, 255 });
    }
    if (this->hardText->IsSelected(this->m_mousePosition))
    {
        this->hardText->SetColor({ 255, 0, 0, 255 });
    }
}

void LevelScene::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, Resource::TX_BACKGROUND_6, nullptr, nullptr);

    this->easyText->RenderText(renderer, "EASY:");
    this->mediumText->RenderText(renderer, "MEDIUM:");
    this->hardText->RenderText(renderer, "HARD:");



}

