#pragma once

#include "../Config.hpp"
#include "BaseObject.hpp"

class Gun : public BaseObject
{
private:

public:
	Gun();//sung
	~Gun() = default;

	void Update(float) override;//cập nhật trạng thái của súng dựa trên thời gian trôi qua
};
