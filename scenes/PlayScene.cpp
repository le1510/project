#include "PlayScene.hpp"
#include "../Resource.hpp"
#include "../Game.hpp"
#include "GameOverScene.hpp"
#include"HighScoreScene.hpp"

void PlayScene::SetSpawnTime(float spawnTime)
{
    m_spawnTime = spawnTime;
}

void PlayScene::SetEasySpawnTime()
{
    SetSpawnTime(3.f);
}

void PlayScene::SetMediumSpawnTime()
{
    SetSpawnTime(1.5f);
}

void PlayScene::SetHardSpawnTime()
{
    SetSpawnTime(0.5f);
}

PlayScene::PlayScene() :
    m_elapsedTime(0.f),
    m_score(0),
    m_spawnTime(2.f),
    m_level(0),
    m_isGamePaused(false),
    m_shotsFired(0),
    m_timeSinceLastShot(0.f),
    m_maxShots(10),
    m_reloadTime(10.f)

{
    this->m_tower = new Tower();
    this->m_player = new Player();
    this->m_scoreText = new Text(Resource::FONT_48);
    this->m_scoreText->SetPosition({ 1000, 5 });
    if(Resource::IsSound)
    {
        Mix_PlayMusic(Resource::SFX_BACKGROUND, -1);
    }

}
void PlayScene::SetMaxShots(int maxShots)
{
    m_maxShots = maxShots;
}
void PlayScene::SetReloadTime(float  reloadtime)
{
    m_reloadTime = reloadtime;
}
void PlayScene::HandleEvent(SDL_Event e)
{
    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
    {
        int mouseX = e.button.x;
        int mouseY = e.button.y;

        if (mouseX >= 0 && mouseX <= 63 && mouseY >= 10 && mouseY <= 74)
        {
            m_isGamePaused = !m_isGamePaused;

            if (m_isGamePaused)
            {
                Mix_PauseMusic();
                m_isContinueShown = true;
            }
            else
            {
                Mix_ResumeMusic();
                m_isContinueShown = false;
            }
        }
        else if (m_isContinueShown && mouseX >= 520 && mouseX <= 584 && mouseY >= 280 && mouseY <= 344)
        {
            m_isGamePaused = false;
            m_isContinueShown = false;
        }
        else if (m_isContinueShown && mouseX >= 650 && mouseX <= 714 && mouseY >= 280 && mouseY <= 344)
        {
            Game::GetInstance()->SetScene(new GameOverScene(this->m_score));
        }
        if (!m_isGamePaused && this->m_player->IsShotable() && m_shotsFired < m_maxShots)
        {

            if (Resource::IsSound)
            {
                Mix_PlayChannel(-1, Resource::SFX_SHOT, 0);
                m_shotsFired++;
            }
            this->m_bullets.push_back(this->m_player->Shot());
        }
    }
}




void PlayScene::Update(float delta)
{
    if(!m_isGamePaused)
    {
        this->m_elapsedTime += delta;

        if (this->m_elapsedTime > this->m_spawnTime)
        {
            this->m_threats.push_back(Threat::Generate());

            this->m_elapsedTime -= this->m_spawnTime;
        }
        if (m_shotsFired >= 5)
        {
            m_timeSinceLastShot += delta;
            if (m_timeSinceLastShot >= m_reloadTime)
            {
                m_shotsFired = 0;
                m_timeSinceLastShot = 0;
            }
        }
        m_player->Heal(10,delta);
        this->m_player->UpdateAmmo(this->m_maxShots - this->m_shotsFired);
        this->m_player->UpdateShotsFired(this->m_shotsFired);



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
        this->CheckPlayerAndThreatsCollision();

    }
}
void PlayScene::ReloadBullet()
{
    m_shotsFired = 0;
    m_timeSinceLastShot = 0;
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


    SDL_Rect imageRect = { 0, 10, 64, 64  };
    SDL_Point mousePos;
    SDL_GetMouseState(&mousePos.x, &mousePos.y);

    if (SDL_PointInRect(&mousePos, &imageRect))
    {
        SDL_Rect scaledImageRect = { imageRect.x + imageRect.w * 0.25, imageRect.y + imageRect.h * 0.25, imageRect.w * 1.2, imageRect.h * 1.2 };
        SDL_RenderCopy(renderer, Resource::TX_PAUSE, nullptr, &scaledImageRect);
    }
    else
    {
        SDL_RenderCopy(renderer, Resource::TX_PAUSE, nullptr, &imageRect);
    }

    if(m_isGamePaused)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_Rect rect = { 470, 250, 350, 20 };
        SDL_RenderFillRect(renderer, &rect);

        SDL_Color white = { 255, 255, 255 };
        SDL_Surface* surface = TTF_RenderText_Solid(Resource::FONT_24, "Do you want to continue or stop?", white);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect textRect = { 500, 250, surface->w, surface->h };
        SDL_RenderCopy(renderer, texture, nullptr, &textRect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);

        SDL_Rect continueRect = { 520, 280, 64, 64 };
        SDL_Rect endRect = { 650, 280, 64, 64 };

        if (SDL_PointInRect(&mousePos, &continueRect))
        {
            SDL_Rect scaledContinueRect = { continueRect.x - continueRect.w * 0.25, continueRect.y - continueRect.h * 0.25, continueRect.w * 1.5, continueRect.h * 1.5 };
            SDL_RenderCopy(renderer, Resource::TX_CONTINUE, nullptr, &scaledContinueRect);
        }
        else
        {
            SDL_RenderCopy(renderer, Resource::TX_CONTINUE, nullptr, &continueRect);
        }

        if (SDL_PointInRect(&mousePos, &endRect))
        {
            SDL_Rect scaledEndRect = { endRect.x - endRect.w * 0.25, endRect.y - endRect.h * 0.25, endRect.w * 1.5, endRect.h * 1.5 };
            SDL_RenderCopy(renderer, Resource::TX_END, nullptr, &scaledEndRect);
        }
        else
        {
            SDL_RenderCopy(renderer, Resource::TX_END, nullptr, &endRect);
        }
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
void PlayScene::CheckPlayerAndThreatsCollision()
{
    for (auto threat : this->m_threats)
    {
        if (this->m_player->IsCollision(threat))
        {
            int damage = threat->GetDamage();
            int currentHP = this->m_player->GetCurrentHP();
            currentHP -= damage;
            this->m_player->SetCurrentHP(currentHP);

            if (currentHP <= 0)
            {


                this->HandlePlayerAndThreatCollision(threat);
                break;
            }
        }
    }
}
void PlayScene::HandlePlayerAndThreatCollision(Threat* threat)
{
    this->GameOver();

}
void PlayScene::GameOver()
{
    Game::GetInstance()->SetScene(new GameOverScene(this->m_score));
}
void PlayScene::UpdateLevel()
{
    int t = this->m_score / 100;
    if (t != this->m_level && this->m_level < 10)
    {
        if (this->m_player->GetScale() < 5.0f)
        {
            this->m_level = t;
            this->m_spawnTime -= t * 0.1f;
            this->m_player->Scale(1.3f);

            this->m_player->DecreaseBulletDamage(5);
        }
    }
}



