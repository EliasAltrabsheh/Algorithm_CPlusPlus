/* Quicksort operates much faster than the simple sorts; it runs in O(N*logN) time, which is the fastest time for general-purpose sorts.
Also, it does not require a large amount of extra memory space, as mergesort does.

This program will focus on partion of data that is defined as:
To partition data is to divide it into two groups, so that all the items with a key value higher than a specified amount are in one group,and all the items with a lower key value are in another.

The partitioning algorithm works by starting with two markers, one at each end of the array. (The markers are implemented as array index numbers.
We could call them pointers, but we don’t want them to be confused with C++ pointers.) 
The marker on the left, leftMark,moves toward the right,and the one of the right, rightMark, moves toward the left.*/

#include <iostream>
#include <vector>
#include <cstdlib>                //for random numbers
#include <ctime>                  //for random numbers
using namespace std;

class ArrayPar
{
private:
  vector<double> theVect;
  int nElems;                 //number of data items

public:
  ArrayPar(int max) : nElems(0)  //constructor
  {
    theVect.resize(max);        //size the vector
  }

void insert(double value)      //put element into array
 {
   theVect[nElems] = value;    //insert it
   nElems++;                   //increment size
 }

int getSize()                  //return number of items
 { return nElems; }

void display()                 //displays array contents
 { cout << "A= ";
 for(int j=0; j<nElems; j++)      //for each element,
   cout << theVect[j] << " ";    //display it
 cout << endl;
 }

 int partitionIt(int left, int right, double pivot)
 {
   int leftMark = left - 1;        //right of first elem
   int rightMark = right + 1;      //left of pivot
   while(true)
   {
     while(leftMark < right &&  theVect[++leftMark] < pivot) ;  //(nop)
     while(rightMark > left && theVect[--rightMark] > pivot) ;  //(nop)
     if(leftMark >= rightMark)    //if markers cross,
        break;                    //   partition done
     else                         //not crossed, so
        swap(leftMark, rightMark); //  swap elements
   }  //end while(true)
   return leftMark;                //return partition
 }  //end partitionIt()

void swap(int dex1, int dex2)  //swap two elements
{ double temp;
   temp = theVect[dex1];            //A into temp
   theVect[dex1] = theVect[dex2];   //B into A
   theVect[dex2] = temp;            //temp into B
  }  //end swap(

}; //endof class

int main()
{
  time_t aTime;
  int maxSize = 16;              //array size
  ArrayPar arr(maxSize);         //create the array
  srand( static_cast<unsigned>(time(&aTime)) ); //seed randoms

  for(int j=0; j<maxSize; j++)   //fill array with
  {                           //random numbers
    double n = rand() % 199;
    arr.insert(n);
  }
arr.display();                 //display unsorted array

double pivot = 99;             //pivot value
cout << "Pivot is "<< pivot;
int size = arr.getSize(); //partition array

int partDex = arr.partitionIt(0, size-1, pivot);

cout << ", Partition is at index " << partDex << endl;
arr.display();                 //display partitioned array
return 0;
}  //end main()
