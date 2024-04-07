#pragma once
#include"../Config.hpp"
class BaseScene //co so boi canh
{
public:

    BaseScene()=default;
    ~BaseScene()=default;
    virtual void HandlEvent(SDL_Event) = 0 ;//xu li su kien// lopes con phải ghi đè phương thức này để xử lý sự kiện cụ thể
    virtual void Update(float) = 0 ;//cap nhat
    virtual void Render(SDL_Renderer*) = 0 ;//ket xuat//trng thai hien thi

};



























