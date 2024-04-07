#pragma once
#include"BaseScene.hpp"
#include "../components/Text.hpp"
#include"../objects/Player.hpp"
#include"../objects/Tower.hpp"
#include"../objects/Threat.hpp"
#include"../objects/Bullet.hpp"

class PlayScene: public BaseScene

{
private:
    Player*  m_player;// con tro đến đối tượng người chơi trong trò chơi
    Tower* m_tower;// con trỏ đến đối tượng tháp trong trò chơi
    float m_elapsedTime; // thời gian đã trôi qua từ khi bắt đầu trò chơi
    std::vector<Threat*> m_threats; //vector chứa các con trỏ đến csc đối tượng mối đe dọa trong trò chơi
    std::vector<Bullet*> m_bullets; //vector chứa các con trỏ đến đối tượng đạn trong trò chơi
    int  m_score;// điểm số của người chơi trong trò choi
    Text* m_scoreText;// con trỏ trỏ đéne đối tượng văn bản để hiển thị điểm số

public:
    PlayScene();// hàm khởi tạo lớp

     void HandlEvent(SDL_Event) override ;//ghi de hinh anh
void Update(float) override;// cậpt nhật trạng thais của cảnh dựa theo thời gian trôi qua
     void Render(SDL_Renderer*) override ;// vẽ các đối tượng và hiển thị cảnh chơi lên màn hình
};
