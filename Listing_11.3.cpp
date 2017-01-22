/* Binanry search using recursion insted of loop function :

We can transform this loop-based function into a recursive function quite easily.
In the loop-based approach, we change lowerBound or upperBound to specify a new range, and then cycle through the loop again. Each time through the loop we divide the range (roughly) in half.
The recursive binary search has the same Big O efficiency as the nonrecursive version: O(logN). It is somewhat more elegant, but might be slightly slower.

Q- Recursion seems weird and complicated. Do I really need to know about it?
After you get used to recursion it’s a very powerful conceptual tool. Sooner or later you’ll encounter a problem that could be solved in a simple way using recursion.

Q-Isn’t it easier to think in terms of a loop-based approach to problems?
A Some situations are hard to visualize in terms of loops, but are easy in terms of recursion.
*/

#include <iostream>
#include <vector>

using namespace std;

class OrdArray // class order array
{
private:
  vector<double> v;
  int nElems;
public:

  OrdArray(int max) : nElems(0) // constructer
  { v.resize(max);}   //

  int getSize()
  {
    return nElems;   // Return number of element left
  }

  int find(double searchKey)
  {
    return recFind(searchKey,0 ,nElems -1);
  }

  int recFind(double searchKey, int lowerBound, int upperBound)
   {
     int curIn;
  curIn = (lowerBound + upperBound ) / 2;
   if(v[curIn]==searchKey)
   return curIn;               //found it
   else
   if(lowerBound > upperBound)
   return nElems;              //can’t find it else                           //divide range
   {
      if(v[curIn] < searchKey)    //it’s in upper half
       return recFind(searchKey, curIn+1, upperBound);
        else                        //it’s in lower half
        return recFind(searchKey, lowerBound, curIn-1);
      }  //end else divide range
    }  //end recFind()

void insert(double value)  //put element into array
  {
    int j;
    for(j=0; j<nElems; j++)        //find where it goes
    if(v[j] > value)            //(linear search)
    break;
    for(int k=nElems; k>j; k--)    //move bigger ones up
    v[k] = v[k-1]; v[j] = value;                  //insert it
    nElems++;                      //increment size
  }  //end insert()

  void display()             //displays array contents
  {
     for(int j=0; j<nElems; j++)       //for each element,
     cout << v[j] << " ";  //display it
     cout << endl;
   }
 }; // end class OrdArray

 int main()
 {
   int maxSize = 100;             //array size
   OrdArray arr(maxSize);         //ordered array
   arr.insert(72);                //insert items
   arr.insert(90);
   arr.insert(45);
   arr.insert(126);
   arr.insert(54);
   arr.insert(99);
   arr.insert(144);
   arr.insert(27);
   arr.insert(135);
   arr.insert(81);
   arr.insert(18);
   arr.insert(108);
   arr.insert(9);
   arr.insert(117);
   arr.insert(63);
   arr.insert(36);

   arr.display();                 //display array

   int searchKey = 27;            //search for item

   if( arr.find(searchKey) != arr.getSize() )
      cout << "Found " << searchKey << endl;
   else
      cout << "Can’t find "  << searchKey << endl;
   return 0;
 }  //end main()
