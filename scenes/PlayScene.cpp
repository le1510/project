#include "PlayScene.hpp"
PlayScene::PlayScene()
{
    m_tower=new Tower();//tao ra cac doi tuong tower va player trong canh choi
    m_player=new Player();
    m_threat=Threat::Generate();
}
void PlayScene::HandlEvent(SDL_Event e)
{

}
void PlayScene::Update(float delta)
{
    m_tower->Update(delta);
    m_player->Update(delta);
    m_threat->Update(delta);



}
void PlayScene::Render(SDL_Renderer* renderer)
{
    m_threat->Render(renderer);
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
