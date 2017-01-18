/* This sample looks at ordered array. Ordered array has an advantage for when we use various search methods (binary search) Which take less number of steps to find the element.
The program consists of a find function that searches specifically by dividing array by half.

We also use get size() to return numbers of data items in array  */

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
    int lowerBound = 0;
    int upperBound = nElems -1;   // Define boundries (U,L)
    int curIn;

    while(true)    // while loop look for bool return to be false to break
      {
        curIn = (lowerBound + upperBound ) / 2;  // divide range

        if(v[curIn] == searchKey)
          return curIn;        // return value
        else if(lowerBound > upperBound)
          return nElems;
        else
          {
          if (v[curIn] < searchKey)
             lowerBound = curIn + 1;//it’s in lowerBound half
          else
            upperBound = curIn - 1; //it’s in upperBoundhalf
          }
        }
      }

  void insert (double value)
  {
    int j;

    for(j=0; j<nElems; j++)
    {         //find where it goes
      if(v[j] > value)
        break;
    }

    for(int k=nElems; k>j; k--)
    {
      v[k] = v[k-1];

    }
    v[j] = value;
    nElems ++;
  }


  bool remove(double value)
  {
    int j = find(value);
    if(j==nElems)
      return false;
    else
      {
        for(int k=j; k<nElems; k++)   //move bigger ones down
        {
          v[k] = v[k+1];
        }
        nElems--;                     //decrement size
        return true;
      }


  }

  void display()
  {

  for(int j=0;j<nElems; j++)
    cout << v[j] << "";
  cout<<endl;
  }
};// End of class

int main()
{
  int maxSize = 100;
  OrdArray arr(maxSize);// Initlaize vector

  arr.insert(77);
  arr.insert(99);
  arr.insert(44);
  arr.insert(55);
  arr.insert(22);
  arr.insert(88);
  arr.insert(11);
  arr.insert(0);
  arr.insert(66);
  arr.insert(33);

  arr.display();

  int searchKey = 35;

  if( arr.find(searchKey) != arr.getSize() ) // condotion needed to search for item
    cout << "Found" << searchKey << endl;
  else
    cout << "Cant find" << searchKey << endl;

  arr.display();                   //display items
  cout << "Deleting 0, 55, and 99" << endl;
 // removal
  arr.remove(0);
  arr.remove(55);
  arr.remove(99);

  arr.display();

  return 0;
}
