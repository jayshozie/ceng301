#ifndef MULTIDIMENSIONALPOINT_H
#define MULTIDIMENSIONALPOINT_H

#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

class MultiDimensionalPoint {
private:
    int dimension;
    double* coordinates;
public:
    // Constructor and Destructor
    MultiDimensionalPoint(int dim = 0);
    ~MultiDimensionalPoint();

    // Copy constructor
    MultiDimensionalPoint(const MultiDimensionalPoint& source);

    // not included, Copy Assignment Operator
    MultiDimensionalPoint& operator=(const MultiDimensionalPoint& rhs);

    // Getter and Setter for a coordinate
    double getCoordinate(int x) const;
    void setCoordinate(int x, double value);

    // Get the number of dimensions
    int getNumberOfDimensions() const;

    // Print function
    void print() const;

    // Distance functions
    double euclideanDistance(const MultiDimensionalPoint& rhs) const;
    double manhattanDistance(const MultiDimensionalPoint& rhs) const;

    // Calculations on dimensions
    double averageOfDimensions() const;
    double sumOfDimensions() const;

    // Max dimension
    double* maxDimension();

    // Closest point functions
    MultiDimensionalPoint closestPoint(MultiDimensionalPoint* pointsArray,
                                       int numberOfPoints) const;
    MultiDimensionalPoint** kClosestPoints(MultiDimensionalPoint* pointsArray,
                                           int numberOfPoints, int k) const;
};

#endif
