#pragma once
#include"../Config.hpp"
#include"Threat.hpp"
class Mushroom : public Threat
{
    public:
    Mushroom();//nấm
    int Score()override;

};
