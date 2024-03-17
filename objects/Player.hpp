#pragma once

#include "../Config.hpp"
#include "../components/Damage.hpp"
#include "AnimatedObject.hpp"
#include "Gun.hpp"

class Player final : public AnimatedObject, Damage
{
private:
	int				m_speed;
	Gun*			m_gun;

public:
	Player();
	~Player() = default;

	void Update(float) override;
	void Render(SDL_Renderer*) override;
};
