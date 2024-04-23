#pragma once
#include"BaseScene.hpp"
#include "../components/Text.hpp"
#include"../objects/Player.hpp"
#include"../objects/Tower.hpp"
#include"../objects/Threat.hpp"
#include"../objects/Bullet.hpp"

class PlayScene: public BaseScene

{
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



public:
    PlayScene();

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


};
