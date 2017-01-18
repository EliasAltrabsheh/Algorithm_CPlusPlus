/*
one of the most important concepts in object-oriented programming is that of inheritance.
Inheritance allows us to define a class in terms of another class, which makes it easier to create and maintain an application.
 This also provides an opportunity to reuse the code functionality and fast implementation time.

When creating a class, instead of writing completely new data members and member functions,
 the programmer can designate that the new class should inherit the members of an existing class.
  This existing class is called the base class, and the new class is referred to as the derived class.

The idea of inheritance implements the is a relationship. For example, mammal IS-A animal, dog IS-A mammal hence dog IS-A animal as well and so on.
*/

#include <iostream>

using namespace std;

// Base class 1 Shape
class Shape {
   public:
      void setWidth(int w) {
         width = w;
      }

      void setHeight(int h) {
         height = h;
      }

   protected:
      int width;
      int height;
};

// Base class 2 PaintCost
class PaintCost  {
   public:
      int getCost(int area) {
         return area * 70;
      }
};

// Derived class i.e a rectangle is a shape and the area of it will have a cost
class Rectangle: public Shape, public PaintCost {
   public:
      int getArea() {
         return (width * height);
      }
};

int main(void) {
   Rectangle Rect; //  class Ectangle call

   int area;

   Rect.setWidth(5);  // calling members in class
   Rect.setHeight(5);

   area = Rect.getArea(); // calcaltes area by calling second base class

   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   // Print the total cost of painting
   cout << "Total paint cost: $" << Rect.getCost(area) << endl;

   return 0;
}
