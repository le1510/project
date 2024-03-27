#include"Mushroom.hpp"
#include"../Resource.hpp"
Mushroom::Mushroom():
    Threat(
           Resource::TX_MUSHROOM_ATTACK,
           Resource::TX_MUSHROOM_DEATH,
           Resource::TX_MUSHROOM_WALK,
           70,1,120) //mãx máu , độ sát thương, tốc đọ
    {

    }
