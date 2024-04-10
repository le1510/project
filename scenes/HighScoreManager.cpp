#include "HighScoreManager.hpp"

HighScoreManager::HighScoreManager() {
    LoadHighScores();
}

void HighScoreManager::LoadHighScores() {
    std::ifstream file(m_scoreFilePath);
    int score;
    while (file >> score) {
        m_scores.push_back(score);
    }
    file.close();
}

bool HighScoreManager::IsNewHighScore(int score) {
    return m_scores.empty() || score > *std::max_element(m_scores.begin(), m_scores.end());
}

void HighScoreManager::AddHighScore(int score) {
    m_scores.push_back(score);
    std::sort(m_scores.rbegin(), m_scores.rend());
    if (m_scores.size() > 10) {
        m_scores.resize(10);
    }
    SaveHighScores();
}

void HighScoreManager::SaveHighScores() {
    std::ofstream file(m_scoreFilePath);
    for (int score : m_scores) {
        file << score << std::endl;
    }
    file.close();
}

std::vector<int> HighScoreManager::GetHighScores() {
    return m_scores;
}
