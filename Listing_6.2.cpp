/* This program looks at a stack methodology of storing and accessing data. We use the stack template to give us a reverse order for words with strings.
 Yes, this can be done in the main with no construction of class member but it more effective and less prone to errors using the stack functionality.
*/
#include <iostream>
#include <vector>
#include <string>


using namespace std;

class StackX
{
private:
  int maxSize;
  vector<double> stackVect;
  int top;

public:

  StackX(int max) : maxSize(max), top(-1) // Constructer
  {
    stackVect.reserve(maxSize);   // size of vector ( we used reserve i.e to resrve memory allocations )  }
  }

 void push(char j) //put item on top
 { stackVect[++top] = j;}  // increment top item}

 double pop() // take item from top
 { return stackVect[top--]; }

  double peek()
  {  return stackVect[top]; }

  bool isEmpty()
  {return(top == -1); }

}; // end class

class Reverser
{
private:
  string input;
  string output;

public:

Reverser(string in): input(in) // constructer
{}

string doRev()
{
  int stackSize = input.length(); // get max size
  StackX theStack(stackSize); // make stack

  for(int j = 0; j < input.length(); j++)
  {
    char ch = input[j];  //get a cahr from the input
    theStack.push(ch);  // push it
  }
output = " ";
while( !theStack.isEmpty() )
{
  char ch = theStack.pop();
  output = output +ch;
}
return output;
 }
};

int main()
{
  string  input, output;

  while(true)
  {
    cout<< "Enter a word: " <<endl;
    cin >> input ;  //read a word from input
    if( input.length() < 2)  // if less than two character dont read
      break;
                                   // make Reverser
    Reverser theReserver(input);
    output =  theReserver.doRev();  // use output
    cout << "Reversed : " << output << endl;
  } // end while
return 0;
}
