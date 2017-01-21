
/*
The aim of the program is to create a bank account that deposits/Withdraws cash.
A class is constructed with members included.
The Constructer is a special member function of that class whenever we create new objects.
*/

/* Q- Can I really learn object-oriented programming from the section in this chapter?
Our aim is to teach just enough about OOP that someone who hasn’t seen it before can follow the program examples. There’s a lot more that we don’t touch on, but what we’ve said should get you started.

Q-There are a lot of new terms in this hour, like record, field, and key, but what is the big picture?
A The big picture is someone trying to store a lot of data in computer memory and then to access it efficiently.
Don’t worry if everything isn’t clear at this point. In the next few hours you’ll get a better idea what sorts of things we’ll be talking about.

Quizz:
What is a data structure?
● is the organization of data in a computer’s memory (or in a disk file).

● Eamples data structures are arrays, stacks, and linked lists

● An object is a programming construct containing both functions and data.
● A class is a specification for many similar object
●  Generally, an object’s data is accessed by calling its member functions*/

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
