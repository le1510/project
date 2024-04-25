#pragma once
#include"BaseScene.hpp"
#include "../components/Text.hpp"
#include"../objects/Player.hpp"
#include"../objects/Tower.hpp"
#include"../objects/Threat.hpp"
#include"../objects/Bullet.hpp"

class PlayScene: public BaseScene
{

    int m_maxShots;
    int m_shotsFired;
    float m_timeSinceLastShot;
    float m_reloadTime;

private:
    Player*  m_player;
    Tower* m_tower;
    float m_elapsedTime;
    std::vector<Threat*> m_threats;
    std::vector<Bullet*> m_bullets;
    int  m_score;
    Text* m_scoreText;
    float m_spawnTime;
    int m_level;
    bool m_isGamePaused;
    bool m_isContinueShown;
    int mouseX;
    int mouseY;




public:
    PlayScene();
    Player* GetPlayer() const
    {
        return m_player;
    }

    void HandleEvent(SDL_Event) override ;
    void Update(float) override;
    void Render(SDL_Renderer*) override ;
    void CheckPlayerAndTower();
    void UpdateLevel();
    void SetSpawnTime(float );
    void SetEasySpawnTime();
    void SetMediumSpawnTime();
    void SetHardSpawnTime();
    void CheckPlayerAndThreatsCollision();
    void HandlePlayerAndThreatCollision(Threat*);
    void GameOver();
    void ReloadBullet();
    void SetMaxShots(int maxShots);
    void SetReloadTime(float reloadTime);
    int GetShotsFired() const
    {
        return m_shotsFired;
    }
    void Heal(int amount, float delta );
    void UpdateBulletScale(float scaleFactor);

};
