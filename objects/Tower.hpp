#pragma once

#include "../Config.hpp"
#include "../components/HP.hpp"
#include "AnimatedObject.hpp"

class Tower final : public AnimatedObject, public HP //final:de khong bi ke thu
{
private:
    SDL_Rect m_totalHP;// max mau
    SDL_Rect m_currentHP;//mau hien tai

public:
	Tower();

	void Update(float) override;//update mau hien tai//de hinh anh
	void Render(SDL_Renderer*) override;//ve hinh anh len man hinh
};
