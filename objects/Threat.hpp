#pragma once

#include"../components/Damage.hpp"
#include"../Config.hpp"
#include"../components/HP.hpp"
#include"AnimatedObject.hpp"
//kieu enum trong c++, kiẻu liệt kê đại diện cho trạng thái của dối tượng
enum class ThreatState //threat:moi de doa, state trang thai
{

    ATTACK,//tan cong
    DEATH,//chet
    WALK//di chuyen

};
class Threat:public AnimatedObject,public HP, public Damage
{
protected:
    ThreatState m_state;// trạng thái hiện tại của đối tượng
    int m_speed;//toc do

    SDL_Texture* m_attackTex;//hinh anh tan cong
    SDL_Texture* m_deathTex;//hinh anh chet
    SDL_Texture* m_walkTex;//hinh anh di chuyen

    SDL_Rect m_totalHP;//hp max
    SDL_Rect m_currentHP;//hp hientai

    float m_elapsedTime;
    bool m_isAttackable;


public:
    Threat(SDL_Texture*,SDL_Texture*,SDL_Texture*,int,int,int);//hàm khởi tạo của lớp threat được sử dụng để thiết lập texture va các thôn gsoos khác của đối tượng
    void SetState(ThreatState state);//thiet lap trang thai
    ThreatState GetState() const;//trien khai trang thai
    void Update(float ) override;//cap nhat update trang thai
    void Render(SDL_Renderer*) override;//ve doi tuong len man hinh
    static Threat* Generate();//tao ra doi tuong threat mới
    virtual int Score() =0;//phương thức thuần áo r để tính điểm khi giết 1 đối tượng de dọa các lớp con của threat phải ghi đè phương thức này để cung cấp điểm số cụ thể cho đối tượng

    bool IsAttackable() const;//kiểm tr xem dối tượng có thể bị tấn công khay không
    int Attack();//thực hiện hành đôngj tấn công

};
