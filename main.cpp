#include <iostream>
#include "Word.h"
#include "GuessedLetters.h"
#include "GameState.h"
using namespace std;

int main() {
    cout << "Welcome to Hang-Animal!" << endl;
    string secretWord;
    cout << "Enter the secret word: ";
    cin >> secretWord;

    Word word(secretWord);
    GuessedLetters guessed;
    GameState state;

    while (!word.solved() && !state.gameOver()) {
        cout << "\nWord: " << word.getWord() << endl;
        cout << "Guessed letters: " << guessed.getLetters() << endl;
        cout << "Enter a letter: ";

        char guess;
        cin >> guess;

        if (word.findLetter(guess)) {
            word.addLetter(guess);
            cout << "Correct!\n";
        } else {
            cout << "Incorrect!\n";
            guessed.addLetter(guess);
            state.addState();
            cout << "Animal state: " << state.getState() << endl;
        }
    }

    if (word.solved()) {
        cout << "\nYou saved the animal!" << endl;
    } else {
        cout << "\nThe animal has been hung!" << endl;
    }

    return 0;
}
