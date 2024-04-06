#include"Game.hpp"
#include"Resource.hpp"
 #include"scenes/PlayScene.hpp"
static Game* g_game=nullptr;
Game::Game()
{
    //chay game
    Initialize();

}
Game::~Game()
{
    //huy game
    Terminate();
}
void Game::Run()
{
    float last_frame_time=0.f;//thoi gian troi qua cua cac khung hinh
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
            m_scene->HandlEvent(e);
        }
        //fps-frame per second
        //60fps -> 1 giay 60 frames
        //update game

        float delta=(SDL_GetTicks()-last_frame_time)/1000.f;
        last_frame_time=SDL_GetTicks();
        m_scene->Update(delta);
        //render
        SDL_SetRenderDrawColor(m_renderer,0,0,0,255);//mau den

        SDL_RenderClear(m_renderer);//xoa noi dung render, chuan bi doi tuong moi
        SDL_RenderCopy(m_renderer,Resource::TX_MAP_BACKGROUND,nullptr,nullptr);// sao chep map_background len renderer
        m_scene->Render(m_renderer);//ve doi tuong scene len rederer
        SDL_RenderPresent(m_renderer);//hien thi noi dung renderer len man hinh

    }

}
Game* Game::GetInstance()
{
    if(g_game==nullptr)//kiem tra xem co doi tuong game nao duoc tao chua
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
{//KHOI TAO SDL2
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);

    //TAO WINDOW
    m_window=SDL_CreateWindow(WINDOW_TITLE,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);
    //tao renderer
    m_renderer=SDL_CreateRenderer(m_window,-1,SDL_RENDERER_PRESENTVSYNC);

    //chon mau render
    SDL_SetRenderDrawColor(m_renderer,0,0,0,255);//mau den
    m_isRunning=true;
    Resource::LoadAllData(m_renderer);
    SetScene(new PlayScene());//tro choi bat dau

}

void Game::Terminate()
{//dung chuong trinh
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);

    SDL_Quit();

}
