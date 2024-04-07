#include "Skeleton.hpp"
#include "../Resource.hpp"

Skeleton::Skeleton() :
	Threat(
        Resource::TX_SKELETON_ATTACK,//hien thi anh quai vat
        Resource::TX_SKELETON_DEATH,
        Resource::TX_SKELETON_WALK,
        20, 5, 200) //máu max, độ sát thương , tốc độ
{
    this->m_rectCollision->w = 30;//hinh chu nhat va cham chieu rong chieu dai
this->m_rectCollision->h = 40;
this->m_rectCollision->x = this->m_rectDst->x + (this->m_rectDst->w - this->m_rectCollision->w) / 2;//vi tri dat hinh chu nhat
this->m_rectCollision->y = this->m_rectDst->y + (this->m_rectDst->h - this->m_rectCollision->h) / 2 + 10;
}
int Skeleton::Score()
{
    return 9;//moi lan giet chet duoc bộ xương thì cộng 9ddieemr
}
