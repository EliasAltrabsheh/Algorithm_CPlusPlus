/*
This program is an introduction on how stacks Process works.

The stack is an abstract entity more so than arrays. It allows only one data to be inserted if you remove this item you can access a new item.

Most microprocessors (like the one in your computer) use a stack-based architecture. a Real life example is how to organize the post received at your home. i.e by receiving new post and putting it in a pile.

Its main functionally used the following:
1) pop: remove data item from top of stack
2) peek: revel data value
3) Push: insert new data
*/

#include <iostream>
#include <vector>

using namespace std;

class StackX
{
private:
  int maxSize;
  vector<double> stackVect;
  int top;

public:

  StackX(int s) : maxSize(s), top(-1) // Constructer
  {
    stackVect.reserve(maxSize); // size of vector ( we used reserve i.e to resrve memory allocations )
  }

 void push(double j) //put item on top
 {
   stackVect[++top] = j;  // increment top item
 }
 double pop() // take item from top
 {
   return stackVect[top--];
 }
  double peek()
  {
    return stackVect[top];
  }
  bool isEmpty()
  {
    return(top == -1);
  }
  bool isFull()
  {
    return (top == maxSize -1);
  }
}; // end class

int main()
{
  StackX theStack(10); // make new stack, size 10
  theStack.push(20);
  theStack.push(40);
  theStack.push(1000);
  theStack.push(323);

  while(!theStack.isEmpty())
  {
    double value = theStack.pop(); // value of stack poped
    cout << value <<  " " ; // display it
  }
  cout << endl;
  return 0;
}
