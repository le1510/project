#pragma once

#include"../Config.hpp"
#include"BaseObject.hpp"
#include"../components/Damage.hpp"
class Bullet:public BaseObject,public Damage
{

private:
    int m_speed;
public:
    Bullet(float,SDL_Point);
    void Update(float) override;
};
