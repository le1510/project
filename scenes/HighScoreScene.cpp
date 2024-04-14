#include "MenuScene.hpp"
#include "HighScoreScene.hpp"
#include "HighScoreScene.hpp"
#include "../Resource.hpp"
#include "../Game.hpp"

HighScoreScene::HighScoreScene() :
    m_elapsedTime(0.f)
{
    this->m_title = new Text(Resource::FONT_96);
    this->m_title->SetPosition({ 420, 120 });

    this->LoadFromFile();
}

void HighScoreScene::HandleEvent(SDL_Event e)
{
    if (e.type == SDL_MOUSEBUTTONDOWN)
    {
        if (e.button.button == SDL_BUTTON_LEFT && this->m_elapsedTime > 0.5f)
        {
            Game::GetInstance()->SetScene(new MenuScene());
        }
    }
}

void HighScoreScene::Update(float delta)
{
    this->m_elapsedTime += delta;
}

void HighScoreScene::Render(SDL_Renderer* renderer)
{
    this->m_title->RenderText(renderer, "High Score");

    int startY = 250;
    int lineHeight = 60;

    for (size_t i = 0; i < m_scores.size(); ++i)
    {
        std::string scoreText = "Score " + std::to_string(i + 1) + ": " + std::to_string(m_scores[i]);

        Text* scoreDisplay = new Text(Resource::FONT_48);
        scoreDisplay->SetPosition({ 492, startY + static_cast<int>(i) * lineHeight });
        scoreDisplay->RenderText(renderer, scoreText);
    }
}

void HighScoreScene::LoadFromFile()
{
    std::ifstream inputFile("scores.txt");

    int score;
    while (inputFile >> score)
    {
        m_scores.push_back(score);
    }

    inputFile.close();
}
