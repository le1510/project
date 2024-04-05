#pragma once

#include "../Config.hpp"
#include "../types/Vector2f.hpp"

class BaseObject
{
protected:
	SDL_Texture*	m_texture;//truy cao thao tac luu tru thong tin hinh anh
	SDL_Rect*		m_rectSrc;//luu ytu hinh chu nhat nguon, xac dinh hinh anh goc ma ta sao cheep len man hinh
	SDL_Rect*		m_rectDst;//luu tr uhinh chu nhat dich, xac dinh vung tren man hinh ma ta muon ve hinh anh vao, xac dinh bi tri va kich thuoc doi tuong
	SDL_Rect*       m_rectCollision;//xu ly va cham bang hinh chu nhat
	SDL_Point*		m_origin;//luu tru diem goc cua doi tuong
	float			m_angle;//goc xoay doi tuong
	bool			m_flipH;//xem co can lat ngang khong
    bool            m_isAlive;

public:
	BaseObject();
	~BaseObject() = default;

	virtual void Update(float) = 0;//phuong thuc ao de update

	virtual void Render(SDL_Renderer*);//ve doi tuong len man hinh su dung renderer truyen vao

    void SetOrigin(SDL_Point origin);//thiet lap gia tri cho m_origin
    SDL_Point GetOrigin() const;

	float GetAngle() const;//goc xoay cua doi tuong
	void SetAngle(float angle);

	bool GetFlipH() const;//lat ngang anh
	void SetFlipH(bool flip);

	void Move(Vector2f vector);//di chuyen doi tuong dua tren vector
    SDL_Rect GetRectCollision() const;
    void SetIsAlive(bool);
    bool IsAlive() const;
    //kiem tra va cham
    //true :va cham, false khong va cham
    bool IsCollision(const BaseObject*) const;
    //thuat toan va cham aabb
};
