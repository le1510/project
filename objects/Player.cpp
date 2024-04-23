#include "Player.hpp"
#include "../types/Vector2f.hpp"
#include "../Resource.hpp"

Player::Player() :
    AnimatedObject(6, 0.1f),
    Damage(70),
    m_speed(150),
    m_isShotable(true)
{
    this->m_texture = Resource::TX_PLAYER;
    this->m_rectSrc->w = 72;
    this->m_rectSrc->h = 72;

    this->m_rectDst->w = 72;
    this->m_rectDst->h = 72;

    this->m_rectCollision->w = this->m_rectCollision->h = 50;
    this->m_rectCollision->x = this->m_rectCollision->y = 11;

    this->SetOrigin({ 100, 100 });

    this->m_gun = new Gun();
}

void Player::Update(float delta)
{
    this->m_elapsedTime+=delta;
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
}

void Player::Render(SDL_Renderer* renderer)
{
    BaseObject::Render(renderer);
    this->m_gun->Render(renderer);
}

bool Player::IsShotable() const
{
    return m_isShotable;
}

Bullet* Player::Shot()
{
    m_isShotable=false;
    m_elapsedTime=0.f;
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

