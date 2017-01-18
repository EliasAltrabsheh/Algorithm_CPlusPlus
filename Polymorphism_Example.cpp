/*Polymorphism involves treating objects of different classes in the same way.

For polymorphism to work, these different classes must be derived (inherited) from the same base class.
 In practice, polymorphism usually involves a function call that actually executes different member functions for objects of different classes*/

 #include <iostream>
using namespace std;

class Shape { // Base class Shape
   protected:
      int width, height;

   public:
      Shape( int a = 0, int b = 0) {
         width = a;
         height = b;
      }

      int area() {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};

class Rectangle: public Shape { // Dervived class i.e child
   public:
      Rectangle( int a = 0, int b = 0):Shape(a, b) { }
      int area () {
         cout << "Rectangle class area :" <<endl;
         return (width * height);
      }
};

class Triangle: public Shape{ // another child
   public:
      Triangle( int a = 0, int b = 0):Shape(a, b) { }
      int area () {
         cout << "Triangle class area :" <<endl;
         return (width * height / 2);
      }
};

// Main function for the program
int main( ) {
   Shape *shape;
   Rectangle rec(10,7);
   Triangle  tri(10,5);

   // store the address of Rectangle
   shape = &rec;

   // call rectangle area.
   shape->area();

   // store the address of Triangle
   shape = &tri;

   // call triangle area.
   shape->area();

   return 0;
}
