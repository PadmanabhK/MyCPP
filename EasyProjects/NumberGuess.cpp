#include <cstdlib>
#include <iostream>

using namespace std;

void inputter(string prompt, int* num){
    cout << prompt;
    cin >> *num;
}

int main(){
    srand(time(0));
    int num = rand() % 100;
    int choice, guess;
    inputter("1 - Easy Mode (10 Lives)\n2 - Hard More (5 Lives)\n", &choice);
    choice = (choice == 1 ? 10 : 5);
    while (choice > 0) {
        inputter("Enter your guess: ", &guess);
        if (guess == num) {cout << "You're CORRECT!!!\nThe Answer is: " << guess << endl; return 0;}
        else if(guess > num) cout << "Guess Lower" << endl;
        else cout << "Guess Higher" << endl;
        choice-=1;
    }
    cout << "You didn't guess correctly! The numeber was: " << num << endl;
    return 0;
}
