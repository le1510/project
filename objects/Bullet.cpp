#include "Bullet.hpp"
#include "../Resource.hpp"
#include <cmath>

Bullet::Bullet(float angle, SDL_Point origin) :
	Damage(15),//đọo sát thuong 15
	m_speed(800)//tốc độ 800
{
	this->m_texture = Resource::TX_PLAYER_BULLET;// dẫn ảnh hiển thị đạn


	this->m_rectSrc->w = this->m_rectDst->w = 32;
	this->m_rectSrc->h = this->m_rectDst->h = 32;//thiết lập kích thước của vùng hiển thị hình ảnh bulllet

	this->m_rectCollision->w = this->m_rectCollision->h = 20;
this->m_rectCollision->x = this->m_rectCollision->y = 6;

	this->SetAngle(angle);//thiêts lập góc bắn
	this->SetOrigin(origin);//thiết lậpddieemr gốc
}

void Bullet::Update(float delta)
{
	Vector2f vec;
	vec.x = (float)std::cos((this->m_angle - 90.f) * M_PI / 180);//việc di chuyển của đạn tọa đọo x
	vec.y = (float)std::sin((this->m_angle - 90.f) * M_PI / 180);//viên di chuyển của đạn tọa độ y

	this->Move(vec * (this->m_speed * delta));//quánxg đường đạn di chuyển
}
