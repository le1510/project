#include "Vector2f.hpp"
#include <cmath>

Vector2f::Vector2f() :
	x(0.f),//x=0; y=0;
	y(0.f)
{
}

Vector2f::Vector2f(float _x, float _y) :
	x(_x),
	y(_y)
{
}

float Vector2f::Magnitude() const
{
	return std::sqrt(this->x * this->x + this->y * this->y);
}

Vector2f Vector2f::Normalize() const
{
	float mag = this->Magnitude();

	if (mag != 0.0f)
	{
		return Vector2f(x / mag, y / mag);
	}
	else
	{
		return *this;
	}
}

Vector2f Vector2f::operator*(float scalar) const
{
	return Vector2f(x * scalar, y * scalar);
}
