#include "PlayScene.hpp"
#include "../Resource.hpp"
#include "../Game.hpp"
#include "GameOverScene.hpp"
#include"HighScoreScene.hpp"

PlayScene::PlayScene() :
    m_elapsedTime(0.f),
    m_score(0),
    m_spawnTime(1.2f),
    m_level(0)
{
    this->m_tower = new Tower();
    this->m_player = new Player();
    this->m_scoreText = new Text(Resource::FONT_24);
    this->m_scoreText->SetPosition({ 50, 5 });
    if(Resource::IsSound)
    {
        Mix_PlayMusic(Resource::SFX_BACKGROUND, -1);
    }

}

void PlayScene::HandleEvent(SDL_Event e)
{
    if (e.type == SDL_MOUSEBUTTONDOWN)
    {
        if (e.button.button == SDL_BUTTON_LEFT && this->m_player->IsShotable())
        {
            if(Resource::IsSound)
            {
                Mix_PlayChannel(-1, Resource::SFX_SHOT, 0);
            }
            this->m_bullets.push_back(this->m_player->Shot());

        }
    }
}

void PlayScene::Update(float delta)
{
    this->m_elapsedTime += delta;

    if (this->m_elapsedTime > this->m_spawnTime)
    {
        this->m_threats.push_back(Threat::Generate());

        this->m_elapsedTime -= this->m_spawnTime;
    }

    this->m_tower->Update(delta);
    this->m_player->Update(delta);
    this->CheckPlayerAndTower();


    for (auto threat : this->m_threats)
    {
        threat->Update(delta);

        if (threat->IsAttackable())
        {
            this->m_tower->SetCurrentHP(this->m_tower->GetCurrentHP() - threat->Attack());
        }
    }

    for (auto bullet : this->m_bullets)
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

    for (int i = 0; i < this->m_threats.size();)
    {
        if (!this->m_threats[i]->IsAlive())
        {
            this->m_threats.erase(this->m_threats.begin() + i);

            this->m_score += this->m_threats[i]->Score();
        }
        else
        {
            i++;
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
    }

    if (!this->m_tower->IsAlive())
    {
        Game::GetInstance()->SetScene(new GameOverScene(this->m_score));
    }
    this->UpdateLevel();
}

void PlayScene::Render(SDL_Renderer* renderer)
{
    if (this->m_tower->GetOrigin().y + 100 < this->m_player->GetOrigin().y)
    {
        this->m_tower->Render(renderer);
        this->m_player->Render(renderer);
    }
    else
    {
        this->m_player->Render(renderer);
        this->m_tower->Render(renderer);
    }

    for (auto threat : this->m_threats)
    {
        threat->Render(renderer);
    }
    for (auto bullet : this->m_bullets)
    {
        bullet->Render(renderer);
    }

    this->m_scoreText->RenderText(renderer, "Score: " + std::to_string(this->m_score));
}

void PlayScene::CheckPlayerAndTower()
{
    if (this->m_player->IsCollision(this->m_tower))
    {
        auto o = this->m_player->GetOrigin();

        if (o.x > 535 && o.x < WINDOW_WIDTH / 2)
        {
            this->m_player->SetOrigin({ 535, o.y });
        }

        if (o.x < 665 && o.x > WINDOW_WIDTH / 2)
        {
            this->m_player->SetOrigin({ 665, o.y });
        }
    }
}
void PlayScene::UpdateLevel()
{
    int t=this->m_score/100;
    if(t<this->m_level&&this->m_level<10)
    {
        this->m_level=t;
        this->m_spawnTime-=t*0.1f;
    }

}


