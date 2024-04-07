#pragma once

#include"../Config.hpp"
#include"BaseObject.hpp"
#include"../components/Damage.hpp"
class Bullet:public BaseObject,public Damage
{

private:
    int m_speed;//tốc độ đạn
public:
    Bullet(float,SDL_Point);// thiết lập tốc độ và điểm bắt đầu của đạn
    void Update(float) override; // cập nhạt trạng thái của đạn theo time
};
