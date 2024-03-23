#pragma once

#include"../components/Damage.hpp"
#include"../Config.hpp"
#include"../components/HP.hpp"
#include"AnimatedObject.hpp"
//kieu enum trong c++
enum class ThreatState
{

    ATTACK,
    DEATH,
    WALK

};
class Threat:public AnimatedObject,public HP, public Damage
{
protected:
    ThreatState m_state;
    int m_speed;

    SDL_Texture* m_attackTex;
    SDL_Texture* m_deathTex;
    SDL_Texture* m_walkTex;
public:
    Threat(SDL_Texture*,SDL_Texture*,SDL_Texture*,int,int,int);
    void SetState(ThreatState state);
    ThreatState GetState() const;
    void Update(float ) override;
    static Threat* Generate();
};
