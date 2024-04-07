#pragma once
#include"../Config.hpp"
#include"Threat.hpp"
class Goblin : public Threat // kế thừa lớp threat để có thuộc tính và phương thức cơ bản của 1 đói tượng mối đe dọa trong trò chơi
{
    public:
    Goblin();//yeutinh
    int Score()override;//ghi đè từ lớp cơ sở threat điểm giết đc 1 con yêu tinh
};
