#pragma once

#include "../Config.hpp"
#include "../types/Vector2f.hpp"

class BaseObject
{
protected:
	SDL_Texture*	m_texture;
	SDL_Rect*		m_rectSrc;
	SDL_Rect*		m_rectDst;
	SDL_Point*		m_origin;
	float			m_angle;
	bool			m_flipH;

public:
	BaseObject();
	~BaseObject() = default;

	virtual void Update(float) = 0;

	virtual void Render(SDL_Renderer*);

	SDL_Point GetOrigin() const;
	void SetOrigin(SDL_Point origin);

	float GetAngle() const;
	void SetAngle(float angle);

	bool GetFlipH() const;
	void SetFlipH(bool flip);

	void Move(Vector2f vector);
};
