#include "PlayScene.hpp"
PlayScene::PlayScene():
    m_elapsedTime(0.f)

{

    m_tower=new Tower();//tao ra cac doi tuong tower va player trong canh choi
    m_player=new Player();

}
void PlayScene::HandlEvent(SDL_Event e)
{
    if(e.type==SDL_MOUSEBUTTONDOWN)//NEU NGUOI DUNG DUNG CHUOT
    {
        if(e.button.button==SDL_BUTTON_LEFT && m_player->IsShotable())//BAM CHUOT TRAI
        {
            m_bullets.push_back(m_player->Shot());//thêm đạn vào _bullets để quản lý và xử lý viên đạn trong trò chơi

        }
    }

}
void PlayScene::Update(float delta)
{
    m_elapsedTime+=delta;//do thoi gian troi qua
    if(m_elapsedTime>2.f)
    {
        m_threats.push_back(Threat::Generate());//mot quai vat moi duoc phat ra
        m_elapsedTime=0.f;
    }
    m_tower->Update(delta);//cap nhat  tower
    m_player->Update(delta);//cap nhat player

    for(auto threat:m_threats)
    {
        threat->Update(delta);//cap nhat quai vat
    }

    for (auto bullet: m_bullets)
    {
        bullet->Update(delta);//cap nhat vien dan
    }

}
void PlayScene::Render(SDL_Renderer* renderer)
{
    for(auto threat:m_threats)
    {
        threat->Render(renderer);//ve quai vat len tren man hinh
    }
    for(auto bullet:m_bullets)
    {
        bullet->Render(renderer);//ve dan
    }
if (m_tower->GetOrigin().y + 100 < m_player->GetOrigin().y)
	{
		m_tower->Render(renderer);
		m_player->Render(renderer);
	}
	else
	{
		m_player->Render(renderer);
		m_tower->Render(renderer);
	}
}//kiem tra xem m_tower hay m_player ve truoc
