#include "GameOverScene.hpp"
#include "MenuScene.hpp"
#include "../Game.hpp"
#include "../Resource.hpp"
#include "../misc/Utils.hpp"


GameOverScene::GameOverScene(int score) :
    m_elapsedTime(0.f)
{
    this->m_scoreStr = "Score: " + toFiveDigitString(score);

    this->m_title = new Text(Resource::FONT_96);
    this->m_title->SetPosition({ 438, 180 });

    this->m_scoreText = new Text(Resource::FONT_48);
    this->m_scoreText->SetPosition({ 492, 300 });

    this->SaveScore(score);
}

void GameOverScene::HandleEvent(SDL_Event e)
{
    if (e.type == SDL_MOUSEBUTTONDOWN)
    {
        if (e.button.button == SDL_BUTTON_LEFT && this->m_elapsedTime > 0.5f)
        {
            Game::GetInstance()->SetScene(new MenuScene());// chuyển màn hình ra menu
        }
    }
}

void GameOverScene::Update(float delta)
{
    this->m_elapsedTime += delta;
}

void GameOverScene::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, Resource::TX_BACKGROUND_2, nullptr, nullptr);

    this->m_title->RenderText(renderer, "GAME OVER");

    this->m_scoreText->RenderText(renderer, this->m_scoreStr);
}

void GameOverScene::SaveScore(int score)
{
    std::vector<int> scores;
    std::ifstream inputFile("scores.txt");
    int tempScore;

    while (inputFile >> tempScore)
    {
        scores.push_back(tempScore);
    }

    inputFile.close();

    scores.push_back(score);

    std::sort(scores.rbegin(), scores.rend());

    std::ofstream outputFile("scores.txt");
    for (size_t i = 0; i < std::min(scores.size(), static_cast<size_t>(5)); ++i)
    {
        outputFile << scores[i] << std::endl;
    }
    outputFile.close();
}
