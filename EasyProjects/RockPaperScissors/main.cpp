// Rock Paper Scissors
#include <iostream>
#include <stdio.h>

using namespace std;

void menu(){
    printf("%s", "******Menu*****\n1 - Rock\n2 - Paper\n3 - Scissors\n");
}

int main(){
    string signs[3] = {"Rock", "Paper", "Scissors"};
    string winner;
    int p1Choice, p2Choice;
    menu();
    printf("%s", "Enter your choice: ");
    scanf("%d", &p1Choice);
    printf("%s", "Enter AI's choice: ");
    scanf("%d", &p2Choice);
    winner = (p1Choice == p2Choice) ? "It's a Draw\n" : (p1Choice > p2Choice && (p1Choice - 2 != p2Choice)) || (p1Choice < p2Choice) && (p2Choice - 2 == p1Choice) ? "Player 1 Wins!!!\n" : "Player 2 Wins\n";
    cout << winner;
    return 0;
}
