#include "Tower.hpp"
#include "../Resource.hpp"

Tower::Tower() :
	AnimatedObject(11, 0.15f),
	HP(100)
{
	this->m_texture = Resource::TX_MAP_TOWER;

	this->m_rectSrc->w = 100;
	this->m_rectSrc->h = 140;

	this->m_rectDst->w = 150;
	this->m_rectDst->h = 210;
	this->m_rectDst->x = (WINDOW_WIDTH - this->m_rectDst->w) / 2;
	this->m_rectDst->y = (WINDOW_HEIGHT - this->m_rectDst->h) / 2;
}

void Tower::Update(float delta)
{
	this->UpdateAnimation(delta);
}
