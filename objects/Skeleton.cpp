#include "Skeleton.hpp"
#include "../Resource.hpp"

Skeleton::Skeleton() :
    Threat(
        Resource::TX_SKELETON_ATTACK,
        Resource::TX_SKELETON_DEATH,
        Resource::TX_SKELETON_WALK,
        20, 5, 200)
{
    this->m_rectCollision->w = 30;
    this->m_rectCollision->h = 40;
    this->m_rectCollision->x = this->m_rectDst->x + (this->m_rectDst->w - this->m_rectCollision->w) / 2;
    this->m_rectCollision->y = this->m_rectDst->y + (this->m_rectDst->h - this->m_rectCollision->h) / 2 + 10;
}
int Skeleton::Score()
{
    return 0 ;
}
