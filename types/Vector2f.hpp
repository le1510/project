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

	Vector2f Normalize() const;//tra ve vector cung huong vector goc nhung độ lớn =1 //chuan hoa normalize vector

	Vector2f operator*(float) const;//nhan mot kieu float  voi vector 2f
};
