#pragma once

#include "../Config.hpp"
#include "../components/HP.hpp"
#include "AnimatedObject.hpp"

class Tower final : public AnimatedObject, public HP //final:de khong bi ke thu
{
private:

public:
	Tower();

	void Update(float) override;
};
