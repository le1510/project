#include "PlayScene.hpp"
#include "../Resource.hpp"
#include "../Game.hpp"
#include "GameOverScene.hpp"
PlayScene::PlayScene():
    m_elapsedTime(0.f),
    m_score(0)

{

    m_tower=new Tower();
    m_player=new Player();
    this->m_scoreText=new Text(Resource::FONT_24);
    this->m_scoreText->SetPosition({50,5});

    //chay nhac nen
    Mix_PlayMusic(Resource::SFX_BACKGROUND,-1);

}
void PlayScene::HandleEvent(SDL_Event e)
{
    if(e.type==SDL_MOUSEBUTTONDOWN)
    {
        if(e.button.button==SDL_BUTTON_LEFT && m_player->IsShotable())
        {
            Mix_PlayChannel(-1,Resource::SFX_SHOT,0);
            m_bullets.push_back(m_player->Shot());
        }
    }

}
void PlayScene::Update(float delta)
{
    m_elapsedTime+=delta;
    if(m_elapsedTime>2.f)
    {
        m_threats.push_back(Threat::Generate());
        m_elapsedTime=0.f;
    }
    m_tower->Update(delta);
    m_player->Update(delta);

    for(auto threat:m_threats)
    {
        if(threat->IsAttackable())
        {
            this->m_tower->SetCurrentHP(this->m_tower->GetCurrentHP()-threat->Attack());
        }
    }

    for (auto bullet: m_bullets)
    {
        bullet->Update(delta);
    }

    for (auto bullet : this->m_bullets)
    {
        for (auto threat : this->m_threats)
        {
            if (bullet->IsAlive() && bullet->IsCollision(threat))
            {
                threat->SetCurrentHP(threat->GetCurrentHP() - bullet->GetDamage());
                bullet->SetIsAlive(false);
            }
        }
    }

    for (int i = 0; i < this->m_bullets.size();)
    {
        if (!this->m_bullets[i]->IsAlive())
        {
            this->m_bullets.erase(this->m_bullets.begin() + i);
        }
        else
        {
            i++;
        }

        for (int i = 0; i < this->m_threats.size();)
        {
            if (!this->m_threats[i]->IsAlive())
            {
                this->m_threats.erase(this->m_threats.begin() + i);
                this->m_score+=this->m_threats[i]->Score();
            }
            else
            {
                i++;
            }
        }

    }

    if (!this->m_tower->IsAlive())
    {
        Game::GetInstance()->SetScene(new GameOverScene(this->m_score));
    }
}

void PlayScene::Render(SDL_Renderer* renderer)
{
    for(auto threat:m_threats)
    {
        threat->Render(renderer);
    }
    for(auto bullet:m_bullets)
    {
        bullet->Render(renderer);
    }
    if (m_tower->GetOrigin().y + 100 < m_player->GetOrigin().y)
    {
        m_tower->Render(renderer);
        m_player->Render(renderer);
    }
    else
    {
        m_player->Render(renderer);
        m_tower->Render(renderer);
    }
    this->m_scoreText->RenderText(renderer,"Score: "+std::to_string(this->m_score));
}
