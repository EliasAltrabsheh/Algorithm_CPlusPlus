
/*
The aim of the program is to create a bank account that deposits/Withdraws cash.
A class is constructed with members included.
The Constructer is a special member function of that class whenever we create new objects.
*/
#include <iostream>
using namespace std;


class BankAccount
{
private:
  int balance; //account balance initilazion
public:

  BankAccount(int OpenBalance) // first member
  {
    balance = OpenBalance; // set balance to
  }

  void deposit(int amount)
  {
    balance = balance + amount;
  }

  void withdraw(int amount)
  {
    balance = balance - amount;
  }

  void display()
  {
    cout << " Balance is = " << balance << endl;
  }
};

int main ()
{
  BankAccount ba1(13700); // create account

  cout << "Before transaction the account balance is : \n " ;
  ba1.display();
  ba1.deposit(1300);// Calls member of class to deposit
  ba1.withdraw(5000);// Calls member of class to withdraw

  cout << "new account balance is \n " ;
  ba1.display();

  return 0;
}
