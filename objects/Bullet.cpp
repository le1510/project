#include "Bullet.hpp"
#include "../Resource.hpp"
#include <cmath>

Bullet::Bullet(float angle, SDL_Point origin) :
    Damage(30),
    m_speed(800),
    m_elapsedTime(0.f)
{
    this->m_texture = Resource::TX_PLAYER_BULLET;


    this->m_rectSrc->w = this->m_rectDst->w = 32;
    this->m_rectSrc->h = this->m_rectDst->h = 32;

    this->m_rectCollision->w = this->m_rectCollision->h = 20;
    this->m_rectCollision->x = this->m_rectCollision->y = 6;

    this->SetAngle(angle);
    this->SetOrigin(origin);
}

void Bullet::Update(float delta)
{
    this->m_elapsedTime+=delta;
    if(this->m_elapsedTime>=0.5f)
    {
        this->m_isAlive=false;
    }
    Vector2f vec;
    vec.x = (float)std::cos((this->m_angle - 90.f) * M_PI / 180);
    vec.y = (float)std::sin((this->m_angle - 90.f) * M_PI / 180);

    this->Move(vec * (this->m_speed * delta));

    auto o = this->m_origin;
    if (o->x < 0 || o->x > WINDOW_WIDTH || o->y < 0 || o->y > WINDOW_HEIGHT)
    {
        this->m_isAlive = false;
    }
}
void Bullet::DecreaseDamage(int amount)
{
    m_damage -= amount;
}
