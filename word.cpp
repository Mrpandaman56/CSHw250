#include "Word.h"

Word::Word(string word) {
    m_word = word;
    for (size_t i = 0; i < m_word.length(); i++) {
        m_currentWord.push_back('_');
    }
}

string Word::getWord() {
    string display = "";
    for (char c : m_currentWord) {
        display += c;
        display += ' ';
    }
    return display;
}

void Word::addLetter(char c) {
    c = toupper(c);
    auto itCurrent = m_currentWord.begin();
    for (size_t i = 0; i < m_word.length(); i++, ++itCurrent) {
        if (toupper(m_word[i]) == c) {
            *itCurrent = c;
        }
    }
}

bool Word::findLetter(char c) {
    c = toupper(c);
    for (char letter : m_word) {
        if (toupper(letter) == c) {
            return true;
        }
    }
    return false;
}

bool Word::solved() {
    auto itCurrent = m_currentWord.begin();
    for (size_t i = 0; i < m_word.length(); i++, ++itCurrent) {
        if (*itCurrent == '_') {
            return false;
        }
    }
    return true;
}
