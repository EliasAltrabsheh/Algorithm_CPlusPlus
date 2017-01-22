/*This is a follow-up the program from listing 8.3.
It includes  an adjustment of finding and removing specific links.

Efficency of listed links :

Insertion and deletion at the beginning of a linked list are very fast. They involve changing only one or two pointers, which takes O(1) time.
Finding or deleting a specified item requires searching through, on the average, half the items in the list. T
his requires O(N) comparisons. An array is also O(N) for these operations, but the linked list is nevertheless faster because nothing needs to be moved when an item is inserted or removed.
The increased efficiency can be significant, especially if a copy takes much longer than a comparison

Of course, another important advantage of linked lists over arrays is that the linked list uses exactly as much memory as it needs,
and can expand to fill all available memory. The size of an array is fixed when it’s created;

Q How do I know when to use a linked list instead of an array?

 You should consider a linked list when there will be lots of insertions of new data items or deletions of existing items.

Q When shouldn’t I use a linked list?
 Don’t use a linked list if you need frequent access to data items with a specified key, or to arbitrary items in the list (such as the access provided by array indices).



*/

#include <iostream>

using namespace std;

class Link
{
public:
  int iData; // data item
  double dData;// data item double type
  Link* pNext;//pointer to next link in list

Link(int id, double dd) : iData(id),dData(dd),pNext(NULL) // constructer
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
  Linklist(): pFirst(NULL)
  {}

  ~Linklist() //destructor (deletes links)
  {
    Link* pCurrent = pFirst;    //start at beginning of list
    while(pCurrent != NULL)     //until end of list,
    {
      Link* pOldCur = pCurrent;    //save current link
      pCurrent = pCurrent->pNext;  //move to next link
      delete pOldCur;              //delete old current (deletes memory location )
    }
  }


  void insertFirst(int id, double dd)
   {                           //make new link
     Link* pNewLink = new Link(id, dd); // creates new memory allocation for link
     pNewLink->pNext = pFirst;   //it points to old first link
     pFirst = pNewLink;          //now first points to this
    }

Link* find(int key)            //find link with given key
{                           //(assumes non-empty list)
  Link* pCurrent = pFirst;           //start at ‘first’
  while(pCurrent->iData != key)      //while no match,
   {
    if(pCurrent->pNext == NULL)     //if end of list,
      return NULL;                 //didn’t find it
    else                            //not end of list,
      pCurrent = pCurrent->pNext;  //go to next link
     }
     return pCurrent;  //found it
  }

  bool remove(int key)           //remove link with given key
  {                           //(assumes non-empty list)
     Link* pCurrent = pFirst;    //search for link
     Link* pPrevious = pFirst;

    while(pCurrent->iData != key)
    {
      if(pCurrent->pNext == NULL)
        return false;         //didn’t find it

      else
        {
           pPrevious = pCurrent; //go to next link
           pCurrent = pCurrent->pNext;
          }
        }                        //found it
        if(pCurrent == pFirst)      //if first link,
          pFirst = pFirst->pNext;  //change first
        else                                   //otherwise,
          pPrevious->pNext = pCurrent->pNext; //bypass it

        delete pCurrent;            //delete link
        return true;                //successful removal
      }
  //--------------------------------------------------------
  void displayList()             //display the list
  {
    cout << "List (first-->last): ";
    Link* pCurrent = pFirst;    //start at beginning of list
    while(pCurrent != NULL)     //until end of list,
    {
      pCurrent->displayLink();     //print data
      pCurrent = pCurrent->pNext;  //move to next link
    }
    cout << endl;
  }
 };  //end class LinkList


 int main()
 {
   Linklist theList;                     //make list

   theList.insertFirst(22, 2.99);        //insert 4 items
   theList.insertFirst(44, 4.99);
   theList.insertFirst(66, 6.99);
   theList.insertFirst(88, 8.99);

   theList.displayList();                //display list

   int findKey = 44;                     //find item

   Link* pFind = theList.find(findKey);
   if( pFind != NULL)
   cout << "Found link with key " << pFind->iData << endl;
   else
   cout << "Can’t find link" << endl;

   int remKey = 66;                      //remove item
   bool remOK = theList.remove(remKey);

   if( remOK ) cout << "Removed link with key " << remKey << endl;
   else
   cout << "Can’t remove link" << endl;
   theList.displayList();                //display list return 0;
 }  //end main()
