#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>     

using namespace std;

int main(){
    srand(time(0));
    vector<string> hangmanStages = {
        R"(
         _______
        |/
        |
        |
        |
        |
       _|___
        )",

        R"(
         _______
        |/      |
        |      (_)
        |
        |
        |
       _|___
        )",

        R"(
         _______
        |/      |
        |      (_)
        |       |
        |       |
        |
       _|___
        )",

        R"(
         _______
        |/      |
        |      (_)
        |      \|
        |       |
        |
       _|___
        )",

        R"(
         _______
        |/      |
        |      (_)
        |      \|/
        |       |
        |
       _|___
        )",

        R"(
         _______
        |/      |
        |      (_)
        |      \|/
        |       |
        |      /
       _|___
        )",

        R"(
         _______
        |/      |
        |      (_)
        |      \|/
        |       |
        |      / \
       _|___
        )"
    };
    vector<string> words = {"umbrella", "table", "morning", "door", "photo", "curtain", "chair", "school", "hospital"};
    int index = rand() % words.size();
    string word = words.at(index);
    string str(word.size(), '_');
    char character;
    int stage{0}, lives{0}, found{0};
    string heading = R"(
      _   _     _     _   _   ____  __  __     _     _   _
     | | | |   / \   | \ | | / ___||  \/  |   / \   | \ | |
     | |_| |  / _ \  |  \| || |  _ | |\/| |  / _ \  |  \| |
     |  _  | / ___ \ | |\  || |_| || |  | | / ___ \ | |\  |
     |_| |_|/_/   \_\|_| \_| \____||_|  |_|/_/   \_\|_| \_|

    )";
    cout << heading << endl;
    while (lives < 6) {
        cout << "***************************************\n";
        cout << "Enter your guess: " << str << endl;
        cin >> character;
        for (int i=0; i<word.size(); i++) {
            if (character == word[i]) {
                str[i] = character;
                word[i] = '_';
                found = 1;
            }
        }
        cout << "After Guess: " << str << endl;
        if (found == 1) {
            cout << "You guessed correct!\n";
            if (str == words.at(index)) {
                cout << "You guessed word correctly: " << str << endl;
                return 0;
            }
        }
        else{
            cout << "You didn't guess correctly!\n";
            lives += 1;
            if (lives == 6) {
                cout << "Hangman Hanged!!! You Lost!\n";
                cout << "HangMan Status: \n" << hangmanStages.at(lives) << endl;
                break;
            }
        }
        found = 0;
        cout << "HangMan Status: \n" << hangmanStages.at(lives) << endl;
        cout << "***************************************\n";
    }
    return 0;
}
