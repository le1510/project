#pragma once

#include"../components/Damage.hpp"
#include"../Config.hpp"
#include"../components/HP.hpp"
#include"AnimatedObject.hpp"
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

    SDL_Rect m_totalHP;
    SDL_Rect m_currentHP;

    float m_elapsedTime;
    bool m_isAttackable;
    int m_attackMaxFrame;


public:
    Threat(SDL_Texture*,SDL_Texture*,SDL_Texture*,int,int,int);
    void SetState(ThreatState state);
    ThreatState GetState() const;
    void Update(float ) override;
    void Render(SDL_Renderer*) override;
    static Threat* Generate();
    virtual int Score() =0;
    bool IsAttackable() const;
    int Attack();
     void SetAttackMaxFrame(int maxFrame) { m_attackMaxFrame = maxFrame; }
    int GetAttackMaxFrame() const { return m_attackMaxFrame; }

};
