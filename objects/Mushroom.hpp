#pragma once
#include"../Config.hpp"
#include"Threat.hpp"
class Mushroom : public Threat
{
    public:
    Mushroom();
    int Score()override;

};
