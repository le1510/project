#include "Tower.hpp"
#include "../Resource.hpp"

Tower::Tower() :
    AnimatedObject(11, 0.15f),
    HP(100)
{
    this->m_texture = Resource::TX_MAP_TOWER;
    this->m_rectSrc->w = 100;
    this->m_rectSrc->h = 140;

    this->m_rectDst->w = 150;
    this->m_rectDst->h = 210;
    this->m_rectDst->x = (WINDOW_WIDTH - this->m_rectDst->w) / 2;
    this->m_rectDst->y = (WINDOW_HEIGHT - this->m_rectDst->h) / 2;

    this->m_rectCollision->w = 80;
    this->m_rectCollision->h = 130;
    this->m_rectCollision->x = this->m_rectDst->x + (this->m_rectDst->w - this->m_rectCollision->w) / 2;
    this->m_rectCollision->y = this->m_rectDst->y + (this->m_rectDst->h - this->m_rectCollision->h) / 2 + 30;
    m_totalHP.w=m_currentHP.w=WINDOW_WIDTH/2;
    m_totalHP.h=m_currentHP.h=5;
    m_totalHP.x=m_currentHP.x=(WINDOW_WIDTH-m_totalHP.w)/2;
    m_totalHP.y=m_currentHP.y=10;

}

void Tower::Update(float delta)
{

    this->UpdateAnimation(delta);//cap nhat trang thai tower
    this->m_currentHP.w = (int)((float)this->GetCurrentHP() / (float)this->GetMaxHP() * this->m_totalHP.w);//máu hiện tại/máu tối đa nhân chiều dài thanh máu để tạo ra chièu dài thanh máu hiện tại
    if(this->GetCurrentHP()<=0)
    {
        this->m_isAlive=false;//thanh máu đã chết
    }
}
void Tower::Render(SDL_Renderer* renderer )
{
    BaseObject::Render(renderer);
    SDL_SetRenderDrawColor(renderer,225,225,225,255);//mau den

    SDL_RenderFillRect(renderer,&this->m_totalHP);

    if(this->GetCurrentHP()>0)
    {
    SDL_SetRenderDrawColor(renderer,255,255,0,255);//MAU vang
    SDL_RenderFillRect(renderer,&this->m_currentHP);
    }
}
