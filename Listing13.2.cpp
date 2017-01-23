/* Quicksort is undoubtedly the most popular sorting algorithm, and for good reason: in the majority of situations, it’s the fastest, operating in O(N*logN) time.
 (This is true only for in-memory sorting; for sorting data in disk files, other algorithms, such as mergesort, may be better.) Quicksort was discovered by C.A.R. Hoare in 1962.


1. Partition the array or subarray into left (smaller keys) and right (larger keys) groups.
2. Call ourselves to sort the left group.
3. Call ourselves again to sort the right group.

The quick sort
*/

#include <iostream>
#include<vector>
#include<cstdlib>                      //for random numbers
#include<ctime>                        //for random numbers
using namespace std;

class ArrayIns
{
  private: vector<double>(theVect);         //vector of doubles
  int nElems;                      //number of data items public: //-------------------------------------------------------------
  ArrayIns(int max) : nElems(0)       //constructor
  { theVect.resize(max); }
  //size the vector } //-------------------------------------------------------------
  void insert(double value)           //put element into array
  {
    theVect[nElems] = value;         //insert it
    nElems++;                        //increment size

  } //-------------------------------------------------------------

  void display()                      //displays array contents
  {
    cout << "A=";
    for(int j=0; j<nElems; j++)      //for each element,
      cout << theVect[j] << " ";    //display it
    cout << endl;
  } //-------------------------------------------------------------
  void quickSort()                    //sort array
  {
    recQuickSort(0, nElems-1);       //call recursive sort
  } //--------------------------------------------------------------
  void recQuickSort(int left, int right)  //recursive sort
  {
    if(right-left <= 0)                  //if size <= 1,
    return;                          //   already sorted
    else                                 //size is 2 or larger
    {
      double pivot = theVect[right];    //rightmost item //partition range
      int partition = partitionIt(left, right, pivot);
      recQuickSort(left, partition-1);  //sort left side
      recQuickSort(partition+1, right); //sort right side
    }
  }  //end recQuickSort()

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
    int maxSize = 16;                   //array size
    ArrayIns arr(maxSize);              //create array
    srand( static_cast<unsigned>(time(&aTime)) );  //seed randoms

    for(int j=0; j<maxSize; j++)        //fill array with
    {                                //random numbers double n = rand() % 99; arr.insert(n); } arr.display();                      //display items arr.quickSort();                    //quicksort them arr.display();                      //display them again return 0; }  //end main()
