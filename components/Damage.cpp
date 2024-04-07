#include "Damage.hpp"

Damage::Damage(int damage) :
    m_damage(damage)
{
}

int Damage::GetDamage()
{
    return this->m_damage;//doc muc do sat thuong
}

void Damage::SetDamage(int damage)
{
    if (damage > 0)
    {
        this->m_damage = damage;//thay doi muc do sat thuong
    }
}
