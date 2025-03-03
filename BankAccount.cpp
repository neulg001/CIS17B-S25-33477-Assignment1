#include <iostream>
#include <stdexcept>
#include <limits>
#include "BankAccount.h"


using namespace std;

BankAccount::BankAccount() // set up bank account name and starting balance
{
    bool good_data1 = false, good_data2, good_string= true;
    string stringTempRebuild;

    do {
        cout<<"Please Enter Account Name: ";
        try 
        {
            // prompt user for value.
            getline(cin,account_holder_name);
            good_data1 = cin.good();
            
            for (char character : account_holder_name) 
            {
                if (isalpha(character) ) //|| character == " "
                {
                    good_string = true;
                    character = tolower(character);
                }
                else if ( character == ' ')
                {
                    good_string = true;
                    //character = tolower(character);
                }
                else 
                {
                    good_string = false;
                    stringTempRebuild = "";
                    break; // No need to check further if one non-alpha character is found
                }
                stringTempRebuild= stringTempRebuild+character;// makes lowercase string
            }
            
            good_data1 = good_data1*good_string;

            if ( !cin.good() )
            {
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n'); // make sure to have #include <limits>
                cout<<"Good Error"<<endl;
            }

            if ( !good_data1)
                throw invalid_argument("Invalid input: Please enter valid name. Please try again: ");

        }
        catch(const invalid_argument& e)
        {
            cout<<"Caught exception: " << e.what() << endl;
        }
    }while(!good_data1);
    
    do {
        cout<<"Please Enter Starting Balance: ";
        try 
        {
            cin >> balance;

            // prompt user for value.
            good_data2 = cin.good();

            good_data2 = good_data2 && (balance > 0);

            if ( !cin.good() )
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); // make sure to have #include <limits>
            }
            if ( !good_data2)
                throw invalid_argument("Invalid input: Please enter a number greater than 0. Please try again: ");

        }
        catch(const invalid_argument& e)
        {
            cout<<"Caught exception: " << e.what() << endl;
        }
    }while(!good_data2);

    account_holder_number = 1; // set up a better account_holder_number but this will work for now
    
}


void BankAccount::deposit(double amount)    // deposit into account
{
        balance = balance + amount;
}    

void BankAccount::withdraw(double amount)   // withdraw from account
{
        balance = balance - amount;
}

double BankAccount::getbalance()               // get the current balance
{
        return balance;
}

