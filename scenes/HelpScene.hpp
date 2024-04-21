#pragma once

#include "../Config.hpp"
#include "../scenes/BaseScene.hpp"
class HelpScene final : public BaseScene
{
private:
    float m_elapsedTime;

public:
    HelpScene();
    ~HelpScene() = default;

    void HandleEvent(SDL_Event) override;
    void Update(float) override;
    void Render(SDL_Renderer*) override;
};
