/* In this Program, we will look at queuing data type using c++. The queues system works like at the movies.
The first person to join the line is the first person to buy a ticker. the last person to join the lane is the last person to get a ticket and he may miss out if tickets are sold.*/
#include<iostream>
#include<iostream>
#include <vector>
using namespace std;

class Queue
{
private:          // intialization process in private entity
  int maxSize;
  vector<int> queVect;
  int front;
  int rear;
  int nItems;
public:
  Queue(int max): maxSize(max), front(-1), rear(-1), nItems(0)   // constructer
  {
    queVect.resize(maxSize);  // size constructer depending on elements
  }

void insert(int j)
{
  if(rear == maxSize-1)
    rear = -1;
  queVect[++rear] = j;
  nItems++;
}

int remove()
{
  int temp = queVect[++rear];
  if(front == maxSize)
    front = 0;
  nItems --;
  return temp;
}

int peekFront()
{
  return queVect[front];
}
bool isEmpty()
{
  return (nItems ==0);
}
bool isFull()
{
  return(nItems == maxSize);
}
int size()
{
  return nItems;
}
};// end of class

int main()
{
  Queue theQueue(5); // hold five values only to start with with intialization of vector

  theQueue.insert(10);
  theQueue.insert(20);
  theQueue.insert(30);
  theQueue.insert(40);

  theQueue.remove();  // remove
  theQueue.remove();
  theQueue.remove();

  theQueue.insert(50);
  theQueue.insert(60);
  theQueue.insert(70);
  theQueue.insert(80);

  while( !theQueue.isEmpty())
  {
    int n =theQueue.remove();
    cout << n <<" ";
  }
  cout << endl;
  return 0;
}// end main
