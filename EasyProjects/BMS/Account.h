#include <iostream>
#include <vector>

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
            cout << "Account - " << name << " with Account number "<< this->Account_Number << "was created successfully\n";
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
        int getAccountNum(){
            return this->Account_Number;
        }
};








// #include <iostream>
// #include <vector>

// using namespace std;

// class Account{
//     private:
//         int is_saving;
//         int Account_Number;
//         string userName;
//         float balance;
//         vector<float> transaction_history = {};
//     public:
//         Account(string name, int mode) : userName(name) {
//             this->is_saving = mode;
//             srand(time(0));
//             Account_Number = rand() % 1000000;
//             cout << "Account - " << name << " with Account number "<< this->Account_Number << " was created successfully\n";
//             cout << "Happy Banking - Welcome!\n";
//         };
//         void deposit(float amount){
//             this->balance += amount;
//             transaction_history.push_back(amount);
//             cout << "$ " << amount << " was deposited successfully!\n";
//             cout << "Total Balance: $ " << this->balance << endl;
//         }
//         void withdraw(float amount){
//             if (amount > this->balance) {
//                 cout << "Not Enough amount in balance!\n";
//                 return;
//             }
//             this->balance -= amount;
//             transaction_history.push_back(amount * -1);
//             cout << "$ " << amount << " was withdrawn successfully!\n";
//             cout << "Remaining Balance: $ " << this->balance << endl;
//         }
//         void AccountInfo(){
//             cout << "***************** ACCOUNT *****************\n";
//             cout << "Username: " << this->userName << endl;
//             cout << "Balance: " << this->balance << endl;
//             cout << "Account Number: " << this->Account_Number << endl;
//             cout << "Account Type: " << (this->is_saving == 1 ? "Savings" : "Current") << endl;
//             cout << "*********** Transaction History ***********\n";
//             for (float transaction : this->transaction_history) {
//                 cout << "$ " << transaction << (transaction > 0 ? " Deposited" : " Withdrawn") << endl;
//             }
//             cout << "*******************************************";
//             cout << endl;
//         }
//         string getName(){
//             return this->userName;
//         }
//         float getBalance(){
//             return this->balance;
//         }
//         int getAccountNum(){
//             return this->Account_Number;
//         }
//         int getSaving(){
//             return this->is_saving;
//         }
// };


// class Saving : public Account{
//     public:
//         Saving(string name) : Account(name, 1){
//             cout << "Saving account was created\n";
//         }
// };
