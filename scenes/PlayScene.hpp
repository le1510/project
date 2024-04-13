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

public:
    PlayScene();

    void HandleEvent(SDL_Event) override ;
    void Update(float) override;
    void Render(SDL_Renderer*) override ;
    void CheckPlayerAndTower();
};
