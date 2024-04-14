#pragma once

#include "../Config.hpp"
#include "../components/Text.hpp"
#include "../scenes/BaseScene.hpp"
class HighScoreScene final : public BaseScene
{
private:
    Text* m_title;
    std::vector<int> m_scores;
    float m_elapsedTime;

public:
    HighScoreScene();
    ~HighScoreScene() = default;

    void HandleEvent(SDL_Event) override;
    void Update(float) override;
    void Render(SDL_Renderer*) override;

    void LoadFromFile();
};
