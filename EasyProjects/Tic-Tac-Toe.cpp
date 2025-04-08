// Tic-Tac-Toe
// Draw Logic still isn't implemented
// Only Player vs. AI mode Available
// Yet to implement Player vs. Player mode

#include <cstdlib>
#include <iostream>

using namespace std;

int checkerNums(char numArray[][3], int i1, int i2, int i3, int j1, int j2, int j3, char symbol1, char symbol2){
    char syms[2] = {symbol1, symbol2};
    for (char sym : syms) {
        if (numArray[i1][j1] == sym) {
            if (numArray[i2][j2] == sym) {
                if (numArray[i3][j3] == sym) {
                    return (sym == 'O') ? 1 : (sym == 'X') ? -1 : 0;
                }
            }
        }
    }
    return 0;
}

int checkPattern(char numArray[][3]){
    int correct = 0;
    int value[4] = {0, 0, 0, 0};
    for (int i=0; i < 3; i++) {
        value[0] = checkerNums(numArray, i, i+1, i+2, i+2, i+1, i, 'O', 'X');
        value[1] = checkerNums(numArray, i, i+1, i+2, i, i+1, i+2, 'O', 'X');
        value[2] = checkerNums(numArray, 0, 1, 2, i, i, i, 'O', 'X');
        value[3] = checkerNums(numArray, i, i, i, 0, 1, 2, 'O', 'X');
        if (value[0] == 1 || value [1] == 1 || value[2] == 1 || value[3] == 1) {
            return 1;
        }
        else if(value[0] == -1 || value [1] == -1 || value[2] == -1 || value[3] == -1){
            return -1;
        }
    }
    return correct;
}

int getAI(){
    return rand() % (106 - 97) + 97;
}

int checker(char numArray[], char guess){
    for(int i = 0; i< 9; i++){
        if (numArray[i] == guess) {
            return 1;
        }
    }
    return 0;
}

int draw(char numArray[]){
    int drawed = 0;
    for(int i = 0; i< 9; i++){
        if (numArray[i] == 'X' || numArray[i] == 'O') {
            drawed = 1;
        }
    }
    return drawed;
}

int getIndex(char arr[], char n){
    for (int i = 0 ; i<9; i++) {
        if (arr[i] == n) {
            return i;
        }
    }
    return -1;
}

int main(){
    srand(time(0));
    char nums[3][3] = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}};
    char valid[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    char choice = 'z';
    char AIchoice = 'y';
    while (true) {
        int result = 0;
        int i = 0;
        cout << "Enter your choice from a to i: ";
        cin >> choice;
        for (char character : valid) {
            if (character == choice) {
                valid[i] = 'O';
            }
            i += 1;
        }
        i = 0;
        while (checker(valid, AIchoice) == 0) {
            AIchoice = getAI();
        }
        for (char character : valid) {
            if (character == AIchoice) {
                valid[i] = 'X';
            }
            i += 1;
        }
        for (char character : valid) {
            cout << character << " " ;
        }
        cout << endl;
        for (int i =0; i < 3 ; i++) {
            for (int j = 0; j < 3; j++){
                if(nums[i][j] == choice){
                    nums[i][j] = 'O';
                }
                if (nums[i][j] == AIchoice) {
                    nums[i][j] = 'X';
                }
                cout << nums[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;


        result = checkPattern(nums);
        if(result == 0){
            continue;
        }
        string message = (result == 1) ? "You Won!!!" : "AI Won!!!";
        cout << message;

        if(draw(valid) == 1 && result == 0){
            cout << "Draw!!!\n";
            break;
        }
        break;
    }
    return 0;
}
