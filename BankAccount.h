#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
using namespace std;

class BankAccount
{
    private:
        string account_holder_name;
        int account_holder_number;
        double balance;

    public :
        BankAccount();                  // set up bank account name and starting balance
        void deposit(double amount);    // deposite into account
        void withdraw(double amount);    // withdraw from account
        double getbalance();   

};
#endif // BANKACCOUNT_H