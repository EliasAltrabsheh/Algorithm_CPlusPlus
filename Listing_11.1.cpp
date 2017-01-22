/* First example of recurtion shown with triangle example*/
/*
Although it’s short, the triangle() function possesses the key features common to all recursive routines:
● It calls itself.
● When it calls itself, it does so to solve a smaller problem.
● There’s some version of the problem that is simple enough that the routine can solve it, and return, without calling itself.

Calling a function involves certain overhead.
Control must be transferred from the location of the call to the beginning of the function.
In addition, the arguments to the function, and the address to which the function should return, must be pushed onto an internal stack so that the function can access the argument values and know where to return.

*/

// triangle.cpp // evaluates triangular numbers
#include <iostream>
using namespace std; //------------------------------------------------------------
int main()
{
  int theNumber;
  int triangle(int);
cout << "Enter a number: ";
cin >> theNumber;
int theAnswer = triangle(theNumber);
cout << "Triangle= " << theAnswer << endl;
return 0;
}  // end main() //------------------------------------------------------------




int triangle(int n)
 {
  cout << "Entering: n=" << n << endl;
   if(n==1)
   {
     cout << "Returning 1" << endl;
     return 1;
    }
else
{
  int temp = n + triangle(n-1);
   cout << "Returning " << temp << endl;
   return temp;
 }
}
