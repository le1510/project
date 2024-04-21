#include "MenuScene.hpp"
#include "HelpScene.hpp"
#include "../Resource.hpp"
#include "../Game.hpp"

HelpScene::HelpScene() :
    m_elapsedTime(0.f)
{
}

void HelpScene::HandleEvent(SDL_Event e)
{
    if (e.type == SDL_MOUSEBUTTONDOWN)
    {
        if (e.button.button == SDL_BUTTON_LEFT && this->m_elapsedTime > 0.5f)
        {
            Game::GetInstance()->SetScene(new MenuScene());
        }
    }
}

void HelpScene::Update(float delta)
{
    this->m_elapsedTime += delta;
}

void HelpScene::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,Resource::TX_BACKGROUND_4,nullptr,nullptr);

}


