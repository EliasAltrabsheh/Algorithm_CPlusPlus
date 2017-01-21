/*This is a follow-up the program from listing 8.3.
It includes  an adjustment of finding and removing specific links.*/

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

  //--------------------------------------------------------
  
