#pragma once

class Vector2f
{
public:
	float x;
	float y;

public:
	Vector2f();
	Vector2f(float, float);

	float Magnitude() const;//kich co can bac 2 cua x2 y2

	Vector2f Normalize() const;//tra ve vector cung hong vector goc nhung magnitude=1 //chuan hoa normalize vector

	Vector2f operator*(float) const;//nhan mot kieu floar voi vector 2f
};
