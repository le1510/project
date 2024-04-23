#pragma once

#include "../Config.hpp"
#include "../scenes/BaseScene.hpp"
#include "../components/Text.hpp"

class LevelScene final : public BaseScene
{
private:
    float m_elapsedTime;
     Text* easyText;
    Text* mediumText;
    Text* hardText;
    SDL_Point m_mousePosition;

public:
    LevelScene();
    ~LevelScene() = default;

    void HandleEvent(SDL_Event) override;
    void Update(float) override;
    void Render(SDL_Renderer*) override;
};
