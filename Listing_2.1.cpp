

/*This program demonstrates the uses of arrays.
 We used an array as a storage method for simplicity and used no class structures.
 */
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////
int main()
{
  int arr[100];                //array initialization
  int nElems = 0;              //number of items
  int j;                       //loop counter
  int searchKey;//key of item to search for

  //-------------------------------------------------------------
  arr[0] = 77;                 //insert 10 items
  arr[1] = 99;
  arr[2] = 44;
  arr[3] = 55;
  arr[4] = 22;
  arr[5] = 88;
  arr[6] = 11;
  arr[7] = 00;
  arr[8] = 66;
  arr[9] = 33;
  nElems = 10;
  //-------------------------------------------------------------

  for(j=0; j< nElems; j++) //display items in row
  {
    cout << arr[j] << " ";
  }

  cout << endl;

  //-------------------------------------------------------------
  searchKey = 66;
  //find item with key 66
  for(j=0; j<nElems; j++)
  {
    if(arr[j] == searchKey)   //found item
    break;                 //yes, exit before end

  }     //for each element,

  if(j == nElems)   // last item
    cout << "Can’t find"  << searchKey << endl; //yes

  else
    cout << "Found" << searchKey << endl;      //no
    //-------------------------------------------------------------

  searchKey = 55;              //delete item with key 55
  cout << "Deleting" << searchKey << endl;

  for(j=0; j<nElems; j++)      //look for it
  {
    if(arr[j] == searchKey)
      break;
  }
   for(int k=j; k<nElems; k++) 
   {
     arr[k] = arr[k+1];  // Shift postion of data
   }

  nElems--;

  //decrement size //-------------------------------------------------------------
  for(j=0; j<nElems; j++)      //display items cout
  {
    cout << arr[j] << " " ;
 }

cout << endl;
return 0;
}  //end main()
