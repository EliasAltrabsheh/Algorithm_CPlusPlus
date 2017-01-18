/*/* This program describes the double sort. This type of sort is the simplest in its way of operation. It works by starting at beginning of array and comparing two values. If values are not in order it swaps them. As it goes through all values its quite inefficient.

Its efficiency is described by:

N(N-1)/2 which is the sum of series such that the algorithms make N^2/2 comparisons in worst case scenario.

The number of swaps is performed is N^2/4as you make one swap per two values.
*/
#include<iostream>
#include <vector>

using namespace std;

class ArrayBubble // Defining class that will have sevral member to it
{
private:
  vector<double> v;
  int nElems;

  void swap(int one,int two)//swapping member of class that countains swapping operation
  {
    double temp = v[one];
    v[one] = v[two];
    v[two] = temp;
  }

public:

  ArrayBubble(int max)// constreucter of class
  {
    v.resize(max);// size vector accordanly

  }
  void insert(double value)
  {
    v[nElems]= value; // Functiion that insert value intop its refrenced location
    nElems++;
  }
  void display()
  {
    for(int j=0; j<nElems;j++)
    {
      cout << v[j] << " ";
    }
  cout << endl;

  }
void bubbleSort()  // Sorting algortm i.e N(N-1)/2 effeciency 
{
  int in,out;
  for(out=nElems-1;out>1;out--)
  {
    for(in =0;in<out; in++)
    {
      if (v[in]>v[in+1])
        swap(in,in+1);
    }
  }
 }
};


int main()
 {
  int maxSize = 100;             //array size
  ArrayBubble arr(maxSize);         //create the array
  arr.insert(77);                //insert 10 items
  arr.insert(99);
  arr.insert(44);
  arr.insert(55);
  arr.insert(22);
  arr.insert(88);
  arr.insert(11);
  arr.insert(00);
  arr.insert(66);
  arr.insert(33);


  arr.display();                 //display items
  arr.bubbleSort();              //bubble sort them
  arr.display();                 //display them again
  return 0;
}  //end main()
