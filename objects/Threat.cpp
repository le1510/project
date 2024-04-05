#include "Threat.hpp"
#include"Goblin.hpp"
#include"Mushroom.hpp"
#include"Skeleton.hpp"
#include"../misc/Random.hpp"
Threat::Threat(
	SDL_Texture* attackTex,
	SDL_Texture* deathTex,
	SDL_Texture* walkTex,
	int maxHP, int damage, int speed) ://damage:su tan pha
	HP(maxHP),
	Damage(damage),
	m_attackTex(attackTex),
	m_deathTex(deathTex),
	m_walkTex(walkTex),
	m_speed(speed),
	m_totalHP({0,0,30,3}),//kich thuoc 30*3 va vi tri la (0,0)
	m_currentHP({0,0,30,3})
{
	this->SetCurrentFrame(1);
	this->SetMaxFrame(8);
	this->SetTimePerFrame(0.15f);

	this->m_state = ThreatState::WALK;
	this->m_texture = m_walkTex;

	this->m_rectSrc->w = 150;
	this->m_rectSrc->h = 150;

	this->m_rectDst->w = 150;
	this->m_rectDst->h = 150;

	if (Random::RandomBool())
	{
		this->SetOrigin({ Random::RandomInt(0, WINDOW_WIDTH), Random::RandomBool() ? 0 : WINDOW_HEIGHT });//tr ve mot gia tr ngau nhien trong khoang tu 0 den window width cho x, windowheight cho y
	}
	else
	{
		this->SetOrigin({ Random::RandomBool() ? 0 : WINDOW_WIDTH , Random::RandomInt(0, WINDOW_HEIGHT) });//vi tri ngau nhien de sinh ra quai vat
	}
}

void Threat::SetState(ThreatState state)
{
	this->m_state = state;//state:tinh trang

	switch (this->m_state)
	{
	case ThreatState::ATTACK:
	{
		this->m_texture = this->m_attackTex;
		this->SetMaxFrame(8);
		this->SetCurrentFrame(1);

		break;
	}
	case ThreatState::DEATH:
	{
		this->m_texture = this->m_deathTex;
		this->SetMaxFrame(4);
		this->SetCurrentFrame(1);

		break;
	}
	case ThreatState::WALK:
	{
		this->m_texture = this->m_walkTex;
		this->SetMaxFrame(8);
		this->SetCurrentFrame(1);

		break;
	}
	}
}

ThreatState Threat::GetState() const
{
	return this->m_state;
}

void Threat::Update(float delta)
{
	this->SetFlipH(this->GetOrigin().x > WINDOW_WIDTH / 2);//giup doi tuong luon huong ve vi tri tower khong di vi tri khac
	this->UpdateAnimation(delta);
    auto o = this->GetOrigin();
    m_totalHP.x=m_currentHP.x=o.x-15;//o.x;o.y vi tri goc cua doi tuong threat
    m_totalHP.y=m_currentHP.y=o.y+30;//de thnh mau hien duoi chan doi tuong

    m_currentHP.w=(float)GetCurrentHP()/(float)GetMaxHP()*m_totalHP.w;//lay mau hien tai/mau max*chieu rong thanh mau

	if (this->m_state == ThreatState::WALK)
	{
		Vector2f vec = Vector2f((float)(WINDOW_WIDTH / 2 - o.x), (float)(WINDOW_HEIGHT / 2 - o.y));

		if (vec.Magnitude() > 80.f)//do lon vector co lon hon 80 khong//kiem tra khoang cach giua threat voi trung tam cua so, neu lon hon 80 thi se di chuyen theo huong trung tam, con khong thi se khong di chuyen va tan cong
		{
			this->Move(vec.Normalize() * (float)(this->m_speed * delta));//chuyen doi vector do dai bang 1 nhung huong giu nguyen, tich toc do di chuyen nhan thoi gian taoj quang duong
		}
		else
		{
			this->SetState(ThreatState::ATTACK);
		}
	}

	if (this->GetCurrentHP() <= 0 && this->m_state != ThreatState::DEATH)
{
	this->SetState(ThreatState::DEATH);
}

if (this->m_state == ThreatState::DEATH && this->GetCurrentFrame() == 4)
{
	this->m_isAlive = false;
}
}
void Threat::Render(SDL_Renderer* renderer )
{
    BaseObject::Render(renderer);
    SDL_SetRenderDrawColor(renderer,225,225,225,255);//mau den

    SDL_RenderFillRect(renderer,&this->m_totalHP);//ve thanh mau tong cua quai vat mau do
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderFillRect(renderer,&this->m_currentHP);//ve hinh chu nhat mau do de dai dien thanh mau tong hien tai

}
Threat* Threat::Generate()//tao ra quai vat ngau nhien
{
	Threat* newThreat = nullptr;

	switch (Random::RandomInt(1, 3))
	{
	case 1:
	{
		newThreat = new Goblin();//yeu tinh
		break;
	}
	case 2:
	{
		newThreat = new Mushroom();//nấm
		break;
	}
	case 3:
	{
		newThreat = new Skeleton();//bộ xương
		break;
	}
	}

	return newThreat;
}
