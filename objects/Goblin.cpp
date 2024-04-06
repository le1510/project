#include"Goblin.hpp"
#include"../Resource.hpp"
Goblin::Goblin():
    Threat(
           Resource::TX_GOBLIN_ATTACK,
           Resource::TX_GOBLIN_DEATH,
           Resource::TX_GOBLIN_WALK,
           50,2,100)//max máu, độ sát thương, tốc độ
    {
	this->m_rectCollision->w = this->m_rectCollision->h = 40;
	this->m_rectCollision->x = this->m_rectDst->x + (this->m_rectDst->w - this->m_rectCollision->w) / 2;
	this->m_rectCollision->y = this->m_rectDst->y + (this->m_rectDst->h - this->m_rectCollision->h) / 2 + 10;
    }
    int Goblin::Score()
    {
        return 10;
    }
