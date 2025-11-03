#include "Complex.h"
#include "MultiDimensionalPoint.h"
#include <iostream>

int main()
{
    // Complex a(3.14, 7.24);
    // Complex b(2.71, 1.41);

    // a.print();
    // b.print();
    // std::cout << a.modulus() << std::endl;
    // Complex d;
    MultiDimensionalPoint x(3);
    MultiDimensionalPoint y(2);
    MultiDimensionalPoint z(3);

    x.setCoordinate(0, 12.3);
    x.setCoordinate(1, 34.5);
    x.setCoordinate(2, 56.7);
    y.setCoordinate(0, 45.6);
    y.setCoordinate(1, 78.9);

    z.setCoordinate(0, 1.1);
    z.setCoordinate(1, 2.2);
    z.setCoordinate(2, 3.3);

    for (int i = 0; i < x.getNumberOfDimensions(); i++) {
        std::cout << "x[" << i << "]: " << x.getCoordinate(i) << std::endl;
    }
    for (int i = 0; i < y.getNumberOfDimensions(); i++) {
        std::cout << "y[" << i << "]: " << y.getCoordinate(i) << std::endl;
    }
    for (int i = 0; i < z.getNumberOfDimensions(); i++) {
        std::cout << "z[" << i << "]: " << z.getCoordinate(i) << std::endl;
    }

    x.print();
    y.print();
    z.print();

    std::cout << "Average of x: " << x.averageOfDimensions() << std::endl;
    std::cout << "Average of y: " << y.averageOfDimensions() << std::endl;
    std::cout << "Average of z: " << z.averageOfDimensions() << std::endl;

    std::cout << "Sum of x: " << x.sumOfDimensions() << std::endl;
    std::cout << "Sum of y: " << y.sumOfDimensions() << std::endl;
    std::cout << "Sum of z: " << z.sumOfDimensions() << std::endl;

    std::cout << "Max of x at: " << x.maxDimension() << std::endl;
    std::cout << "Max of y at: " << y.maxDimension() << std::endl;
    std::cout << "Max of z at: " << z.maxDimension() << std::endl;

    MultiDimensionalPoint w(3);
    w.setCoordinate(0, 9.9);
    w.setCoordinate(1, 8.8);
    w.setCoordinate(2, 7.7);
    MultiDimensionalPoint v(3);
    v.setCoordinate(0, 6.6);
    v.setCoordinate(1, 5.5);
    v.setCoordinate(2, 4.4);
    MultiDimensionalPoint u(3);
    u.setCoordinate(0, 3.3);
    u.setCoordinate(1, 2.2);
    u.setCoordinate(2, 1.1);
    MultiDimensionalPoint t(3);
    t.setCoordinate(0, 0.0);
    t.setCoordinate(1, -1.1);
    t.setCoordinate(2, -2.2);

    // no constructor fo MultiDimensionalPoint[2];
    MultiDimensionalPoint* exampleArray = new MultiDimensionalPoint[5];
    exampleArray[0] = z;
    exampleArray[1] = w;
    exampleArray[2] = v;
    exampleArray[3] = u;
    
    // closest point to x
    MultiDimensionalPoint closest = x.closestPoint(exampleArray, 4);
    for (int i = 0; i <= exampleArray->getNumberOfDimensions(); i++) {
        std::cout << "exampleArray[" << i << "]: ";
        exampleArray[i].print();
    }
    for (int i = 0; i < closest.getNumberOfDimensions(); i++) {
        std::cout << "closest[" << i << "]: " << closest.getCoordinate(i) << std::endl;
    }

    std::cout << "Euclidean Distance between x and z: " << x.euclideanDistance(z) << std::endl;
    std::cout << "Manhattan Distance between x and z: " << x.manhattanDistance(z) << std::endl;
}
