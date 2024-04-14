#pragma once

class Damage
{
protected:
    int		m_damage;

public:
    Damage() = default;
    Damage(int);

    ~Damage() = default;

    int GetDamage();
    void SetDamage(int);
};
