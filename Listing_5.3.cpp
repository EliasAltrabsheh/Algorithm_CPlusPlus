/* This is a sample of sorting objects by using Insertion method*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
private:
  string lastName;
  string firstName;
  int age;
public:

Person (string last, string first, int a): lastName(last), firstName(first), age(a) // constructer
{}
//-------------------------------------------------------------------
void displayPerson()
{
  cout << " Last Name: " << lastName;
  cout << " First Name " << firstName;
  cout << " , Age: " << age << endl;
}

string getLast()
{return lastName;} // gert last name of preson

};

class ArrayIn
{
private:
  vector<Person*> v; //vector of pointers to person
  int nElems;
public:

ArrayIn(int max):nElems(0)
{
  v.resize(max);  // resize vectior to the lenght required
}

void insert(string last, string first, int age)
{
  v[nElems] = new Person(last, first, age); // insert elements in diffrent component of vector
  nElems ++;
}

void display()
{
  for(int j=0; j<nElems; j++)
    v[j]->displayPerson(); // easier way to write a dot operator. i.e To access something a pointer points
}

void insertionSort() // Insertion soprt algorthim
{
  int in,out;

  for(out=1; out <nElems; out++) // for loop to explore outer loop(dividing line)
    {
      Person* temp =v[out]; // set deviding line to temp
      in = out; // start shifting at out

      while (in>0 && v[in-1]->getLast() > temp->getLast() )
      {
        v[in] = v[in-1]; // shift item to right
        --in; // go left one postion
      }
     v[in] = temp; // insert marked item
    }
 }
};

int main()
{
  int maxSize = 100;
  ArrayIn arr(maxSize);// create array of 100 size

  arr.insert("Evans", "Patty", 24);
  arr.insert("James", "May", 59);
  arr.insert("Smith", "joe", 37);
  arr.insert("Simth", "Ryan", 37);
  arr.insert("Hall", "Tom", 43);
  arr.insert("Harary", "Taka", 21);
  arr.insert("Lutchman", "Bryan", 29);
  arr.insert("Bond", "James", 72);
  arr.insert("Evans", "David Mummary", 22);
  arr.insert("Busby", "Ben", 18);
  cout << "Before Sorting list : " << endl;
    cout << endl;
  arr.display();  // display items
  arr.insertionSort(); // sort items using insertionSort
  cout << endl;
  cout << "After Sorting List : " << endl;
    cout << endl;
  arr.display();// display after sorrted;


return 0;

}
