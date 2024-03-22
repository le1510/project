#pragma once
#include"Config.hpp"
#include"scenes/BaseScene.hpp"
//class game
class Game
{

private:

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    BaseScene *m_scene;
    bool m_isRunning;
public:
    Game();
    ~Game();
    void Run();
    //sinmgleton pattern
    static Game* GetInstance();
    void SetScene(BaseScene*);
private:
//ham khoi tao game
    void Initialize();
    //ham  huy game
    void Terminate();
};
