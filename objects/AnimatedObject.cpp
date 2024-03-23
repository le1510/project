#include "AnimatedObject.hpp"

AnimatedObject::AnimatedObject(int maxFrame, float timePerFrame) :
	m_maxFrame(maxFrame),//so luong khung hinh toi da
	m_currentFrame(1),
	m_timePerFrame(timePerFrame),//thoi gian hien thi 1 khung hinh
	m_elapsedTime(0.f)//time choi game
{
}

void AnimatedObject::UpdateAnimation(float delta)
{
	this->m_elapsedTime += delta;

	if (this->m_elapsedTime > m_timePerFrame)
	{
		this->m_elapsedTime -= m_timePerFrame;

		this->m_currentFrame++;//di chuyen khung hinh tiep theo

		if (this->m_currentFrame > this->m_maxFrame)
		{
			this->m_currentFrame = 1;
		}

		if (this->m_rectSrc != nullptr)
		{
			this->m_rectSrc->x = this->m_rectSrc->w * (this->m_currentFrame - 1);//cat 1 phan hinh anh lien tiep de nhan vat di chuyen
		}
	}
}
void AnimatedObject::SetMaxFrame(int maxFrame)
{
    this->m_maxFrame=maxFrame;
}
void AnimatedObject::SetCurrentFrame(int currentFrame)
{
    this->m_currentFrame=currentFrame;
}
void AnimatedObject::SetTimePerFrame(float timePerFrame)
{
    this->m_timePerFrame=timePerFrame;
}
