
/* This is a sample program to demonstrate how to apply  Fibonacci sequence using C++.
 The Fibonacci sequence is stated as the following:

F_{N} = F_{N_1} + F_{N-2}

We will describe below two methods of implementation.

1) Recursive method
2) Iterative method
3) Iterative method with Vectors

*/

#include <iostream>
#include<vector>
// fibananci code sevral methods
using namespace std;

int Recursive(int x)  // Recursive function
{
    if (x == 0 || x == 1) return x;  // Condition order for first two values
  else
  {
      return Recursive(x-1)+Recursive(x-2);
  }

}

int Irretitive(int x)   //Iterative Function

{
    int prev= 0, last= 1, temp;
    if (x == 0 || x == 1) return x;
    for(int i=2; i<=x;++i)
    {
      temp = last;
      last = last + prev;
      prev = temp;
    }
return last;
}

int better(int x)
{
  vector<int> v(x+1); // define vector
  v[0] = 1;   // initialization of first two terms
  v[1] = 1;
  for(int i = 2; i<= x;++i)
  {
    v[i] = v[i-1] + v[i-2];
  }
  return v[x-1];
}

int main()
{
  int n ;
  cout << "Enter the number of terms of Fibonacci series you want" << endl;
  cin >> n;

  cout <<"Recursive method " << Recursive(n) << endl;
  cout <<"Irretitive method " << Irretitive(n) << endl;
  cout << "Better method with vectors " << better(n) <<endl;


}
