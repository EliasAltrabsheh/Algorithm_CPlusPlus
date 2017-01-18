/* This program reviews how to use priority queues.
normally used in a multitasking operating system so that certain operations have priority
in which needs to implemented first*/


#include <iostream>
#include <vector>
using namespace std;

class PriorityQ
{
private:
  int maxSize;
  vector <double> queVect; // initilazion code
  int nItems;

public:

  PriorityQ(int s) : maxSize(s), nItems(0)
    {  queVect.resize(maxSize); }
  void insert(double item)

  {
    int j;

    if( nItems == 0) // check condotion if no items are inserted

      queVect[nItems] = item;
 else   // if items are inserted then

 {

  for(j = nItems -1; j >= 0;j++)  // go looping items
  {
    if(item > queVect[j] )   // if new item is larger
      queVect[j+1] = queVect[j];   // shift one postion upwards in stack
    else
      break;
  }   // endfor

queVect[j+1] = item ;   // insert it in
nItems++;
 }//end else
}//end inserted

double remove()                 // remove minmal item
{return queVect[--nItems];}

double peekMin()              // peek i.e view item
{return queVect[nItems-1];}

bool isEmpty()              // check if vector (stack ) empty
{
  return (nItems==0);
}
bool isFull()
{return (nItems == maxSize);}       // check if queue is full

};//end of class

int main()
{
  PriorityQ thePQ(5); // Prioroty, size 5
  thePQ.insert(30);   // insert 5 values
  thePQ.insert(50);
  thePQ.insert(10);
  thePQ.insert(40);
  thePQ.insert(20);

  while( !thePQ.isEmpty())   // wait when array is full
  {
    double item = thePQ.remove();      // sorted romeoved
    cout << item << " ";
  } //endwhile
cout << endl;
return 0;
}
