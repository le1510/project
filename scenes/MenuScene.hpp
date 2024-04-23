#pragma once

#include "../Config.hpp"
#include "../components/Text.hpp"
#include "../scenes/BaseScene.hpp"
#include "../objects/AnimatedObject.hpp"
#include"MenuAnimation.hpp"

class MenuScene final : public BaseScene,public MenuAnimation
{
private:
    Text* m_title;
    Text* m_playText;
    Text* m_scoreText;
    Text* m_exitText;
    Text* m_helpText;
    SDL_Point m_mousePosition;
    SDL_Rect* m_soundRect;
    Text* m_levelText;
    float m_elapsedTime;




public:
    MenuScene();
    ~MenuScene() = default;

    void HandleEvent(SDL_Event) override;
    void Update(float) override;
    void Render(SDL_Renderer*) override;


};
