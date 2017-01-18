/* This sample complements 2.3 but with an improved data structure storage.  As we now have a class we no longer use indexing method and replaced by functions.
*/

#include <iostream>
#include <vector>

using namespace std;

class HighArray // Our new class
{
private:
  vector<double> v;
  int nElems;        // defining elements
public:

  HighArray(): nElems(0)  // Default  Constructer
  {}

  HighArray(int max)  // Another constructer
  {
    v.resize(max);   //size the vector
  }

  bool find(double searchKey) // Bool used for a True /false return
  {   //find specified value
    int j;
    for (j=0;j<nElems; j++)
    {
      if (v[j] == searchKey)
        break;
      }
      if(j == nElems)
        return false;
      else
        return true;

  }

  void insert (double value)  // Inserting elemnt
  {
    v[nElems] = value;
    nElems ++;
  }

  bool remove(double value)  //remove element from array
  {
    int j;
    for(j = 0; j < nElems;j++)
    {
      if( value == v[j])
        break;            // break for loop when done
    }
    if(j == nElems)
      return false;
    else
      {
        for(int k = j;k<nElems;k++)
        {
          v[k]= v[k+1];
        }
       nElems--;
       return true;
      }
  }

  void display()  // Dsiplay array
  {

  for(int j=0;j<nElems; j++)
    cout << v[j] << "";
  cout<<endl;
  }
};// End of class

int main()
{
  int maxSize = 100;
  HighArray arr(maxSize); // Initlaize vector

  arr.insert(77);
  arr.insert(99);     // Inserting values
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

  if( arr.find(searchKey))
    cout << "Found" << searchKey << endl;
  else
    cout << "Cant find" << searchKey << endl;

  cout << "Deleting 0, 55, and 99" << endl;

  arr.remove(0);
  arr.remove(55);
  arr.remove(99);

  arr.display();
  return 0;
}
