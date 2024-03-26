#pragma once

#include"../components/Damage.hpp"
#include"../Config.hpp"
#include"../components/HP.hpp"
#include"AnimatedObject.hpp"
//kieu enum trong c++
enum class ThreatState //threat:moi de doa, state trang thai
{

    ATTACK,//tan cong
    DEATH,//chet
    WALK//di chuyen

};
class Threat:public AnimatedObject,public HP, public Damage
{
protected:
    ThreatState m_state;
    int m_speed;//toc do

    SDL_Texture* m_attackTex;//hinh anh tan cong
    SDL_Texture* m_deathTex;//hinh anh chet
    SDL_Texture* m_walkTex;//hinh anh di chuyen

    SDL_Rect m_totalHP;//hp max
    SDL_Rect m_currentHP;//hp hientai

public:
    Threat(SDL_Texture*,SDL_Texture*,SDL_Texture*,int,int,int);
    void SetState(ThreatState state);//thiet lap trang thai
    ThreatState GetState() const;//trien khai trang thai
    void Update(float ) override;//cap nhat update trang thai
    void Render(SDL_Renderer*) override;//ve doi tuong len man hinh
    static Threat* Generate();//tao ra doi tuong threat moi
};
