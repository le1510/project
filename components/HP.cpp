#include "HP.hpp"

HP::HP(int maxHP):



	m_maxHP(maxHP),//thiet lap m_maxhp=maxhp duoc truyen vao
	m_currentHP(maxHP)//thiet lap m_currenthp=maxhp
{

}

int HP::GetMaxHP()
{
	return this->m_maxHP;//doc gia tri maxhp cua hp
}

int HP::GetCurrentHP()
{
	return this->m_currentHP;//doc mau hien tai
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
	this->m_currentHP = currentHP;//tjiet lap gia tr imoi cho hp hien tai
}
