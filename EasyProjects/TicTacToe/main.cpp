#include <iostream>

using namespace std;

void displayer(char *board){
    for (int i=0; i<9; i++) {
        if ((i+1) % 3 == 0) {
            cout << "  " << board[i] << "   ";
            if (i!=8) {
                cout << "\n";
                cout << "-----*-----*------\n";
            }
            continue;
        }
        cout << "  " << board[i] << "  |";
    }
    cout << "\n";
}

int main(){
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int player1, player2;
    displayer(board);
    while (true) {
        cout << "[Player1] : Enter your move: ";
        cin >> player1;
        while (board[player1 - 1] == 'X' || board[player1 - 1] == 'O') {
            cout << "The spot is already occupied!!! Enter another spot: ";
            cin >> player1;
        }
        board[player1 - 1] = 'X';

        cout << "[Player2] : Enter your move: ";
        cin >> player2;
        while (board[player2 - 1] == 'X' || board[player2 - 1] == 'O') {
            cout << "The spot is already occupied!!! Enter another spot: ";
            cin >> player2;
        }
        board[player2 - 1] = 'O';


        cout << "***** STATUS *****\n";
        displayer(board);
        cout << "\n";
    }
    return 0;
}




/*
char board[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};
int drawIndex = 0;
for (int i = 0; i<3; i++) {
    cout << "  ";
    for (int j=0; j<3; j++) {
        cout << board[i][j];
        if(j != 2) cout << "  |  ";
    }
    cout << endl;
    if (i==2) {
        continue;
    }
    for (int i=0; i<3; i++) {
        cout << "-----*";
    }
    cout << endl;
}
 */
