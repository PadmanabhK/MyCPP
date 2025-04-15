// This is a simple Bank management system

// FEATURES:
// Creating both Current and Savings Account
// However, whenever you create an account a unique account number is generated - which you've to keep noted
// You can perform operations like deposit, withdrawl, closure of account, check for interest (if you've savings account), detailed information about a particular account
// This operations are enabled by account number
// However might be hidden bugs in the program which I might not be aware off
// This is one of the project - So, I'm leaving it to current version as I'll move for my next project
// But, I'll expand functionalities like encryption by introducing a pin number for each account


#include <iostream>
#include "Bank.h"

using namespace std;

void printMenu(){
    cout << "\n***** WELCOME *****\n";
    cout << "1 - Deposit\n2 - Withdraw\n3 - Account Information\n4 - Create Account\n5 - Close Account\n6 - All Accounts\n7 - Get Interest\n8 - Year Pass\n\n";
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
        if (choice < 0 || choice > 8) break;
        bank->Choice(choice);
    }
    return 0;
}
