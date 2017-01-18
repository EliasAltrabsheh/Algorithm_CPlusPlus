/*This is a sample program to deal with Vectors.

Vectors has the benefits of resizes the vector unlike the size of the array remains fixed with initlazation.
*/

#include <iostream>
#include <vector> // This vector header files allows us to use vectors stl files . Its usefull for handelling sizing of vector by using empty(); and size() elements of its class
using namespace std;

class LowArray
{
private:
  vector<double> v; // Define vector

public:

  LowArray(int max)
  {
    v.resize(max);
  }

  void SetElem(int index, double value)
  {
    v[index] = value;
  }

  void getElem(int index)
  {
    return v[index];
  }
};

int main()
{
  LowArray arr(100);
  int nElems = 0;
  int j;

  arr.setElem(0, 77);   //insert 10 items
  arr.setElem(1, 99);
  arr.setElem(2, 44);
  arr.setElem(3, 55);
  arr.setElem(4, 22);
  arr.setElem(5, 88);
  arr.setElem(6, 11);
  arr.setElem(7, 00);
  arr.setElem(8, 66);
  arr.setElem(9, 33);
  nElems = 10;

for(j = 0; j<nElems; j++)
{
  cout << arr.getElem(j) << " ";

}
cout << endl;

int searchKey = 26;          //search

for(j=0; j<nElems; j++)//for each element,
{
  if(arr.getElem(j) == searchKey)    //found item?
    break;
}

if(j == nElems)
  cout << "Can’t find" << searchKey << endl;
else
  cout << "Found"  << searchKey << endl;


double deleteKey = 55;  //delete item with key 55

cout << "Deleting" << deleteKey << endl;

for(j=0; j< nElems; j++)      //look for it
{
  if(arr.getElem(j) == deleteKey)
    break;
}
 for(int k=j; k< nElems; k++)  //move higher ones down
 {
   arr.setElem(k, arr.getElem(k+1) );
 }

nElems--;

//decrement size //-------------------------------------------------------------
for(j=0; j<nElems; j++)      //display items cout
{
  cout <<  arr.getElem(j) << " " ;
}

cout << endl;
return 0;

}
