#pragma once
#include"../Config.hpp"
#include"Threat.hpp"
class Skeleton  : public Threat
{
public:
    Skeleton();
    int Score()override;

};
