#include "GuessedLetters.h"

GuessedLetters::GuessedLetters() {}

string GuessedLetters::getLetters() {
    string result = "";
    for (char c : m_guessed) {
        result += c;
        result += ' ';
    }
    return result;
}

void GuessedLetters::addLetter(char c) {
    c = toupper(c);
    m_guessed.push_back(c);
}
