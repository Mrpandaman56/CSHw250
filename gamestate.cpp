#include "GameState.h"

GameState::GameState() {
    m_nextState = 0;
    m_allStates = {
        "HEAD", "BODY", "LEFT_FRONT_LEG", "LEFT_MIDDLE_LEG", "LEFT_BACK_LEG",
        "RIGHT_FRONT_LEG", "RIGHT_MIDDLE_LEG", "RIGHT_BACK_LEG"
    };
}

string GameState::getState() {
    string result = "";
    for (const string& s : m_state) {
        result += s + " ";
    }
    return result;
}

void GameState::addState() {
    if (m_nextState < (int)m_allStates.size()) {
        m_state.push_back(m_allStates[m_nextState]);
        m_nextState++;
    }
}

bool GameState::gameOver() {
    return m_nextState >= (int)m_allStates.size();
}
