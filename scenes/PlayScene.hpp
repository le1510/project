#pragma once
#include"BaseScene.hpp"
#include"../objects/Player.hpp"
#include"../objects/Tower.hpp"
#include"../objects/Threat.hpp"

class PlayScene: public BaseScene

{
private:
    Player*  m_player;
    Tower* m_tower;
    Threat* m_threat;
public:
    PlayScene();

     void HandlEvent(SDL_Event) override ;//ghi de hinh anh
void Update(float) override;
     void Render(SDL_Renderer*) override ;
};
