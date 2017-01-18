/* This program focuses on using links as data structure types. This is related to how array is constructed.
With an array the insertion is slow. (Vectors differ from this as they can be resized).
with links, we use pointers to link to other objects improving performance massively.

With an array, you can access data using index number. With links, you have to use relations to find particular data set.

To implement a simple link program we use the following :
 1) Inserting an item at the beginning of the list
 2) Removing the item at the beginning of the list
 3) Iterating through the list to display its contents*/



#include <iostream>

using namespace std;

class Link
{
public:
  int iData; // data item
  double dData;// data item double type
  Link* pNext;//pointer to next link in list

Link(int id, double dd) : iData(id),dData(dd),pNext(NULL)
{}

void displayLink()
{
cout << "{" << iData << ", " << dData << "} ";
 }
};//end class link

class Linklist
{
private:
  Link* pFirst; // pointer to first link on list
public:

Linklist(): pFirst(NULL) //constructer
{ }//no links yet

bool isEmpty()
{return pFirst == NULL;}

void insertFirst(int id, double dd)
{
  Link* pNewLink = new Link(id,dd);
  pNewLink-> pNext = pFirst;
  pFirst = pNewLink;
}

Link* getFirst()
{return pFirst;}

void removeFirst()  // delete first link(assume list is not empty)
{
  Link* pTemp = pFirst; // save file
  pFirst = pFirst -> pNext; // unlink
  delete pTemp;  // delete old first
}

void displayList()
{
  cout << "List (first --> Last): ";
  Link* pCurrent = pFirst;    //start at beginning of list
  while(pCurrent != NULL)     //until end of list,
  {
    pCurrent->displayLink(); //print data
    pCurrent = pCurrent->pNext;  //move to next link
  }
  cout << endl;
 }
};//end of class

int main()
{
  Linklist theList;    //make new list using class

  theList.insertFirst(22, 2.99);         //insert four items
  theList.insertFirst(44, 4.99);
  theList.insertFirst(66, 6.99);
  theList.insertFirst(88, 8.99);

  theList.displayList();                 //display list

  while( !theList.isEmpty() )            //until it’s empty,
  {
    Link* pTemp = theList.getFirst();  //get first link //display its key
    cout << "Removing link with key" << pTemp->iData << endl;
    theList.removeFirst();             //remove it
  }
   theList.displayList();                //display empty list
   return 0;

}// main end
