
/*
Implement this header in a separate .cpp file.

#ifndef MULTIDIMENSIONALPOINT_H
#define MULTIDIMENSIONALPOINT_H

class MultiDimensionalPoint {
private:
    int dimension;
    int* coordinates;

public:
    // Constructor and Destructor
    MultiDimensionalPoint(int dim);
    ~MultiDimensionalPoint();

    // Copy constructor
    MultiDimensionalPoint(const MultiDimensionalPoint& other);

    // Getter and Setter for a coordinate
    double getCoordinate(int x) const;
    void setCoordinate(int x, double value);

    // Get the number of dimensions
    int getNumberOfDimensions() const;

    // Print function
    void print() const;

    // Distance functions
    double euclideanDistance(const MultiDimensionalPoint& other) const;
    double manhattanDistance(const MultiDimensionalPoint& other) const;

    // Calculations on dimensions
    double averageOfDimensions() const;
    double sumOfDimensions() const;

    // Max dimension
    int* maxDimension();

    // Closest point functions
    MultiDimensionalPoint closestPoint(MultiDimensionalPoint* pointsArray, int numberOfPoints) const;
    MultiDimensionalPoint** kClosestPoints(MultiDimensionalPoint* pointsArray, int numberOfPoints, int k) const;
};

#endif
*/

#include "MultiDimensionalPoint.h"
#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Constructor to initialize a point with a given number of dimensions.
// It allocates memory dynamically for coordinates based on the given dimensions.
MultiDimensionalPoint::MultiDimensionalPoint(int dim){
    // YOUR CODE GOES HERE
}

// Destructor to clean up the dynamically allocated memory for coordinates.
MultiDimensionalPoint::~MultiDimensionalPoint() {
    // YOUR CODE GOES HERE
}

// Copy constructor - creates a new MultiDimensionalPoint by copying another point.
// It ensures that the copied point has its own memory for coordinates.
MultiDimensionalPoint::MultiDimensionalPoint(const MultiDimensionalPoint& other) {
    // YOUR CODE GOES HERE
}

// Getter function to retrieve the coordinate value at a given dimension (index).
double MultiDimensionalPoint::getCoordinate(int x) const {
    // YOUR CODE GOES HERE
}

// Setter function to modify the coordinate value at a given dimension (index).
void MultiDimensionalPoint::setCoordinate(int x, double value) {
    // YOUR CODE GOES HERE
}

// Function to return the number of dimensions of the point.
int MultiDimensionalPoint::getNumberOfDimensions() const {
    // YOUR CODE GOES HERE
}

// Function to print the coordinates of the point.
// Prints each coordinate with a space in between, except for the last one.
void MultiDimensionalPoint::print() const {
    // YOUR CODE GOES HERE
}

// Function to calculate the Euclidean distance between this point and another point.
// The Euclidean distance formula is: sqrt((x1-x2)^2 + (y1-y2)^2 + ...)
double MultiDimensionalPoint::euclideanDistance(const MultiDimensionalPoint& other) const {
    // YOUR CODE GOES HERE
}

// Function to calculate the Manhattan distance between this point and another point.
// The Manhattan distance formula is: |x1 - x2| + |y1 - y2| + ...
double MultiDimensionalPoint::manhattanDistance(const MultiDimensionalPoint& other) const {
    // YOUR CODE GOES HERE
}

// Function to calculate the average of the coordinates of this point.
double MultiDimensionalPoint::averageOfDimensions() const {
    // YOUR CODE GOES HERE
}

// Function to calculate the sum of all coordinates of this point.
double MultiDimensionalPoint::sumOfDimensions() const {
    // YOUR CODE GOES HERE
}

// Function to find the maximum value among the coordinates of the point.
// Returns a pointer to the coordinate with the maximum value.
int* MultiDimensionalPoint::maxDimension() {
    // YOUR CODE GOES HERE
}

// Function to find the closest point to the current point from an array of points
MultiDimensionalPoint MultiDimensionalPoint::closestPoint(MultiDimensionalPoint* pointsArray, int numberOfPoints) const {
    // YOUR CODE GOES HERE
}


// Function to find the k closest points to the current point.
// Points are provided as an array, and k is the number of closest points to find.
MultiDimensionalPoint** MultiDimensionalPoint::kClosestPoints(MultiDimensionalPoint* pointsArray, int numberOfPoints, int k) const {
    // YOUR CODE GOES HERE
}
