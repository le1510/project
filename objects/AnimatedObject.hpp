#pragma once

#include "../Config.hpp"
#include "BaseObject.hpp"

class AnimatedObject : public BaseObject
{
private:
	int			m_maxFrame;//max khung canh 1 giay
	int			m_currentFrame;// khung hinh hien tai
	float		m_timePerFrame;//xu li hinh anh video
	float		m_elapsedTime;//khoang thoi gian choi game

public:
	AnimatedObject() = default;
	AnimatedObject(int, float);

	void UpdateAnimation(float);// cap nhat  trang thai

	void SetMaxFrame(int);//thiet lapa so khung hinh toi da
	void SetCurrentFrame(int);//thiet lap khung hinh hien ti
	void SetTimePerFrame(float);//thiet lap thoi gin de khung anh nay sang khung hinh tiep theo
	int GetCurrentFrame() const;
};
