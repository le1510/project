#pragma once
#include"Config.hpp"
class Game
{

private:

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    bool m_isRunning;
public:
    Game();
    ~Game();
    void Run();
    static Game* GetInstance();
private:
//ham khoi tao game
    void Initialize();
    //ham  huy game
    void Terminate();
};
