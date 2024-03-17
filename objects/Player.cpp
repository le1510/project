#include "Player.hpp"
#include "../types/Vector2f.hpp"
#include "../Resource.hpp"

Player::Player() :
	AnimatedObject(6, 0.1f),
	Damage(10),
	m_speed(150)
{
	this->m_texture = Resource::TX_PLAYER;
	this->m_rectSrc->w = 72;
	this->m_rectSrc->h = 72;

	this->m_rectDst->w = 72;
	this->m_rectDst->h = 72;

	this->SetOrigin({ 100, 100 });

	this->m_gun = new Gun();
}

void Player::Update(float delta)
{
	this->UpdateAnimation(delta);

	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);

	Vector2f vector;

	if (keyboardState[SDL_SCANCODE_A])
	{
		this->SetFlipH(true);
		vector.x = -1.f;
	}

	if (keyboardState[SDL_SCANCODE_D])
	{
		this->SetFlipH(false);
		vector.x = 1.f;
	}

	if (keyboardState[SDL_SCANCODE_W])
	{
		vector.y = -1.f;
	}

	if (keyboardState[SDL_SCANCODE_S])
	{
		vector.y = 1.f;
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
