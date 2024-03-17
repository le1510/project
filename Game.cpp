#include"Game.hpp"
#include"Rescoure.hpp"
static Game* g_game=nullptr;
Game::Game()
{
    Initialize();

}
Game::~Game()
{
    Terminate();
}
void Game::Run()
{
    float last_frame_time=0.f;
    while(m_isRunning)
    {
        //xu ly su kien
        SDL_Event e;
        while(SDL_PollEvent(&e)!=0)
        {
            if(e.type==SDL_QUIT)
            {
                m_isRunning=false;
            }
        }
        //fps-frame per second
        //60fps -> 1 giay 60 frames
        //update

        float delta=(SDL_GetTicks()-last_frame_time)/1000.f;
        last_frame_time=SDL_GetTicks();
        //render
        SDL_RenderClear(m_renderer);
        SDL_RenderPresent(m_renderer);

    }

}
Game* Game::GetInstance()
{
    if(g_game==nullptr)
    {





        g_game=new Game();
    }
    return g_game;
}
void Game::Initialize()
{//KHOI TAO SDL2
    SDL_Init(SDL_INIT_EVERYTHING);
    //TAO WINDOW
    m_window=SDL_CreateWindow(WINDOW_TITLE,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);
    //tao renderer
    m_renderer=SDL_CreateRenderer(m_window,-1,SDL_RENDERER_PRESENTVSYNC);

    //chon mau render
    SDL_SetRenderDrawColor(m_renderer,0,0,0,255);
    m_isRunning=true;
    Resource::LoadAllData(m_renderer);

}

void Game::Terminate()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);

    SDL_Quit();

}
