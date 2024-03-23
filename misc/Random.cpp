#include"Random.hpp"
#include<random>

int Random::RandomInt(int min,int max)
{
    return (std::rand() % (max - min + 1)) + min;
}

bool Random::RandomBool()
{
    return Random::RandomInt(1, 2) == 1;
}
