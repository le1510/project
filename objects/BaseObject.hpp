#pragma once
// lớp cơ sở cho các đối tượng objects trong trò chơi
#include "../Config.hpp"
#include "../types/Vector2f.hpp"

class BaseObject
{
protected:
	SDL_Texture*	m_texture;//truy cao thao tac luu tru thong tin hinh anh
	SDL_Rect*		m_rectSrc;//luu tru hinh chu nhat nguon, xac dinh hinh anh goc ma ta sao cheep len man hinh
	SDL_Rect*		m_rectDst;//luu tr uhinh chu nhat dich, xac dinh vung tren man hinh ma ta muon ve hinh anh vao, xac dinh bi tri va kich thuoc doi tuong
	SDL_Rect*       m_rectCollision;//xu ly va cham bang hinh chu nhat
	SDL_Point*		m_origin;//luu tru diem goc cua doi tuong
	float			m_angle;//goc xoay doi tuong
	bool			m_flipH;//xem co can lat ngang khong
    bool            m_isAlive;//xem xem đối tượng còn sống hay không

public:
	BaseObject();
	~BaseObject() = default;

	virtual void Update(float) = 0;//phuong thuc ao de update // cậpt nhậ trạng thái của đối tượng // lớp con phải ghi đè phương thức này để cung cấp cật nhật riêng cho tưngf đói tượng cụ thể

	virtual void Render(SDL_Renderer*);//ve doi tuong len man hinh su dung renderer truyen vao

    void SetOrigin(SDL_Point origin);//thiet lap gia tri cho m_origin diểm gốc của đóio tượng
    SDL_Point GetOrigin() const;// lấy giá trị điểm gốc của đối tượng

	float GetAngle() const;//lấy goc xoay cua doi tuong
	void SetAngle(float angle);// thiết lập góc xoay của đối tượng

	bool GetFlipH() const;//lat ngang anh
	void SetFlipH(bool flip);

	void Move(Vector2f vector);//di chuyen doi tuong dua tren vector
    SDL_Rect GetRectCollision() const;//lấy hình chữ nhật va chạm của đối tượng
    void SetIsAlive(bool);// thiết lập giá trị sống chết của đối tượng
    bool IsAlive() const;// kiểm tra xem đối tượng còn sống hay không
    //kiem tra va cham
    //true :va cham, false khong va cham
    bool IsCollision(const BaseObject*) const;
    //thuat toan va cham aabb
};
