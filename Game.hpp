#pragma once
#include"Config.hpp"
#include"scenes/BaseScene.hpp"
//class game
class Game
{

private:

    SDL_Window* m_window;// đại diện cho cửa sổ hiển thị trò chơi
    SDL_Renderer* m_renderer;// trình kết xuất đồ họa để vẽ đồ họa lên cửa sổ
    BaseScene *m_scene;// con trỏ đến đối tượng lớp basescene đại diện cho cảnh hiện tại đang chạy trong trò chơi
    bool m_isRunning;// xác định xem trò chơi có đang chạy hay khong
public:
    Game();
    ~Game();
    void Run();
    //sinmgleton pattern
    static Game* GetInstance();// chỉ có 1 dối tượng duy nhất tạo ra vào truy cập vào chương trình
    void SetScene(BaseScene*);// đặt cảnh hiện tại của trò chơi
private:
//ham khoi tao game
    void Initialize();
    //ham  huy game
    void Terminate();
};
