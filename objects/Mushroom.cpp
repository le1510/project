#include"Mushroom.hpp"
#include"../Resource.hpp"
Mushroom::Mushroom():
    Threat(
           Resource::TX_MUSHROOM_ATTACK,
           Resource::TX_MUSHROOM_DEATH,
           Resource::TX_MUSHROOM_WALK,
           70,1,120) //mãx máu , độ sát thương, tốc đọ
    {
this->m_rectCollision->w = 30;
this->m_rectCollision->h = 40;
this->m_rectCollision->x = this->m_rectDst->x + (this->m_rectDst->w - this->m_rectCollision->w) / 2;//hinh chữ nhật đi theo con nấm dựa trên tọa độ x và y của nấm nên khi nấm di chuyển nhình chữ nhật cũng di chuyển
this->m_rectCollision->y = this->m_rectDst->y + (this->m_rectDst->h - this->m_rectCollision->h) / 2 + 10;
    }
int Mushroom::Score()
{
    return 8;
}
