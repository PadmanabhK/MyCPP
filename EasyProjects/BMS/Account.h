#include <iostream>
#include <vector>

using namespace std;

class Account{
    private:
        float interest_rate;
        float interest_value;
        int is_saving;
        int Account_Number;
        string userName;
        float balance = 0;
        vector<float> transaction_history = {};

        void changeBalance(float amount, string type){
            this->balance += (type == "+") ? amount : (amount * -1);
            this->transaction_history.push_back((type == "+") ? amount : (-1 * amount));
            cout << "$ " << amount << " was "<< ((type == "+") ? "Deposited" : "Withdrawn") <<" successfully!\n";
            cout << "Total Balance: $ " << this->balance << endl;
        }

    public:
        Account(string name, int mode) : userName(name) {
            this->is_saving = mode;
            this->interest_rate = (mode == 1) ? 4.0 : 0;
            this->interest_value = 0;
            srand(time(0));
            Account_Number = rand() % 1000000;
            cout << ((mode == 0) ? "Current" : "Savings") << " Account - " << name << " with Account number "<< this->Account_Number << " was created successfully\n";
            cout << "Happy Banking - Welcome!\n";
        };
        void deposit(float amount){
            changeBalance(amount, "+");
        }
        void withdraw(float amount){
            if (amount > this->balance) {
                cout << "Not Enough amount in balance!\n";
                return;
            }
            changeBalance(amount, "-");
        }
        void InterestChange(){
            if (this->balance > 0) {
                this->interest_value = (this->interest_rate / 100) * this->balance;
            }
            cout << "New Interest is: " << this->interest_value << endl;
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
            cout << "*******************************************\n";
        }
        void getInterest(){
            cout << "Interest value of $ " << this->interest_value << " is received\n";
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
};


class Saving : public Account{
    public:
        Saving(string name) : Account(name, 1){}
};
