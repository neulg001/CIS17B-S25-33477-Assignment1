
#include <iostream>
#include <limits>
#include "BankAccount.h"

using namespace std;

int menu_1 (BankAccount& user1);

void deposit( BankAccount& user1);
void withdraw(BankAccount& user1);
void displaybalance(BankAccount& user1);

float inputCheck(float min);
int inputCheck(int min, int max);




int main()
{
    int menu_return=0 ;

    cout<<"Please follow accout set up process."<<endl;
    BankAccount user1;
    cout<<"Account created successfully!"<<endl<<endl;

    do
    {
        menu_return = menu_1(user1);

    } while (menu_return !=4 );

    return 0;
}


int menu_1 (BankAccount& user1)
{
    int menu_input = 0;
    cout <<"Welcom to RCC Bank. Please select an option below."<<endl;

        cout <<"1 Deposite Money"<<endl;
        cout <<"2 Withdraw Money"<<endl;
        cout <<"3 Check Balance"<<endl;
        cout <<"4 Exit"<<endl;
        cout<<"Customer Input : ";
        menu_input = inputCheck (1,4);

    switch (menu_input)
    {
        case 1: 
        {
            deposit(user1);
            break;
        }
        case 2: 
        {
            withdraw (user1);
            break;
        }
        case 3: 
        {
            displaybalance(user1);
            break;
        }
        case 4: 
        {
            cout<<"Loggin out. Thank you for using RCC Bank!"<<endl<<endl;;
            break;
        }
        default:
            cout<<"Invalide Input. Please enter a numbe between 1 and 5.";

    }
    
    return menu_input;
}

void deposit( BankAccount& user1)
{
    float numTemp;
    cout<< "Enter deposit amount:";
    numTemp = inputCheck (0);
    user1.deposit(numTemp);
    cout<<"Deposite of $"<<numTemp<<" was sucessful. New balance is: $"<<user1.getbalance()<<endl<<endl;
}

void withdraw(BankAccount& user1)
{
float numTemp=-1;

do 
{
    cout<< "Enter withdraw amount:";
    numTemp = inputCheck (0);

    if (user1.getbalance() >= numTemp)
        user1.withdraw(numTemp);
    else 
    {
        cout<<"Error: Withdraw amount exceed current account balance of $"<<user1.getbalance()<<" please try again: "<<endl;
        numTemp = -1;
    }

} while ( numTemp == -1);

cout<<"Withdraw of $"<<numTemp<<" was sucessful. New balance is: $"<<user1.getbalance()<<endl<<endl;
}

void displaybalance(BankAccount& user1)
{
    cout <<"The Balance is: $" << user1.getbalance() << endl << endl;
}

int inputCheck(int min, int max)
{
    bool good_data = false;
    int check;
        
    do
    {
         // prompt user for value.
         cin >> check;
         good_data = cin.good();

         good_data = good_data && (check >= min) && (check <= max);

         if ( !cin.good() )
         {
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(),'\n'); // make sure to have #include <limits>
         }

         if ( !good_data)
         {
             cout<< "Invalid Integer: Please enter a number between ";
             cout <<min <<"-"<< max<<". Please try again: ";
         }

    } while ( !good_data );
    
    return check; 
}

float inputCheck(float min)
{
    bool good_data = false;
    float check;
        
    do
    {
         // prompt user for value.
         cin >> check;
         good_data = cin.good();

         good_data = good_data && (check > min);

         if ( !cin.good() )
         {
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(),'\n'); // make sure to have #include <limits>
         }

         if ( !good_data)
         {
             cout<< "Invalid Input: Please enter a numner greater than ";
             cout << min <<". Please try again: ";
         }

    } while ( !good_data );
    
    return check; 
}
