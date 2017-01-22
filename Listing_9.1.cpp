/* This program will look at the implementaion of stack structures using Linked Lists rather than arrays

In this hour, you’ve learned the following:
● An Abstract Data Type (ADT) is a class considered without reference to its implementation.
● Stacks and queues are examples of ADTs. They can be implemented using either arrays or linked lists.
● An ADT simplifies program design by allowing you focus on the essentials of a data storage structure, without worrying (at least initially) about its implementation.
● A double-ended list allows easy insertion at the end of the list.
● A double-ended list maintains a pointer to the last link in the list, often called last, as well as to the first.

Q I’m a little unclear on the point of all this ADT stuff?
A In large programming projects it’s helpful to start designing a program by focusing on the interface a class will present to its users,
 without worrying until later how it will be implemented.
 You don’t need to know too much about ADTs and the philosophy behind them to understand this book, which is more concerned with the nuts and bolts of how data structures work.
 But the idea of ADTs is important in software engineering

Q How do I decide whether to implement a stack or queue as a vector or a linked list?

In many cases it doesn’t matter how you implement a stack or queue. Both vectors and linked lists provide fast O(1) performance for insertion and deletion. A priority

*/

#include <iostream>

using namespace std;

class Link
{
public:
  double dData; // data Item
  Link* pNext; // Pointer Next link in list

Link(double dd): dData(dd),pNext(NULL)
{}

void displayLink()
{ cout << dData << " "; }
};//end class




class LinkList
{
private:
  Link* pFirst; // pointer to first link on list
public:
  LinkList(): pFirst(NULL)
  {}

~LinkList() //destructor (deletes links)
{
  Link* pCurrent = pFirst;    //start at beginning of list
  while(pCurrent != NULL)     //until end of list,
  {
    Link* pOldCur = pCurrent;    //save current link
    pCurrent = pCurrent->pNext;  //move to next link
    delete pOldCur;              //delete old current (deletes memory location )
  }
}
bool isEmpty()                 //true if list is empty
{ return (pFirst==NULL); }

void insertFirst(double dd)    //insert at start of list
{                           //make new link
   Link* pNewLink = new Link(dd);
   pNewLink->pNext = pFirst;   //newLink --> old first
   pFirst = pNewLink;          //first --> newLink
 }

double deleteFirst()           //delete first item
{                           //(assumes list not empty)
   Link* pTemp = pFirst;       //save old first link
   pFirst = pFirst->pNext;     //remove it: first-->old next
   double key = pTemp->dData;  //remember data
   delete pTemp;               //delete old first link
   return key;                 //return deleted link’s data
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


class LinkStack
{
 private:
    LinkList* pList;            //pointer to linked list
 public:

 LinkStack()
 {pList = new LinkList;} //make a linked list

 ~LinkStack()                //destructor
 { delete pList; }           //delete the linked list

 void push(double j)            //put item on top of stack
 { pList->insertFirst(j); }

 double pop()                   //take item from top of stack
 { return pList->deleteFirst(); }

 bool isEmpty()                 //true if stack is empty
 { return ( pList->isEmpty() ); }

void displayStack()
{
cout << "Stack (top-->bottom): ";
 pList->displayList();
}
};  //end class LinkStack

int main()
{ LinkStack theStack;            //make stack
theStack.push(20);             //push items
theStack.push(40);
theStack.displayStack();       //display stack (40, 20)
theStack.push(60);             //push items
theStack.push(80);
theStack.displayStack();       //display (80, 60, 40, 20,)
theStack.pop();                //pop items (80, 60)
theStack.pop();
theStack.displayStack();       //display stack (40, 20)

return 0;
}  //end main()
