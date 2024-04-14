#pragma once // file hp

#include "../Config.hpp"
#include "../components/Damage.hpp"
#include "AnimatedObject.hpp"
#include "Gun.hpp"
#include"Bullet.hpp"

class Player final : public AnimatedObject,public Damage
{
private:
    int				m_speed;
    Gun*			m_gun;

    bool m_isShotable;
    float m_elapsedTime;

public:
    Player();
    ~Player() = default;

    void Update(float) override;
    void Render(SDL_Renderer*) override;


    bool IsShotable() const;
    Bullet* Shot();
};
