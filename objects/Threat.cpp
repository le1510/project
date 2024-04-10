#include "Threat.hpp"
#include"Goblin.hpp"
#include"Mushroom.hpp"
#include"Skeleton.hpp"
#include"../misc/Random.hpp"
Threat::Threat(
    SDL_Texture* attackTex,
    SDL_Texture* deathTex,
    SDL_Texture* walkTex,
    int maxHP, int damage, int speed) :
    HP(maxHP),
    Damage(damage),
    m_attackTex(attackTex),
    m_deathTex(deathTex),
    m_walkTex(walkTex),
    m_speed(speed),
    m_totalHP({0,0,30,3}),
          m_currentHP({0,0,30,3}),
          m_elapsedTime(0.f),
          m_isAttackable(false)
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
        this->SetOrigin({ Random::RandomInt(0, WINDOW_WIDTH), Random::RandomBool() ? 0 : WINDOW_HEIGHT });
    }
    else
    {
        this->SetOrigin({ Random::RandomBool() ? 0 : WINDOW_WIDTH, Random::RandomInt(0, WINDOW_HEIGHT) }); //
    }
}

void Threat::SetState(ThreatState state)
{
    this->m_state = state;

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
    this->SetFlipH(this->GetOrigin().x > WINDOW_WIDTH / 2);
    this->UpdateAnimation(delta);
    auto o = this->GetOrigin();
    m_totalHP.x=m_currentHP.x=o.x-15;
    m_totalHP.y=m_currentHP.y=o.y+30;
    m_currentHP.w=(float)GetCurrentHP()/(float)GetMaxHP()*m_totalHP.w;
    if (this->m_state == ThreatState::WALK)
    {
        Vector2f vec = Vector2f((float)(WINDOW_WIDTH / 2 - o.x), (float)(WINDOW_HEIGHT / 2 - o.y));

        if (vec.Magnitude() > 80.f)
        {
            this->Move(vec.Normalize() * (float)(this->m_speed * delta));
        }
        else
        {
            this->SetState(ThreatState::ATTACK);
        }
    }
    if(this->m_state==ThreatState::ATTACK)
    {
        this->m_elapsedTime+=delta;
        if(this->m_elapsedTime>1.2f&&!this->m_isAttackable)
        {
            this->m_isAttackable=true;
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
    SDL_SetRenderDrawColor(renderer,225,225,225,255);

    SDL_RenderFillRect(renderer,&this->m_totalHP);

    if(this->GetCurrentHP()>0)
    {
        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        SDL_RenderFillRect(renderer,&this->m_currentHP);
    }

}
bool Threat::IsAttackable()const
{
    return this->m_isAttackable;
}
int Threat::Attack()
{

    this->m_isAttackable=false;
    this->m_elapsedTime=0.f;
    return this->GetDamage();
}
Threat* Threat::Generate()
{
    Threat* newThreat = nullptr;

    switch (Random::RandomInt(1, 3))
    {
    case 1:
    {
        newThreat = new Goblin();
        break;
    }
    case 2:
    {
        newThreat = new Mushroom();
        break;
    }
    case 3:
    {
        newThreat = new Skeleton();
        break;
    }
    }

    return newThreat;
}
