#include "geometry.hpp"

double PI{3.14159};

// Circle class
Circle::Circle(double r) : radius(r) {};
double Circle::getRadius() { return radius; }
double Circle::getDiameter() { return 2 * radius; }
double Circle::getArea() { return PI * radius * radius; }
double Circle::getCircumference() { return 2 * PI * radius; }


// Rectangle class
Rectangle::Rectangle(double l, double w) : length(l), width(w) {}
double Rectangle::getLength() { return length; }
double Rectangle::getWidth() { return width; }
double Rectangle::getPerimeter() { return (2*length) + (2*width); }
double Rectangle::getArea() { return length * width; }

