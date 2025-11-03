#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Word {
private:
    list<char> m_currentWord;
    string m_word;

public:
    Word(string word);
    string getWord();
    void addLetter(char c);
    bool findLetter(char c);
    bool solved();
};

#endif
