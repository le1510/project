#pragma once
#include"BaseScene.hpp"
#include"../objects/Player.hpp"
#include"../objects/Tower.hpp"
class PlayScene: public BaseScene

{
private:
    Player*  m_player;
    Tower* m_tower;
public:
    PlayScene();

     void HandlEvent(SDL_Event) override ;
void Update(float) override;
     void Render(SDL_Renderer*) override ;
};
