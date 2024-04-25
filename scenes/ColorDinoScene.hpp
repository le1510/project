#pragma once

#include "../Config.hpp"
#include "../scenes/BaseScene.hpp"
#include "../components/Text.hpp"
#include "PlayScene.hpp"
#include"MenuAnimation.hpp"
class ColorDinoScene final : public BaseScene,public MenuAnimation
{
private:
    float m_elapsedTime;
    Text* yellowText;
    Text* redText;
    Text* greenText;
    Text* blueText;

    SDL_Point m_mousePosition;
    PlayScene* m_playScene;


public:
    ColorDinoScene();
    ~ColorDinoScene() = default;
    ColorDinoScene(PlayScene* playScene);

    void HandleEvent(SDL_Event) override;
    void Update(float) override;
    void Render(SDL_Renderer*) override;
};
