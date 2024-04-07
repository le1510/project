#pragma once

#include "../Config.hpp"
#include "BaseObject.hpp"

class AnimatedObject : public BaseObject//kế thừa lớp của hoạt hình
{
private:
	int			m_maxFrame;//so khung hình tối đa của 1 đối tương
	int			m_currentFrame;// khung hinh hien tai
	float		m_timePerFrame;//xu li hinh anh video//thoiư gian chuyển tư khung hình này sang khung hình tiếp theo
	float		m_elapsedTime;//khoang thoi gian choi game

public:
	AnimatedObject() = default;
	AnimatedObject(int, float);

	void UpdateAnimation(float);// cap nhat  trang thai

	void SetMaxFrame(int);//thiet lapa so khung hinh toi da
	void SetCurrentFrame(int);//thiet lap khung hinh hien ti
	void SetTimePerFrame(float);//thiet lap thoi gin de khung anh nay sang khung hinh tiep theo
	int GetCurrentFrame() const;//lay khung hinh hien tai
};
