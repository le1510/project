#include "HP.hpp"

HP::HP(int maxHP):
    m_maxHP(maxHP),
    m_currentHP(maxHP)
{

}

int HP::GetMaxHP()
{
    return this->m_maxHP;
}

int HP::GetCurrentHP()
{
    return this->m_currentHP;
}

void HP::SetMaxHP(int maxHP)
{
    if (maxHP)
    {
        this->m_maxHP = maxHP;
    }
}

void HP::SetCurrentHP(int currentHP)
{
    this->m_currentHP = currentHP;
}
