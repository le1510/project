#include "Player.hpp"
#include "../types/Vector2f.hpp"
#include "../Resource.hpp"

Player::Player() :
    AnimatedObject(11, 0.1f),
    Damage(70),
    m_speed(150),
    m_isShotable(true),
    m_scale(1.0f),
    HP(200),
    m_totalHP({0,0,40,5 }),
    m_currentHP({0,0,40,5}),
     m_currentAmmo(10),
    m_maxAmmo(10)


{
    this->m_texture = Resource::TX_PLAYER;
    this->m_rectSrc->w = 72;
    this->m_rectSrc->h = 78;

    this->m_rectDst->w = 72;
    this->m_rectDst->h = 78;

    this->m_rectCollision->w = this->m_rectCollision->h = 50;
    this->m_rectCollision->x = this->m_rectCollision->y = 11;

    this->SetOrigin({ 100, 100 });

    this->m_gun = new Gun();


}
//void Player::UpdateTexture(const std::string& texturePath)
//{
//    if (texturePath == "yellow")
//    {
//        this->m_texture = Resource::TX_PLAYERYELLOW;
//    }
//    else if (texturePath == "red")
//    {
//        m_texture = Resource::TX_PLAYERRED;
//    }
//    else if (texturePath == "blue")
//    {
//        m_texture = Resource::TX_PLAYERBLUE;
//    }
//    else if (texturePath == "green")
//    {
//        m_texture = Resource::TX_PLAYERGREEN;
//    }
//    else
//    {
//        // Mặc định là màu vàng nếu đường dẫn không hợp lệ
//        m_texture = Resource::TX_PLAYERYELLOW;
//    }
//}

void Player::Update(float delta)
{
    this->m_elapsedTime+=delta;
    auto o = this->GetOrigin();
    m_totalHP.x=m_currentHP.x=o.x-20 ;
    m_totalHP.y=m_currentHP.y=o.y+30;
    m_currentHP.w=(float)GetCurrentHP()/(float)GetMaxHP()*m_totalHP.w;

    if(m_elapsedTime>0.5f)
    {
        m_isShotable=true;
    }
    this->UpdateAnimation(delta);

    const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
    Vector2f vector;

    bool isMoving = false;

    if (keyboardState[SDL_SCANCODE_A])
    {
        this->SetFlipH(true);
        vector.x = -1.f;
        isMoving = true;
    }

    if (keyboardState[SDL_SCANCODE_D])
    {
        this->SetFlipH(false);
        vector.x = 1.f;
        isMoving = true;
    }

    if (keyboardState[SDL_SCANCODE_W])
    {
        vector.y = -1.f;
        isMoving = true;
    }

    if (keyboardState[SDL_SCANCODE_S])
    {
        vector.y = 1.f;
        isMoving = true;
    }

    vector = vector.Normalize();

    if (!isMoving)
    {
        this->SetCurrentFrame(1);
    }
    if (isMoving)
    {
        this->UpdateAnimation(delta);
    }

    vector = vector.Normalize();

    this->Move(vector * (delta * this->m_speed));
    int xOffset = this->m_rectDst->w / 2;
    int yOffset = this->m_rectDst->h / 2;

    if (this->m_origin->x < xOffset)
    {
        this->SetOrigin({ xOffset, this->m_origin->y });
    }

    if (this->m_origin->x > WINDOW_WIDTH - xOffset)
    {
        this->SetOrigin({ WINDOW_WIDTH - xOffset, this->m_origin->y });
    }

    if (this->m_origin->y < yOffset)
    {
        this->SetOrigin({ this->m_origin->x, yOffset });
    }

    if (this->m_origin->y > WINDOW_HEIGHT - yOffset)
    {
        this->SetOrigin({ this->m_origin->x, WINDOW_HEIGHT - yOffset });
    }

    this->m_gun->SetOrigin(this->GetOrigin());
    this->m_gun->Update(delta);
    this->UpdateAmmo(m_maxAmmo - m_shotsFired);
}

void Player::Render(SDL_Renderer* renderer) {
    BaseObject::Render(renderer);
    this->m_gun->Render(renderer);
    SDL_SetRenderDrawColor(renderer, 225, 225, 225, 255);
    SDL_RenderFillRect(renderer, &this->m_totalHP);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Màu xanh dương

    if (this->GetCurrentHP() > 0) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &this->m_currentHP);
    }

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Màu xanh lá cây cho thanh đạn
    int ammoWidth = static_cast<int>((static_cast<float>(m_currentAmmo) / static_cast<float>(m_maxAmmo)) * m_totalHP.w);
    SDL_Rect currentAmmoRect = { m_totalHP.x, m_totalHP.y + m_totalHP.h, ammoWidth, 5 }; // Lượng đạn còn lại
    SDL_RenderFillRect(renderer, &currentAmmoRect);
}



bool Player::IsShotable() const
{
    return m_isShotable;
}
void Player::DecreaseBulletDamage(int amount)
{
    for (auto bullet : m_bullets)
    {
        bullet->DecreaseDamage(amount);
    }
}

Bullet* Player::Shot()
{
    m_isShotable=false;
    m_elapsedTime=0.f;
    DecreaseBulletDamage(5);

    return new Bullet(m_gun->GetAngle(),GetOrigin());
}
void Player::Scale(float scaleFactor)
{
    this->m_rectDst->w *= scaleFactor;
    this->m_rectDst->h *= scaleFactor;

    this->m_rectDst->x -= (this->m_rectDst->w * scaleFactor - this->m_rectDst->w) / 2;
    this->m_rectDst->y -= (this->m_rectDst->h * scaleFactor - this->m_rectDst->h) / 2;

    this->m_rectCollision->w *= scaleFactor;
    this->m_rectCollision->h *= scaleFactor;
    this->m_rectCollision->x -= (this->m_rectCollision->w * scaleFactor - this->m_rectCollision->w) / 2;
    this->m_rectCollision->y -= (this->m_rectCollision->h * scaleFactor - this->m_rectCollision->h) / 2;
}
float Player::GetScale() const
{
    return m_scale;
}

