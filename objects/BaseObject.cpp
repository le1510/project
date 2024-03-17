 #include "BaseObject.hpp"

BaseObject::BaseObject() :
	m_texture(nullptr),
	m_angle(0.f),
	m_flipH(false)
{
	this->m_rectSrc = new SDL_Rect();
	this->m_rectDst = new SDL_Rect();
	this->m_origin = new SDL_Point();
}

void BaseObject::Render(SDL_Renderer* renderer)
{
	if (this->m_texture != nullptr)
	{
		SDL_Point* center = new SDL_Point();
		center->x = this->m_rectDst->w / 2;
		center->y = this->m_rectDst->h / 2;

		SDL_RendererFlip flip = this->m_flipH ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

		SDL_RenderCopyEx(
			renderer,
			this->m_texture,
			this->m_rectSrc,
			this->m_rectDst,
			this->m_angle,
			center,
			flip
		);
	}
}

SDL_Point BaseObject::GetOrigin() const
{
	this->m_origin->x = this->m_rectDst->w / 2 + this->m_rectDst->x;
	this->m_origin->y = this->m_rectDst->w / 2 + this->m_rectDst->y;

	return *this->m_origin;
}

void BaseObject::SetOrigin(SDL_Point origin)
{
	SDL_Point o = this->GetOrigin();
	int xOffset = origin.x - o.x;
	int yOffset = origin.y - o.y;

	this->m_rectDst->x += xOffset;
	this->m_rectDst->y += yOffset;

	this->m_origin->x = origin.x;
	this->m_origin->y = origin.y;
}

float BaseObject::GetAngle() const
{
	return this->m_angle;
}

void BaseObject::SetAngle(float angle)
{
	while (angle >= 360)
	{
		angle -= 360;
	}

	this->m_angle = angle;
}

bool BaseObject::GetFlipH() const
{
	return this->m_flipH;
}

void BaseObject::SetFlipH(bool flip)
{
	this->m_flipH = flip;
}

void BaseObject::Move(Vector2f vector)
{
	auto origin = this->GetOrigin();
	origin.x += (int) vector.x;
	origin.y += (int) vector.y;

	this->SetOrigin(origin);
}
