#pragma once
#include "../Config.hpp"
#include "../types/Vector2f.hpp"

class BaseObject
{
protected:
	SDL_Texture*	m_texture;
	SDL_Rect*		m_rectSrc;
	SDL_Rect*		m_rectDst;
	SDL_Rect*       m_rectCollision;
	SDL_Point*		m_origin;
	float			m_angle;
	bool			m_flipH;
    bool            m_isAlive;

public:
	BaseObject();
	~BaseObject() = default;

	virtual void Update(float) = 0;
	virtual void Render(SDL_Renderer*);
    void SetOrigin(SDL_Point origin);
    SDL_Point GetOrigin() const;

	float GetAngle() const;
	void SetAngle(float angle);

	bool GetFlipH() const;
	void SetFlipH(bool flip);

	void Move(Vector2f vector);
    SDL_Rect GetRectCollision() const;
    void SetIsAlive(bool);
    bool IsAlive() const;

    bool IsCollision(const BaseObject*) const;
};
