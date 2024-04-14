#include"Game.hpp"
#include"Resource.hpp"
#include"scenes/MenuScene.hpp"
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
        SDL_Event e;
        while(SDL_PollEvent(&e)!=0)
        {
            if(e.type==SDL_QUIT)
            {
                m_isRunning=false;

            }
            m_scene->HandleEvent(e);
        }


        float delta=(SDL_GetTicks()-last_frame_time)/1000.f;
        last_frame_time=SDL_GetTicks();
        m_scene->Update(delta);

        SDL_SetRenderDrawColor(m_renderer,0,0,0,255);
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer,Resource::TX_MAP_BACKGROUND,nullptr,nullptr);
        m_scene->Render(m_renderer);
        SDL_RenderPresent(m_renderer);
    }

}
// singleton pattern
Game* Game::GetInstance()
{
    if(g_game==nullptr)
    {
        g_game=new Game();
    }
    return g_game;
}

void Game::SetScene(BaseScene* scene)
{
    m_scene = scene;
}

void Game::Initialize()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);

    m_window=SDL_CreateWindow(WINDOW_TITLE,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);
    m_renderer=SDL_CreateRenderer(m_window,-1,SDL_RENDERER_PRESENTVSYNC);

    SDL_SetRenderDrawColor(m_renderer,0,0,0,255);
    m_isRunning=true;
    Resource::LoadAllData(m_renderer);
    SetScene(new MenuScene());
}

void Game::Quit()
{
    this->m_isRunning = false;
}

void Game::Terminate()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);

    SDL_Quit();

}
