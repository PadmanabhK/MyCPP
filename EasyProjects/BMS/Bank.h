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













// #include <cstdlib>
// #include <ctime>
// #include <iostream>
// #include <vector>
// #include <string>
// #include "Account.h"

// using namespace std;

// class Bank{
//     private:
//         vector<Account> Accounts;
//         vector<Saving> Savings;
//         int* indexFinder(int num){
//             static int nums[2];
//             int index = 0;
//             for (Account account : Accounts) {
//                 if (account.getAccountNum() == num) {
//                     nums[0] = index;
//                     nums[1] = 0;
//                     return nums;
//                 }
//                 index += 1;
//             }
//             index = 0;
//             for (Saving save : Savings) {
//                 if (save.getAccountNum() == num) {
//                     nums[0] = index;
//                     nums[1] = 1;
//                     return nums;
//                 }
//                 index += 1;
//             }
//             nums[0] = -1;
//             nums[1] = -1;
//             return nums;
//         }
//     public:
//         void Choice(int choice){
//             int *num;
//             int mode;
//             string name = "";
//             int ac_num;
//             float amount;
//             if (choice != 6 && choice != 4) {
//                 cout << "Enter Account number: ";
//                 cin >> ac_num;
//                 if (choice != 4) {
//                     num = indexFinder(ac_num);
//                     if (num[0] == -1) {
//                         cout << "Account was not found! Create one today!!!\n";
//                         return;
//                     }
//                 }
//             }
//             if (choice == 1 || choice == 2) {
//                 cout << "Enter your amount: ";
//                 cin >> amount;
//             }
//             switch (choice) {
//                 case 1:
//                     Deposit(amount, num);
//                     break;
//                 case 2:
//                     withdraw(amount, num);
//                     break;
//                 case 3:
//                     AccountInfo(num);
//                     break;
//                 case 4:
//                     cout << "Enter your name: ";
//                     cin >> name;
//                     cout << "Enter type of account (0 - current) (1 - savings): ";
//                     cin >> mode;
//                     createAccount(name, mode);
//                     break;
//                 case 5:
//                     closeAccount(num);
//                     break;
//                 case 6:
//                     AllAccounts();
//                     break;
//             }
//         }
//         void Deposit(float amount, int* num){
//             (num[1] == 1) ? this->Savings.at(num[0]).deposit(amount) : this->Accounts.at(num[0]).deposit(amount);
//         }
//         void withdraw(float amount, int *num){
//             (num[1] == 1) ? this->Savings.at(num[0]).withdraw(amount) : this->Accounts.at(num[0]).withdraw(amount);
//         }
//         void AccountInfo(int *num){
//             (num[1] == 1) ? this->Savings.at(num[0]).AccountInfo() : this->Accounts.at(num[0]).AccountInfo();
//         }
//         void createAccount(string name, int mode){
//             if (mode == 1) {
//                 Saving *sav = new Saving(name);
//                 Savings.push_back(*sav);
//             }
//             else{
//                 Account *account = new Account(name, mode);
//                 Accounts.push_back(*account);
//             }
//         }
//         void closeAccount(int *num){
//             if (num[1] == 1) {
//                 this->Savings.erase(Savings.begin() + num[0]);
//                 return;
//             }
//             this->Accounts.erase(Accounts.begin() + num[0]);
//         }
//         void AllAccounts(){
//             if (Accounts.size() == 0 && Savings.size() == 0) {
//                 cout << "No Accounts found!\n";
//                 return;
//             }
//             cout << "******************* ALL CURRENT ACCOUNTS *******************\n";
//             for (Account account : Accounts) {
//                 cout << account.getName() << "  -  $ " << account.getBalance() << "\n";
//             }
//             cout << "******************* ALL CURRENT ACCOUNTS *******************\n";
//             for (Saving save : Savings) {
//                 cout << save.getName() << "  -  $ " << save.getBalance() << "\n";
//             }
//             cout << "****************************************************\n";
//         }
// };

