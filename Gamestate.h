#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

class GameState {
private:
    list<string> m_state;
    vector<string> m_allStates;
    int m_nextState;

public:
    GameState();
    string getState();
    void addState();
    bool gameOver();
};

#endif
