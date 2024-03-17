#include "PlayScene.hpp"
PlayScene::PlayScene()
{
    m_tower=new Tower();
    m_player=new Player();
}
void PlayScene::HandlEvent(SDL_Event e)
{

}
void PlayScene::Update(float delta)
{
    m_tower->Update(delta);
    m_player->Update(delta);



}
void PlayScene::Render(SDL_Renderer* renderer)
{
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
}
