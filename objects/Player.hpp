#pragma once // file hp

#include "../Config.hpp"
#include "../components/Damage.hpp"
#include "AnimatedObject.hpp"
#include "Gun.hpp"
#include"Bullet.hpp"
#include "../components/HP.hpp"


class Player final : public AnimatedObject,public Damage,public HP
{
private:
    int				m_speed;
    Gun*			m_gun;

    bool m_isShotable;
    float m_elapsedTime;
    float m_scale;
    SDL_Rect m_totalHP;
    SDL_Rect m_currentHP;

public:
    Player();
    ~Player() = default;

    void Update(float) override;
    void Render(SDL_Renderer*) override;


    bool IsShotable() const;
    Bullet* Shot();
    void Scale(float scaleFactor);
    float GetScale() const;

};
