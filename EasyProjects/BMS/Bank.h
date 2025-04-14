#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account{
    private:
        int Account_Number;
        string userName;
        float balance;
        vector<float> transaction_history = {};
    public:
        Account(string name) : userName(name) {
            srand(time(0));
            Account_Number = rand() % 1000000;
            cout << "Account - " << name << " was created successfully\n";
            cout << "Happy Banking - Welcome!\n";
        };
        void deposit(float amount){
            this->balance += amount;
            transaction_history.push_back(amount);
            cout << "$ " << amount << " was deposited successfully!\n";
            cout << "Total Balance: $ " << this->balance << endl;
        }
        void withdraw(float amount){
            if (amount > this->balance) {
                cout << "Not Enough amount in balance!\n";
                return;
            }
            this->balance -= amount;
            transaction_history.push_back(amount * -1);
            cout << "$ " << amount << " was withdrawn successfully!\n";
            cout << "Remaining Balance: $ " << this->balance << endl;
        }
        void AccountInfo(){
            cout << "***************** ACCOUNT *****************\n";
            cout << "Username: " << this->userName << endl;
            cout << "Balance: " << this->balance << endl;
            cout << "Account Number: " << this->Account_Number << endl;
            cout << "*********** Transaction History ***********\n";
            for (float transaction : this->transaction_history) {
                cout << "$ " << transaction << (transaction > 0 ? " Deposited" : " Withdrawn") << endl;
            }
            cout << "*******************************************";
            cout << endl;
        }
        string getName(){
            return this->userName;
        }
        float getBalance(){
            return this->balance;
        }
};

class Bank{
    private:
        vector<Account> Accounts;
        int indexFinder(string name){
            int index = 0;
            for (Account account : Accounts) {
                if (account.getName() == name) {
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
            float amount;
            if (choice != 6) {
                cout << "Enter your name: ";
                cin >> name;
                if (choice != 4) {
                    num = indexFinder(name);
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
                    Deposit(name, amount, num);
                    break;
                case 2:
                    withdraw(name, amount, num);
                    break;
                case 3:
                    AccountInfo(name, num);
                    break;
                case 4:
                    createAccount(name);
                    break;
                case 5:
                    closeAccount(name, num);
                    break;
                case 6:
                    AllAccounts();
                    break;
            }
        }
        void Deposit(string name, float amount, int num){
            this->Accounts.at(num).deposit(amount);
        }
        void withdraw(string name, float amount, int num){
            this->Accounts.at(num).withdraw(amount);
        }
        void AccountInfo(string name, int num){
            this->Accounts.at(num).AccountInfo();
        }
        void createAccount(string name){
            Account *account = new Account(name);
            Accounts.push_back(*account);
        }
        void closeAccount(string name, int num){
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
