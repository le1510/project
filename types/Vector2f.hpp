#pragma once

class Vector2f
{
public:
	float x;
	float y;

public:
	Vector2f();
	Vector2f(float, float);

	float Magnitude() const;
	Vector2f Normalize() const;

	Vector2f operator*(float) const;
};
