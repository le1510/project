#include"Goblin.hpp"
#include"../Resource.hpp"
Goblin::Goblin():
    Threat(
           Resource::TX_GOBLIN_ATTACK,
           Resource::TX_GOBLIN_DEATH,
           Resource::TX_GOBLIN_WALK,
           50,2,100)//max máu, độ sát thương, tốc độ
    {

    }
