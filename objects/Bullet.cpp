#include "Bullet.hpp"
#include "../Resource.hpp"
#include <cmath>

Bullet::Bullet(float angle, SDL_Point origin) :
	Damage(15),
	m_speed(800)
{
	this->m_texture = Resource::TX_PLAYER_BULLET;

	this->m_rectSrc->w = this->m_rectDst->w = 32;
	this->m_rectSrc->h = this->m_rectDst->h = 32;

	this->SetAngle(angle);
	this->SetOrigin(origin);
}

void Bullet::Update(float delta)
{
	Vector2f vec;
	vec.x = (float)std::cos((this->m_angle - 90.f) * M_PI / 180);
	vec.y = (float)std::sin((this->m_angle - 90.f) * M_PI / 180);

	this->Move(vec * (this->m_speed * delta));
}
