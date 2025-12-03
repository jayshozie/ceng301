// MultiDimensionalPoint.cpp
#include "MultiDimensionalPoint.h"

// Constructor to initialize a point with a given number of dimensions.
// It allocates memory dynamically for coordinates based on the given
// dimensions.
MultiDimensionalPoint::MultiDimensionalPoint(int dim)
    : dimension(dim), coordinates(new double[dim])
{}

// Destructor to clean up the dynamically allocated memory for coordinates.
MultiDimensionalPoint::~MultiDimensionalPoint()
{
    delete[] this->coordinates;
    this->coordinates = nullptr;
}

// Copy constructor - creates a new MultiDimensionalPoint by copying another
// point. It ensures that the copied point has its own memory for coordinates.
MultiDimensionalPoint::MultiDimensionalPoint(
    const MultiDimensionalPoint& source)
    : dimension(source.dimension)
{
    this->coordinates = new double[this->dimension];

    for(int i = 0; i < this->dimension; i++) {
        this->coordinates[i] = source.coordinates[i];
    }
}

// not included, but copy assignment operator
MultiDimensionalPoint&
MultiDimensionalPoint::operator=(const MultiDimensionalPoint& rhs)
{
    // self-assignment check
    if(this != &rhs) {
        double* tmp = new double[rhs.dimension];

        for(int i = 0; i < rhs.dimension; i++) { tmp[i] = rhs.coordinates[i]; }

        delete[] this->coordinates;
        this->dimension = rhs.dimension;
        this->coordinates = tmp;
    }
    return *this;
}

// Getter function to retrieve the coordinate value at a given dimension
// (index).
double MultiDimensionalPoint::getCoordinate(int x) const
{
    return this->coordinates[x];
}

// Setter function to modify the coordinate value at a given dimension (index).
void MultiDimensionalPoint::setCoordinate(int x, double value)
{
    if(x < 0 || x >= this->dimension) {
        std::stringstream errStr;
        errStr << "ERR:: " << x << " is out of range. Valid range: [0, "
               << this->dimension - 1 << "]" << std::endl;
        throw std::out_of_range(errStr.str());
    }
    this->coordinates[x] = value;
}

// Function to return the number of dimensions of the point.
int MultiDimensionalPoint::getNumberOfDimensions() const
{
    return this->dimension;
}

// Function to print the coordinates of the point.
// Prints each coordinate with a space in between, except for the last one.
void MultiDimensionalPoint::print() const
{
    for(int i = 0; i < this->dimension; i++) {
        std::cout << this->coordinates[i] << ' ';
    }
    std::cout << std::endl;
}

// Function to calculate the Euclidean distance between this point and another
// point. The Euclidean distance formula is: sqrt((x1-x2)^2 + (y1-y2)^2 + ...)
double
MultiDimensionalPoint::euclideanDistance(const MultiDimensionalPoint& rhs) const
{
    // their dimensions must match
    if(this->dimension != rhs.dimension) {
        std::stringstream errStr;
        errStr << "ERR: Dimensions don't match: " << this->dimension
               << " != " << rhs.dimension << std::endl;
        throw std::out_of_range(errStr.str());
    }
    double total = 0;
    for(int i = 0; i < this->dimension; i++) {
        double diff = rhs.coordinates[i] - this->coordinates[i];
        total += pow(diff, 2);
    }
    return sqrt(total);
}

// Function to calculate the Manhattan distance between this point and another
// point. The Manhattan distance formula is: |x1 - x2| + |y1 - y2| + ...
double
MultiDimensionalPoint::manhattanDistance(const MultiDimensionalPoint& rhs) const
{
    // their dimensions must match
    if(this->dimension != rhs.dimension) {
        std::stringstream errStr;
        errStr << "ERR: Dimensions don't match: " << this->dimension
               << " != " << rhs.dimension << std::endl;
        throw std::out_of_range(errStr.str());
    }
    double total = 0;
    for(int i = 0; i < this->dimension; i++) {
        double tmp_diff = rhs.coordinates[i] - this->coordinates[i];
        if(tmp_diff < 0) { tmp_diff *= -1; }
        total += tmp_diff;
    }
    return total;
}

// Function to calculate the average of the coordinates of this point.
double MultiDimensionalPoint::averageOfDimensions() const
{
    double total = 0;
    for(int i = 0; i < this->dimension; i++) { total += this->coordinates[i]; }
    double average = total / this->dimension;
    return average;
}

// Function to calculate the sum of all coordinates of this point.
double MultiDimensionalPoint::sumOfDimensions() const
{
    double sum = 0;
    for(int i = 0; i < this->dimension; i++) { sum += this->coordinates[i]; }
    return sum;
}

// Function to find the maximum value among the coordinates of the point.
// Returns a pointer to the coordinate with the maximum value.
double* MultiDimensionalPoint::maxDimension()
{
    double max = 0;
    double* max_ptr;
    for(int i = 0; i < this->dimension; i++) {
        if(this->coordinates[i] >= max) {
            max = this->coordinates[i];
            max_ptr = &this->coordinates[i];
        }
    }
    return max_ptr;
    // doesn't make sense at all
}

// Function to find the closest point to the current point from an array of
// points
MultiDimensionalPoint
MultiDimensionalPoint::closestPoint(MultiDimensionalPoint* pointsArray,
                                    int numberOfPoints) const
{
    double min = MAXFLOAT;
    MultiDimensionalPoint* closest;
    for(int i = 0; i < numberOfPoints; i++) {
        double distance = this->euclideanDistance(pointsArray[i]);
        if(distance < min) {
            min = distance;
            closest = &pointsArray[i];
        }
    }
    return *closest;
}

// TODO: IMPLEMENT THIS
// Function to find the k closest points to the current point.
// Points are provided as an array, and k is the number of closest points to
// find.
MultiDimensionalPoint**
MultiDimensionalPoint::kClosestPoints(MultiDimensionalPoint* pointsArray,
                                      int numberOfPoints, int k) const
{
    if(numberOfPoints < k) {
        std::stringstream errStr;
        errStr << "ERR: Not enough points: " << numberOfPoints << " < " << k
               << std::endl;
        throw std::out_of_range(errStr.str());
    }
    else {
        MultiDimensionalPoint** retPtrArr = new MultiDimensionalPoint*[k];
        if(numberOfPoints == k) {
            for(int i = 0; i < k; i++) {
                retPtrArr[i] = new MultiDimensionalPoint(pointsArray[i]);
            }
            return retPtrArr;
        }
        else {
            double distances[numberOfPoints];
            int indices[numberOfPoints];

            for(int i = 0; i < numberOfPoints; i++) {
                distances[i] = this->euclideanDistance(pointsArray[i]);
                indices[i] = i;
            }

            // sort both arrays by sorting array distances
            for(int i = 0; i < k; i++) {
                int minIndex = i;
                for(int j = i + 1; j < numberOfPoints; j++) {
                    if(distances[j] < distances[minIndex]) { minIndex = j; }
                }
                if(minIndex != i) {
                    double tmpDist = distances[i];
                    distances[i] = distances[minIndex];
                    distances[minIndex] = tmpDist;

                    int tmpIndex = indices[i];
                    indices[i] = indices[minIndex];
                    indices[minIndex] = tmpIndex;
                }
            } // sorted

            // fill retPtrArr
            for(int j = 0; j < k; j++) {
                retPtrArr[j]
                    = new MultiDimensionalPoint(pointsArray[indices[j]]);
            }
            return retPtrArr;
        }
    }
}
