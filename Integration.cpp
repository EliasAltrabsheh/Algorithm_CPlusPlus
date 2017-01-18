
/*This is a Sample function on how to perform integration using midpoint method.
*/
#include<iostream>
using namespace std;


double Function(double x)
{


  return x; //Insert function here
}

double IntegrateF(double a, double b , int n) // N is number of points you wanna take
{
double result =0.0;
double length =(b-a)/n; //calculate difrence i.e area of rectangle (if function wich has a gradient of zero)

for(int i=0; i<n;++i)
  {
    result = result + Function(a+(i+0.5)*length); // summing up all areas

  }

    result = result*length;
}


int main()
{
  cout  << "Integration of x is with bound (2,1) "<<endl;
cout << "Your anwser is : "<< IntegrateF(1,2,100) << endl;
  return 0;
}
