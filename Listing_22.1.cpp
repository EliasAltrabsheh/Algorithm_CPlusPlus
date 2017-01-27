/* load factor for hash tables is the number items inserted / number of cells.

In general, the greater the load factor the more clusters there will be. However, clusters can form even when the load factor isn’t high.

To aviod clustring we use can use two methods :

1) quadratic probing:  Quadratic probing is an attempt to keep clusters from forming. The idea is to probe more widely separated cells, instead of those adjacent to the initial hash site.
In a linear probe, if the primary hash index is x, subsequent probes go to x+1, x+2, x+3, and so on.
In quadratic probing, probes go to x+1, x+4, x+9, x+16, x+25, and so on. The distance from the initial site is the square of the step number, so the probes fall at x+12, x+22, x+32, x+42, x+52, and so on.

Quadratic probes eliminate the clustering problem we saw with the linear probe, which is called primary clustering.
However, quadratic probes suffer from a different and more subtle clustering problem. This occurs because all the keys that hash to a particular cell follow the same sequence in trying to find a vacant space.
This phenomenon is called secondary clustering .Secondary clustering is not a serious problem, but quadratic probing is not often used because there’s a slightly better solution

2) double hashing

eliminate secondary clustering as well as primary clustering,another approach can be used: double hashing (sometimes called rehashing).
Secondary clustering occurs because the algorithm that generates the sequence of steps in the quadratic probe always generates the same steps: 1, 4, 9, 16, and so on.

The solution is to hash the key a second time, using a different hash function, and use the result as the step size.
 For a given key the step size remains constant throughout a probe, but it’s different for different keys.

 Experience has shown that this secondary hash function must have certain characteristics. These are as follows:
 ● It must not be the same as the primary hash function.
 ● It must never output a 0 (otherwise there would be no step; every probe would land on the same cell, and the algorithm would go into an endless loop).


*/
//Doublehash.cpp //demonstrates hash table with Quadratic probing
#include <iostream>
#include <vector>
#include <cstdlib>                    //for random numbers
#include <ctime>                      //for random numbers
using namespace std;

class DataItem
{                                  //(could have more data)
   public:
     int iData;                      //data item (key)

     DataItem(int ii):iData(ii)   // constructer
     {}
}; // end of class DataItem

class HashTable
{
private:
  vector<DataItem*> hashArray; // vector of size of hash array  with DataItem being a class(hold array table)
  int arraySize;    // array size initilization
  DataItem* pNonItem;  //  pointer for deleted items
public:

  HashTable(int size): arraySize(size) //constructer (setting initial value for member varibles )
  {
    arraySize = size;
    hashArray.resize(arraySize); // size of vector
    for(int j=0; j<arraySize; j++)
    {
      hashArray[j]=NULL;
    }
    pNonItem = new DataItem(-1); // deleted item key is -1 (new operater is defult allocating space for data items )
  }

  void displayTable()
  {
    cout << "Table: ";
    for (int j=0;j<arraySize; j++)
    {
      if(hashArray[j] != NULL)
        cout << hashArray[j] ->iData << " ";
      else
        cout << "** ";
    }
    cout << endl;
  }
//-------------------------------
//---First hash function
//----------------------------------

  int hashFunc1(int key)
  {
    return key % arraySize; // Hash function (depending on what key find moudules from 0-9)
  }
//---------------------------------------------------
//------second hashFunction
//non-zero, less than array size, different from hF1
 //array size must be relatively prime to 5, 4, 3, and 2
int hashFunc2(int key)
{
  return 5 - key % 5;
}


//----------------------------------
//---- Inserting items into table
  void insert(int key, DataItem* pDataItem) // insert a Data item
    {
    int hashVal = hashFunc1(key);  //hash the key
    int stepSize = hashFunc2(key); //get step size

      while(hashArray[hashVal] != NULL && hashArray[hashVal]->iData != -1) // inserting data and dealing wih Collisions
      {
        hashVal+= stepSize;                   //go to next cell
        hashVal %= arraySize;        //wraparound if necessary
      }
    hashArray[hashVal] = pDataItem;     //insert item
  } // End insert member
//----------------------------------------------
//---- Removing key from hash table
DataItem* remove(int key) // remove data item
{
 int hashVal = hashFunc1(key);    //hash the key
int stepSize = hashFunc2(key); //get step size
 while (hashArray[hashVal] != NULL) //until empty cell,
 {
   if(hashArray[hashVal]->iData == key)
   {
     DataItem* pTemp = hashArray[hashVal]; //save item
     hashArray[hashVal] = pNonItem;        //delete item
     return pTemp;                         //return item
   }
      hashVal += stepSize;                   //go to next cell
      hashVal %= arraySize;        //wraparound if necessary
    }
  return NULL;                    //can’t find item
} // end Remove

 DataItem* find(int key)            //find item with key
 {
   int hashVal = hashFunc1(key);  //hash the key
   int stepSize = hashFunc2(key); //get step size

   while(hashArray[hashVal] != NULL)  //until empty cell,
    {                               //found the key?
       if(hashArray[hashVal]->iData == key)
          return hashArray[hashVal];   //yes, return item

        hashVal += stepSize;                   //go to next cell
        hashVal %= arraySize;        //wraparound if necessary
      }
      return NULL;                    //can’t find item
    } // end find value


};// end class HashTable

int main()  // Main function
{

  DataItem* pDataItem; // initilization of pointer

  int aKey, size, n; // initilization of varibles
  time_t aTime;  // time function that returns time from time ibrary

  char choice = 'b'; //get sizes

  cout << "Enter size of hash table( prime number ): ";
  cin >> size;
  cout << "Enter initial number of items: ";
  cin >> n;
  HashTable theHashTable(size);

  srand( static_cast<unsigned>(time(&aTime)) ); // casting result for Implicit perssion loss with unsinged

  for(int j=0; j<n; j++)        //insert data
  {
    aKey = rand() % (2 * size); // seting key values to modules depending on size of array
    pDataItem = new DataItem(aKey);  // allocating new memory
    theHashTable.insert(aKey,pDataItem); // insering data depending on number of items
  }
  while(true)        //interact with user
  {
    cout << "Enter first letter of " << "show, insert, delete, or find: ";
    char choice;
    cin >> choice;
    switch(choice)
     {
      case 's':
        theHashTable.displayTable();
        break;

      case 'i':
        cout << "Enter key value to insert: ";
        cin >> aKey;
        pDataItem = new DataItem(aKey);
        theHashTable.insert(aKey, pDataItem);
        break;

      case 'd':
        cout << "Enter key value to delete: ";
        cin >> aKey;
        theHashTable.remove(aKey);
        break;

      case 'f':
        cout << "Enter key value to find: ";
        cin >> aKey;
        pDataItem = theHashTable.find(aKey);
        if(pDataItem != NULL)
          cout << "Found " << aKey << endl;
      else
        cout << "Could not find " << aKey << endl;
      break;

      default:
       cout << "Invalid entry\n";

    }  //end switch
  }  //end while
    return 0;
  }  //end main()
