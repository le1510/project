#pragma once

#include "../Config.hpp"
#include "../components/Text.hpp"
#include "../scenes/BaseScene.hpp"

class MenuScene final : public BaseScene
{
private:
    Text* m_title;
    Text* m_playText;
    Text* m_scoreText;
    Text* m_exitText;
    SDL_Point m_mousePosition;

public:
    MenuScene();
    ~MenuScene() = default;

    void HandleEvent(SDL_Event) override;
    void Update(float) override;
    void Render(SDL_Renderer*) override;
};
