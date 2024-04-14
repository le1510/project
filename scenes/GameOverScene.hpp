#pragma once

#include "../Config.hpp"
#include "../components/Text.hpp"
#include "../scenes/BaseScene.hpp"

class GameOverScene : public BaseScene
{
private:
    Text* m_title;
    Text* m_scoreText;

    std::string m_scoreStr;

    float m_elapsedTime;

public:
    GameOverScene(int);
    ~GameOverScene() = default;

    void HandleEvent(SDL_Event) override;
    void Update(float) override;
    void Render(SDL_Renderer*) override;

    void SaveScore(int);
};
