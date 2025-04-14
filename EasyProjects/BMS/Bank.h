#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"

using namespace std;

class Bank{
    private:
        vector<Account> Accounts;
        int indexFinder(int num){
            int index = 0;
            for (Account account : Accounts) {
                if (account.getAccountNum() == num) {
                    return index;
                }
                index += 1;
            }
            return -1;
        }
    public:
        void Choice(int choice){
            int num;
            string name = "";
            int ac_num;
            float amount;
            if (choice != 6 && choice != 4) {
                cout << "Enter Account number: ";
                cin >> name;
                if (choice != 4) {
                    num = indexFinder(ac_num);
                    if (num == -1) {
                        cout << "Account was not found! Create one today!!!\n";
                        return;
                    }
                }
            }
            if (choice == 1 || choice == 2) {
                cout << "Enter your amount: ";
                cin >> amount;
            }
            switch (choice) {
                case 1:
                    Deposit(amount, num);
                    break;
                case 2:
                    withdraw(amount, num);
                    break;
                case 3:
                    AccountInfo(num);
                    break;
                case 4:
                    cout << "Enter your name: ";
                    cin >> name;
                    createAccount(name);
                    break;
                case 5:
                    closeAccount(num);
                    break;
                case 6:
                    AllAccounts();
                    break;
            }
        }
        void Deposit(float amount, int num){
            this->Accounts.at(num).deposit(amount);
        }
        void withdraw(float amount, int num){
            this->Accounts.at(num).withdraw(amount);
        }
        void AccountInfo(int num){
            this->Accounts.at(num).AccountInfo();
        }
        void createAccount(string name){
            Account *account = new Account(name);
            Accounts.push_back(*account);
        }
        void closeAccount(int num){
            this->Accounts.erase(Accounts.begin() + num);
        }
        void AllAccounts(){
            if (Accounts.size() == 0) {
                cout << "No Accounts found!\n";
                return;
            }
            cout << "******************* ALL ACCOUNTS *******************\n";
            for (Account account : Accounts) {
                cout << account.getName() << "  -  $ " << account.getBalance() << "\n";
            }
            cout << "****************************************************\n";
        }
};
