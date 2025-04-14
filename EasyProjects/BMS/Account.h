#include <iostream>
#include <vector>

using namespace std;

class Account{
    private:
        float interest_value;
        float interest_rate;
        int is_saving;
        int Account_Number;
        string userName;
        float balance;
        vector<float> transaction_history = {};
    public:
        Account(string name, int mode) : userName(name) {
            this->is_saving = mode;
            if (mode == 1) {
                this->interest_rate = 4.0;
                this->interest_value = 0;
            }
            else{
                this->interest_value = 0;
                this->interest_rate = 0;
            }
            srand(time(0));
            Account_Number = rand() % 1000000;
            cout << "Account - " << name << " with Account number "<< this->Account_Number << " was created successfully\n";
            cout << "Happy Banking - Welcome!\n";
        };
        void deposit(float amount){
            this->balance += amount;
            transaction_history.push_back(amount);
            this->InterestChange();
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
            this->InterestChange();
            cout << "$ " << amount << " was withdrawn successfully!\n";
            cout << "Remaining Balance: $ " << this->balance << endl;
        }
        void AccountInfo(){
            cout << "***************** ACCOUNT *****************\n";
            cout << "Username: " << this->userName << endl;
            cout << "Balance: $ " << this->balance << endl;
            cout << "Account Number: " << this->Account_Number << endl;
            cout << "Account Type: " << (this->is_saving == 1 ? "Savings" : "Current") << endl;
            if (this->is_saving == 1) {
                cout << "Interest value: $ " << this->interest_value << endl;
                cout << "Interest rate: " << this->interest_rate << "%" << endl;
            }
            cout << "*********** Transaction History ***********\n";
            for (float transaction : this->transaction_history) {
                cout << "$ " << transaction << (transaction > 0 ? " Deposited" : " Withdrawn") << endl;
            }
            cout << "*******************************************";
            cout << endl;
        }
        void InterestChange(){
            this->interest_value += (this->interest_rate / 100) * this->balance;
            cout << "Interst values is: " << this->interest_value << endl;
        }
        void getInterest(){
            cout << "Interest value of " << this->interest_value << " is received\n";
            this->interest_value = 0;
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
        int getSaving(){
            return this->is_saving;
        }
};


class Saving : public Account{
    public:
        Saving(string name) : Account(name, 1){
            cout << "Saving account was created\n";
        }
};






// #include <iostream>
// #include <vector>

// using namespace std;

// class Account{
//     private:
//         int Account_Number;
//         string userName;
//         float balance;
//         vector<float> transaction_history = {};
//     public:
//         Account(string name) : userName(name) {
//             srand(time(0));
//             Account_Number = rand() % 1000000;
//             cout << "Account - " << name << " with Account number "<< this->Account_Number << "was created successfully\n";
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
// };








// // #include <iostream>
// // #include <vector>

// // using namespace std;

// // class Account{
// //     private:
// //         int is_saving;
// //         int Account_Number;
// //         string userName;
// //         float balance;
// //         vector<float> transaction_history = {};
// //     public:
// //         Account(string name, int mode) : userName(name) {
// //             this->is_saving = mode;
// //             srand(time(0));
// //             Account_Number = rand() % 1000000;
// //             cout << "Account - " << name << " with Account number "<< this->Account_Number << " was created successfully\n";
// //             cout << "Happy Banking - Welcome!\n";
// //         };
// //         void deposit(float amount){
// //             this->balance += amount;
// //             transaction_history.push_back(amount);
// //             cout << "$ " << amount << " was deposited successfully!\n";
// //             cout << "Total Balance: $ " << this->balance << endl;
// //         }
// //         void withdraw(float amount){
// //             if (amount > this->balance) {
// //                 cout << "Not Enough amount in balance!\n";
// //                 return;
// //             }
// //             this->balance -= amount;
// //             transaction_history.push_back(amount * -1);
// //             cout << "$ " << amount << " was withdrawn successfully!\n";
// //             cout << "Remaining Balance: $ " << this->balance << endl;
// //         }
// //         void AccountInfo(){
// //             cout << "***************** ACCOUNT *****************\n";
// //             cout << "Username: " << this->userName << endl;
// //             cout << "Balance: " << this->balance << endl;
// //             cout << "Account Number: " << this->Account_Number << endl;
// //             cout << "Account Type: " << (this->is_saving == 1 ? "Savings" : "Current") << endl;
// //             cout << "*********** Transaction History ***********\n";
// //             for (float transaction : this->transaction_history) {
// //                 cout << "$ " << transaction << (transaction > 0 ? " Deposited" : " Withdrawn") << endl;
// //             }
// //             cout << "*******************************************";
// //             cout << endl;
// //         }
// //         string getName(){
// //             return this->userName;
// //         }
// //         float getBalance(){
// //             return this->balance;
// //         }
// //         int getAccountNum(){
// //             return this->Account_Number;
// //         }
// //         int getSaving(){
// //             return this->is_saving;
// //         }
// // };


// // class Saving : public Account{
// //     public:
// //         Saving(string name) : Account(name, 1){
// //             cout << "Saving account was created\n";
// //         }
// // };
