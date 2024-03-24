#pragma once

#include "../Config.hpp"
#include "../components/Damage.hpp"
#include "AnimatedObject.hpp"
#include "Gun.hpp"
#include"Bullet.hpp"

class Player final : public AnimatedObject,public Damage
{
private:
	int				m_speed;//toc do
	Gun*			m_gun;//player so huu vu khi

	bool m_isShotable;
	float m_elapsedTime;

public:
	Player();
	~Player() = default;

	void Update(float) override;//cap nha trang thai nguoi choi tai 1 thoi gian float//override;ghi de ham
	void Render(SDL_Renderer*) override;


	bool IsShotable() const;
	Bullet* Shot();
};
