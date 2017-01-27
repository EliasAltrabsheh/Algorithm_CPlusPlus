/*When you first hear about them, hash tables sound almost too good to be true.
No matter how many data items there are, insertion and searching (and sometimes deletion) can take close to constant time: O(1) in Big O notation*.

operate in relatively fast O(log N) time. Not only are they fast, hash tables are relatively easy to program.

Disadvantages:

 They’re based on arrays, and arrays are difficult to expand after they’ve been created.
 Also, for some kinds of hash tables, performance might degrade catastrophically when the table becomes too full,
 so the programmer needs to have a fairly accurate idea of how many data items will need to be stored (or be prepared to periodically transfer data to a larger hash table, a timeconsuming process).

This is an example of a hash function.
 It hashes (converts) a number in a large range into a number in a smaller range.
  This smaller range corresponds to the index numbers in an array.
  An array into which data is inserted using a hash function is called a hash table. (We’ll talk more about the design of hash functions in Hour 23.)


In linear probing we search sequentially for vacant cells when a collision occurs.
If 5,421 is occupied when we try to insert cats there, we go to 5,422, then 5,423, and so on, incrementing the index until we find an empty cell.
This is called linear probing because it steps sequentially along the line of cells, probing for an empty cell.

*/
//hash.cpp //demonstrates hash table with linear probing
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

  int hashFunc(int key)
  {
    return key % arraySize; // Hash function (depending on what key find moudules from 0-9)
  }
//----------------------------------
//---- Inserting items into table
  void insert(DataItem* pItem) // insert a Data item
    {
      int key = pItem-> iData; // extract key from location of iData
      int hashVal = hashFunc(key); // Hash Value so it returns modules
      while(hashArray[hashVal] != NULL && hashArray[hashVal]->iData != -1) // inserting data and dealing wih Collisions
      {
        ++hashVal;                   //go to next cell
        hashVal %= arraySize;        //wraparound if necessary
      }
    hashArray[hashVal] = pItem;     //insert item
    }
//----------------------------------------------
//---- Removing key from hash table
DataItem* remove(int key) // remove data item
{
 int hashVal = hashFunc(key);    //hash the key

 while (hashArray[hashVal] != NULL) //until empty cell,
 {
   if(hashArray[hashVal]->iData == key)
   {
     DataItem* pTemp = hashArray[hashVal]; //save item
     hashArray[hashVal] = pNonItem;        //delete item
     return pTemp;                         //return item
   }
      ++hashVal;                   //go to next cell
      hashVal %= arraySize;        //wraparound if necessary
    }
  return NULL;                    //can’t find item
} // end Remove

 DataItem* find(int key)            //find item with key
 {
   int hashVal = hashFunc(key);    //hash the key
   while(hashArray[hashVal] != NULL)  //until empty cell,
    {                               //found the key?
       if(hashArray[hashVal]->iData == key)
        return hashArray[hashVal];   //yes, return item

        ++hashVal;   //go to next cell
        hashVal %= arraySize;        //wraparound if necessary
      }
      return NULL;                    //can’t find item
    }



};// end class HashTable

int main()  // Main function
{
  DataItem* pDataItem; // initilization of pointer

  int aKey, size, n, keysPerCell; // initilization of varibles
  time_t aTime;  // time function that returns time from time ibrary

  char choice = 'b'; //get sizes

  cout << "Enter size of hash table: ";
  cin >> size;
  cout << "Enter initial number of items: ";
  cin >> n;
  keysPerCell = 10;  //make table
  HashTable theHashTable(size);

  srand( static_cast<unsigned>(time(&aTime)) ); // casting result for Implicit perssion loss with unsinged

  for(int j=0; j<n; j++)        //insert data
  {
    aKey = rand() % (keysPerCell*size); // seting key values to modules depending on size of array
    pDataItem = new DataItem(aKey);  // allocating new memory
    theHashTable.insert(pDataItem); // insering data depending on number of items
  }
  while(choice != 'x')        //interact with user
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
        cin >> aKey; pDataItem = new DataItem(aKey);
        theHashTable.insert(pDataItem);
      break;
      case 'd':
        cout << "Enter key value to delete: ";
        cin >> aKey; theHashTable.remove(aKey);
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
