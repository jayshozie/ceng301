#include "Complex.h"
#include "MultiDimensionalPoint.h"
#include <iostream>

// Helper function to set coordinates (assuming a 'setCoordinate' method exists)
void setCoords(MultiDimensionalPoint& p, double c0, double c1, double c2)
{
    // Assuming your point dimension is 3 for this test
    p.setCoordinate(0, c0);
    p.setCoordinate(1, c1);
    p.setCoordinate(2, c2);
}

// Function to print a point and its distance to the center (for verification)
void printPointDetails(const MultiDimensionalPoint& center,
                       const MultiDimensionalPoint* p, int index)
{
    if(p) {
        double dist = center.euclideanDistance(*p);
        std::cout << "  [" << index << "] Point: (" << p->getCoordinate(0)
                  << ", " << p->getCoordinate(1) << ", " << p->getCoordinate(2)
                  << ") | Distance: " << dist << std::endl;
    }
    else {
        std::cout << "  [" << index << "] Point is NULL." << std::endl;
    }
}

int main()
{
    const int DIM = 3;
    const int NUM_POINTS = 10;
    const int K_CLOSEST = 3;

    // --- 1. Random Center Point (The *this object) ---
    // A point at the origin
    MultiDimensionalPoint centerPoint(DIM);
    setCoords(centerPoint, 0.0, 0.0, 0.0);

    std::cout << "--- Test Setup ---\n";
    std::cout << "Center Point (The *this object): ";
    centerPoint.print();

    // --- 2. MultiDimensionalPoint Array (The input array) ---
    // Dynamically allocate an array of 10 points
    MultiDimensionalPoint* pointsArray = new MultiDimensionalPoint[NUM_POINTS];
    for(int i = 0; i < NUM_POINTS; ++i) {
        pointsArray[i] = MultiDimensionalPoint(DIM);
    }

    // Initialize 10 points (where indices 0, 1, and 9 are the closest)
    // Distance calculation is based on sqrt(c0^2 + c1^2 + c2^2)

    // #1 (Closest) Distance: 1.0
    setCoords(pointsArray[0], 1.0, 0.0, 0.0);
    // #2 (Closest) Distance: 1.732
    setCoords(pointsArray[1], 1.0, 1.0, 1.0);
    // #3 Distance: 3.0
    setCoords(pointsArray[2], 3.0, 0.0, 0.0);
    // #4 Distance: 4.0
    setCoords(pointsArray[3], 4.0, 0.0, 0.0);
    // #5 Distance: 10.0
    setCoords(pointsArray[4], 10.0, 0.0, 0.0);
    // #6 Distance: 5.0
    setCoords(pointsArray[5], 0.0, 5.0, 0.0);
    // #7 Distance: 6.0
    setCoords(pointsArray[6], 6.0, 0.0, 0.0);
    // #8 Distance: 7.0
    setCoords(pointsArray[7], 0.0, 0.0, 7.0);
    // #9 Distance: 8.0
    setCoords(pointsArray[8], 8.0, 0.0, 0.0);
    // #10 (3rd Closest) Distance: 2.0
    setCoords(pointsArray[9], 2.0, 0.0, 0.0);

    // Expected closest points (based on distance):
    // 1st: pointsArray[0] (Dist 1.0)
    // 2nd: pointsArray[1] (Dist 1.732)
    // 3rd: pointsArray[9] (Dist 2.0)

    std::cout << "\nInput Array (Points being searched): \n";
    for(int i = 0; i < NUM_POINTS; ++i) {
        printPointDetails(centerPoint, &pointsArray[i], i);
    }

    // --- 3. Call kClosestPoints() and Test ---

    std::cout << "\n--- Testing kClosestPoints(Array, " << NUM_POINTS << ", "
              << K_CLOSEST << ") ---\n";

    // Call the function that returns a pointer-to-pointer
    // (MultiDimensionalPoint**)
    MultiDimensionalPoint** kResult
        = centerPoint.kClosestPoints(pointsArray, NUM_POINTS, K_CLOSEST);

    if(kResult == nullptr) {
        std::cout << "ERROR: kClosestPoints returned a nullptr. Cannot test "
                     "results.\n";
    }
    else {
        std::cout << "Result (Expected Indices 0, 1, 9):\n";
        for(int i = 0; i < K_CLOSEST; ++i) {
            // The result points should be ordered by distance if your sort is
            // correct
            printPointDetails(centerPoint, kResult[i], i);
        }
    }

    // --- 4. CRITICAL CLEANUP (Prevent Memory Leaks) ---

    // A. Clean up the array returned by kClosestPoints (2-level cleanup)
    if(kResult != nullptr) {
        std::cout << "\nCleaning up kResult array...\n";
        for(int i = 0; i < K_CLOSEST; ++i) {
            // Must delete the OBJECTS first (the second level of allocation)
            delete kResult[i];
            kResult[i] = nullptr; // Good practice
        }
        // Then, delete the array of POINTERS (the first level of allocation)
        delete[] kResult;
        kResult = nullptr;
    }

    // B. Clean up the input array
    std::cout << "Cleaning up input pointsArray...\n";
    delete[] pointsArray;

    return 0;
}
