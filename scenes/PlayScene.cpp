#include "PlayScene.hpp"
#include "../Resource.hpp"
#include "../Game.hpp"
#include "GameOverScene.hpp"
// khai báo nơi diễn ra các hoạt động chính như chơi game
PlayScene::PlayScene():
    m_elapsedTime(0.f),//ljowi rtaoj thời gian bắt dầu là 0
    m_score(0) //khởi tạo điểm số ban đầu là 0

{

    m_tower=new Tower();//tao ra cac doi tuong tower va player trong canh choi
    m_player=new Player();
    this->m_scoreText=new Text(Resource::FONT_24);//tạo điểm với font chữ là 24
    this->m_scoreText->SetPosition({50,5});// nơi đặt điểm số

    //chay nhac nen
    Mix_PlayMusic(Resource::SFX_BACKGROUND,-1);

}
void PlayScene::HandleEvent(SDL_Event e)//xử lý sự kiện
{
    if(e.type==SDL_MOUSEBUTTONDOWN)//NEU NGUOI DUNG DUNG CHUOT
    {
        if(e.button.button==SDL_BUTTON_LEFT && m_player->IsShotable())//BAM CHUOT TRAI thì có thể bắn
        {
            Mix_PlayChannel(-1,Resource::SFX_SHOT,0);//âm thanh bắn
            m_bullets.push_back(m_player->Shot());//thêm đạn vào _bullets để quản lý và xử lý viên đạn trong trò chơi

        }
    }

}
void PlayScene::Update(float delta)//cập nhật trạng thái
{
    m_elapsedTime+=delta;//do thoi gian troi qua
    if(m_elapsedTime>2.f)//cứ 2 giây tạo ra 1 quái vật
    {
        m_threats.push_back(Threat::Generate());//mot quai vat moi duoc phat ra
        m_elapsedTime=0.f;//reset lại thời gian
    }
    m_tower->Update(delta);//cap nhat  tower
    m_player->Update(delta);//cap nhat player

    for(auto threat:m_threats)
    {
        threat->Update(delta);//cap nhat quai vat
        if(threat->IsAttackable())
        {
            this->m_tower->SetCurrentHP(this->m_tower->GetCurrentHP()-threat->Attack());
        }
    }

    for (auto bullet: m_bullets)
    {
        bullet->Update(delta);//cap nhat vien dan
    }

    for (auto bullet : this->m_bullets)//lạpư qua danh sách viên dạn trong __bullets
    {
        for (auto threat : this->m_threats) //dnh sách các mối đe dọa trong m _threats
        {
            if (bullet->IsAlive() && bullet->IsCollision(threat))//kiểm tra xem viên dạn còn sóng và va chạm với mối de dọa không
            {
                threat->SetCurrentHP(threat->GetCurrentHP() - bullet->GetDamage());//nếu đúng giảm máu của mối đe dọa và coi như viên đạn đã chết
                bullet->SetIsAlive(false);
            }
        }
    }

    for (int i = 0; i < this->m_bullets.size();)// lặp qua danh sách các viên đạn
    {
        if (!this->m_bullets[i]->IsAlive()) // !false -> true //kiẻm tra xem viên dạn còn sống hay không
        {
            this->m_bullets.erase(this->m_bullets.begin() + i); //nếu không thì xóa nó ra khỏi danh sách
        }
        else
        {
            i++;//nếu  còn sống tăng giá trị biến đếm lên i để chuyển viên dạn tiếp theo trong danh sách
        }

        for (int i = 0; i < this->m_threats.size();)//lặp qua danh sách các mối đe dọa trong m_threats
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
                i++;//nếu mối đe dọa còn sống tăng giá trị biến đêm sleen i và chuyển đến mối ded dọa tiếp theo trong danh sách
            }
        }

    }

    // neu mau cua thap duoi 0, thap chet -> chuyen qua GameOverScene
    if (!this->m_tower->IsAlive())
    {
        Game::GetInstance()->SetScene(new GameOverScene(this->m_score));
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
    this->m_scoreText->RenderText(renderer,"Score: "+std::to_string(this->m_score));//vẽ điểm số lên màn hình, là chuỗi kết hợp với giá trị điểm số hiện tại
}//kiem tra xem m_tower hay m_player ve truoc
