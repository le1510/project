#pragma once

class HP
{
protected:
	int			m_maxHP;// mau toi da
	int			m_currentHP;// mau hien tai

public:
	HP() = default;
	HP(int);//khoi tao hp voi mau hp chi dinh

	~HP() = default;

	int GetMaxHP(); //tra ve gia tri m_max Hp
	int GetCurrentHP();//tra ve gia tri mau hien tai, su dung de lay mau hien tai

	void SetMaxHP(int);//thiet lap max hp
	void SetCurrentHP(int);//thiet lap hp hien tai
};
