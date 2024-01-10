#ifndef GEOMETRY_H
#define GEOMETRY_H

class Circle {
private:
  double radius;

public:
  // Constructor
  Circle(double);
  
  // Methods
  double getRadius();
  double getDiameter();
  double getArea();
  double getCircumference();
};

class Rectangle {
private:
  double length;
  double width;

public:
  // Constructor
  Rectangle(double, double);

  // Methods
  double getLength();
  double getWidth();
  double getPerimeter();
  double getArea();
};

#endif
