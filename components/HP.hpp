#pragma once

class HP
{
protected:
	int			m_maxHP;
	int			m_currentHP;

public:
	HP() = default;
	HP(int);

	~HP() = default;

	int GetMaxHP();
	int GetCurrentHP();

	void SetMaxHP(int);
	void SetCurrentHP(int);
};
