#pragma once
#include"../Config.hpp"
class BaseScene
{
public:

    BaseScene()=default;
    ~BaseScene()=default;
    virtual void HandlEvent(SDL_Event) = 0 ;
    virtual void Update(float) = 0 ;
    virtual void Render(SDL_Renderer*) = 0 ;

};



























