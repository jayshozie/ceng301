#include <iostream>
#include <math.h>

class Rectangle {
    double width, height;
public:
    void set_values(double, double);
    double area() {return width*height;}
};

void Rectangle::set_values(double a, double b) {
    height = a;
    width = b;
};

int main()
{
    Rectangle rect;
    rect.set_values(sqrt(2), sqrt(2));
    std::cout << "Area of rect = " << rect.area();
}


