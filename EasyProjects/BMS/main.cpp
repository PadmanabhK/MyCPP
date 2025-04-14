#include <iostream>
#include "Bank.h"

using namespace std;

void printMenu(){
    cout << "\n***** WELCOME *****\n";
    cout << "1 - Deposit\n2 - Withdraw\n3 - Account Information\n4 - Create Account\n5 - Close Account\n6 - All Accounts\n7 - Get Interest\n\n";
}

int main(){
    Bank *bank = new Bank();
    string userName = "";
    float amount;
    int choice = 0;
    while (true) {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        bank->Choice(choice);
    }
    return 0;
}
