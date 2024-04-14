#include"Config.hpp"
#include"Game.hpp"

int main(int argc, char* arvg[])
{
    // random 1 cai seed
    //std::srand(std::time(nullptr));
    Game::GetInstance()->Run();

    return EXIT_SUCCESS;//RETURN 0
}
