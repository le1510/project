#include"Config.hpp"
#include"Game.hpp"

int main(int argc, char* arvg[])
{
    std::srand(std::time(nullptr));
    Game::GetInstance()->Run();

    return EXIT_SUCCESS;
}
