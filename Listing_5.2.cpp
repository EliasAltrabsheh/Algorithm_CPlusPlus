/* Program sample of insertion sort :

Insertion sort has two main companonts :
It serches from lerft to right in the array and compares values , once a value that found is not in order of initail sort it sets that value in temp file and shifts all elements higher to right and insrts temp value back into array.
This gives it the following efficency:
the maximum comparisons is N-1 sucth that
1+2+3+4+5+6+...N=N(N-1)/2 but as you applied only half of array search the max number of excucations is N(N-1)/4. So that makes run time for O(N^2) for random data.
For sorted data it becomes only matter of outer loop that sucth that its N-1 so its runs in O(N).
 */
 #include <iostream>
 #include <vector>

using namespace std;

class ArrayIns // Define class
{
private: // set access for members in class
  vector<double> v;
  int nElems;

public:

ArrayIns(int max):nElems(0) // constructer of array class using Polymorphism
{
v.resize(max);  // Perform resize of array
}
void insert(double value)
{
  v[nElems]= value;// Insert values into vectors(array)
  nElems++;
}
void display()
{
  for(int j= 0 ;j<nElems; j++) //display entreis of array with space after
    cout << v[j] << " ";
  cout << endl;
}

void insertionSort()
{
  int in,out;

  for(out=1; out<nElems; out++) // For loop incharge of outer sequence (dividing line )
  {
    double temp= v[out];     // =romove marked item

    in = out; // set the shift out 

    while(in>0 && v[in-1] >= temp) //until one is smaller
    {
      v[in] = v[in-1];            //shift item to right
      --in;                       //go left one position
    }
    v[in] = temp;                  //insert marked item
  }
}
};

int main()
 {
  int maxSize = 100;             //array size
  ArrayIns arr(maxSize);         //create the array
  arr.insert(77);                //insert 10 items
  arr.insert(99);
  arr.insert(44);
  arr.insert(55);
  arr.insert(22);
  arr.insert(88);
  arr.insert(11);
  arr.insert(00);
  arr.insert(66);
  arr.insert(33);


  arr.display();                 //display items
  arr.insertionSort();              //bubble sort them
  arr.display();                 //display them again
  return 0;
}  //end main()
