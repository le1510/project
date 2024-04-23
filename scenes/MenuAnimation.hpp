#pragma once

#include "../Config.hpp"
#include "../objects/BaseObject.hpp"

class MenuAnimation : public BaseObject
{
private:
    int m_maxFrame;
    int m_currentFrame;
    float m_timePerFrame;
    float m_elapsedTime;

public:
    MenuAnimation() = default;
    MenuAnimation(int , float );
    void UpdateAnimation(float);
    void SetMaxFrame(int);
    void SetCurrentFrame(int);
    void SetTimePerFrame(float);
    int GetCurrentFrame() const;
};
