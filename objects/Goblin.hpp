#pragma once
#include"../Config.hpp"
#include"Threat.hpp"
class Goblin : public Threat
{
    public:
    Goblin();
    int Score()override;
};
