#pragma once

class Damage
{
protected:
	int		m_damage;// muc do sat thuong

public:
	Damage() = default;
	Damage(int);

	~Damage() = default;

	int GetDamage();// lay muc do sat thuong, khong nhan tham so, tra ve gia tri hien tai cua m damage, cho phep truy cap, va doc muc do sat thuong damage

	void SetDamage(int); //thiet lap muc do sat thuong
	//thiet lap gia tri cho m_damage // nhan tham so kieu in tva gan cho m_damage, phuong thuc nay cho phep thay doi muc do sat thuong cua doi tuong damage
};
