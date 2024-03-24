#pragma once

#include "../Config.hpp"
#include "../components/HP.hpp"
#include "AnimatedObject.hpp"

class Tower final : public AnimatedObject, public HP //final:de khong bi ke thu
{
private:
    SDL_Rect m_totalHP;
    SDL_Rect m_currentHP;

public:
	Tower();

	void Update(float) override;
	void Render(SDL_Renderer*) override;
};
