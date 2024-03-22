#include "Gun.hpp"
#include "../Resource.hpp"
#include <cmath>

Gun::Gun()
{
	this->m_texture = Resource::TX_PLAYER_GUN;//hinh anh duoc dua len

	this->m_rectSrc->w = 16;//chieu rong o hinh chu nhat nguon
	this->m_rectSrc->h = 32;//kich dai sung hinh chu nhat nguon

	this->m_rectDst->w = 24;//hinh chu nhat dich chieu rong
	this->m_rectDst->h = 48;//                    chieu dai
}

void Gun::Update(float delta)
{
	int xMouse;//toa do x con tro chuot
	int yMouse;//toa do y con tro chuot
	SDL_GetMouseState(&xMouse, &yMouse);

	int deltaX = xMouse - m_origin->x;//su chenh lech cua toa do con tro chuot va toa do goc
	int deltaY = yMouse - m_origin->y;

	float angleRadians = (float) std::atan2(deltaY, deltaX);// goc giua con tro chuot va diem goc cua sung
	this->m_angle = (float) (angleRadians * 180.0f / M_PI + 90.f);//chuyen rad thanh do

	this->m_flipH = deltaX < 0 ? true : false;//xem hinh anh co duoc lat ngang khong

}
