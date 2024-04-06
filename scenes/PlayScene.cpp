#include "PlayScene.hpp"
#include "../Resource.hpp"

PlayScene::PlayScene():
    m_elapsedTime(0.f),
    m_score(0)

{

    m_tower=new Tower();//tao ra cac doi tuong tower va player trong canh choi
    m_player=new Player();
    this->m_scoreText=new Text(Resource::FONT_24);
    this->m_scoreText->SetPosition({50,5});

    //chay nhac nen
    Mix_PlayMusic(Resource::SFX_BACKGROUND,-1);

}
void PlayScene::HandlEvent(SDL_Event e)
{
    if(e.type==SDL_MOUSEBUTTONDOWN)//NEU NGUOI DUNG DUNG CHUOT
    {
        if(e.button.button==SDL_BUTTON_LEFT && m_player->IsShotable())//BAM CHUOT TRAI
        {
            Mix_PlayChannel(-1,Resource::SFX_SHOT,0);
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

    for (auto bullet : this->m_bullets)
{
	for (auto threat : this->m_threats)
	{
		if (bullet->IsAlive() && bullet->IsCollision(threat))
		{
			threat->SetCurrentHP(threat->GetCurrentHP() - bullet->GetDamage());
			bullet->SetIsAlive(false);
		}
	}
}

 for (int i = 0; i < this->m_bullets.size();)
{
	if (!this->m_bullets[i]->IsAlive()) // !false -> true
	{
		this->m_bullets.erase(this->m_bullets.begin() + i);
	}
	else
	{
		i++;
	}
}

for (int i = 0; i < this->m_threats.size();)
{
    //neu quai vat chet
	if (!this->m_threats[i]->IsAlive())
	{
	    //xoa quai vat chet khoi danh sach
		this->m_threats.erase(this->m_threats.begin() + i);
        //cong diem
        this->m_score+=this->m_threats[i]->Score();
	}
	else
	{
		i++;
	}
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
	this->m_scoreText->RenderText(renderer,"Score: "+std::to_string(this->m_score));
}//kiem tra xem m_tower hay m_player ve truoc
