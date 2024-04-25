#include "Gun.hpp"
#include "../Resource.hpp"
#include <cmath>

Gun::Gun()
{
    this->m_texture = Resource::TX_PLAYER_GUN;

    this->m_rectSrc->w = 16;
    this->m_rectSrc->h = 32;

    this->m_rectDst->w = 24;
    this->m_rectDst->h = 48;
}

void Gun::Update(float delta)
{
    int xMouse;
    int yMouse;
    SDL_GetMouseState(&xMouse, &yMouse);

    int deltaX = xMouse - m_origin->x;
    int deltaY = yMouse - m_origin->y;

    float angleRadians = (float) std::atan2(deltaY, deltaX);
    this->m_angle = (float) (angleRadians * 180.0f / M_PI + 90.f);
    this->m_flipH = deltaX < 0 ? true : false;
}
void Gun::Scale(float scaleFactor)
{
    this->m_rectDst->w *= scaleFactor;
    this->m_rectDst->h *= scaleFactor;
}
