#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"

using namespace std;

class Bank{
    public:
        vector<Account> Accounts;
        vector<Saving> Savings;
    private:
        int* indexFinder(int num){
            static int nums[2];
            int index = 0;
            for (Account account : Accounts) {
                if (account.getAccountNum() == num) {
                    nums[0] = index;
                    nums[1] = 0;
                    return nums;
                }
                index += 1;
            }
            index = 0;
            for (Saving save : Savings) {
                if (save.getAccountNum() == num) {
                    nums[0] = index;
                    nums[1] = 1;
                    return nums;
                }
                index += 1;
            }
            nums[0] = -1;
            nums[1] = -1;
            return nums;
        }
    public:
        void Choice(int choice){
            int *num;
            int mode;
            string name = "";
            int ac_num;
            float amount;
            if (choice != 6 && choice != 4 && choice != 8) {
                cout << "Enter Account number: ";
                cin >> ac_num;
                if (choice != 4) {
                    num = indexFinder(ac_num);
                    if (num[0] == -1) {
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
                    (num[1] == 1) ? this->Savings.at(num[0]).deposit(amount) : this->Accounts.at(num[0]).deposit(amount);
                    break;
                case 2:
                    (num[1] == 1) ? this->Savings.at(num[0]).withdraw(amount) : this->Accounts.at(num[0]).withdraw(amount);
                    break;
                case 3:
                    (num[1] == 1) ? this->Savings.at(num[0]).AccountInfo() : this->Accounts.at(num[0]).AccountInfo();
                    break;
                case 4:
                    cout << "Enter your name: ";
                    cin >> name;
                    cout << "Enter type of account (0 - current) (1 - savings): ";
                    cin >> mode;
                    (mode == 1) ? Savings.push_back(Saving(name)) : Accounts.push_back(Account(name, mode));
                    break;
                case 5:
                    cout << "Account with number " << ((num[1] == 1) ? Savings.at(num[0]).getAccountNum() : Accounts.at(num[0]).getAccountNum()) << " Is closed!!!\n";
                    cout << "Your amount in balance will be sent to you of $: " << ((num[1] == 1) ? Savings.at(num[0]).getBalance() : Accounts.at(num[0]).getBalance());
                    (num[1] == 1) ? *Savings.erase(Savings.begin() + num[0]) : *Accounts.erase(Accounts.begin() + num[0]);
                    break;
                case 6:
                    AllAccounts();
                    break;
                case 7:
                    if(num[1] == 1) Savings.at(num[0]).getInterest();
                    break;
                case 8:
                    for (Saving& save : this->Savings) save.InterestChange();
                    break;
            }
        }
        void AllAccounts(){
            if (Accounts.size() == 0 && Savings.size() == 0) {
                cout << "No Accounts found!\n";
                return;
            }
            cout << "******************* ALL CURRENT ACCOUNTS *******************\n";
            for (Account account : Accounts) {
                cout << account.getName() << "  -  $ " << account.getBalance() << "\n";
            }
            cout << "******************* ALL SAVINGS ACCOUNTS *******************\n";
            for (Saving save : Savings) {
                cout << save.getName() << "  -  $ " << save.getBalance() << "\n";
            }
            cout << "****************************************************\n";
        }
};

