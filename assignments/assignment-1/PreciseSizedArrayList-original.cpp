#include "PreciseSizedArrayList.h"
#include <iostream> // For printList and simulateJourney


#ifdef USE_STUDENT_CONSTRUCTOR_IMPL
/**
 * Constructor: Initializes an empty list.
 */
PreciseSizedArrayList::PreciseSizedArrayList()
{
    // YOUR CODE GOES HERE
}

#endif


#ifdef USE_STUDENT_DESTRUCTOR_IMPL
/**
 * Destructor: Frees (deletes) all dynamically allocated memory.
 */
PreciseSizedArrayList::~PreciseSizedArrayList()
{
    // YOUR CODE GOES HERE
}
#endif


#ifdef USE_STUDENT_ADD_IMPL
/**
 * Don't forget to dynamically reallocate a new array of size (size + 1) and finally update the size variable.
 */
void PreciseSizedArrayList::add(int index, int value)
{
    // YOUR CODE GOES HERE
}
#endif


#ifdef USE_STUDENT_REMOVE_IMPL
/**
 * Don't forget to dynamically reallocate a new array of size (size - 1), copy/shift the remaining elements, and finally update the size variable.
 */
void PreciseSizedArrayList::remove(int index)
{
    // YOUR CODE GOES HERE
}
#endif


#ifdef USE_STUDENT_CHANGE_IMPL
/**
 * Changes the value at a specific index.
 */
void PreciseSizedArrayList::changeValue(int index, int new_value)
{
    // YOUR CODE GOES HERE
}
#endif


#ifdef USE_STUDENT_REVERSE_IMPL
/**
 * Reverses the elements of the list.
 */
void PreciseSizedArrayList::reverse()
{
    // YOUR CODE GOES HERE
}
#endif

#ifdef USE_STUDENT_AVERAGE_IMPL
/**
 * Calculates the average of all values in the list.
 * Returns the average as a double, or 0.0 if the list is empty.
 */
double PreciseSizedArrayList::getAverageValue() const
{
    // YOUR CODE GOES HERE
}
#endif

#ifdef USE_STUDENT_JOURNEY_IMPL
/**
 * Simulates a "journey" by stepping through the array.
 * Example Output:
Step 0: A1 at 0, A2 at 0
Step 1: A1 at 1, A2 at 2
Step 2: A1 at 2, A2 at 4
Step 3: A1 at 3, A2 at 0
Step 4: A1 at 4, A2 at 2
Step 5: A1 at 5, A2 at 4
Step 6: A1 at 0, A2 at 0
 */
void PreciseSizedArrayList::simulateJourney(int step_one, int step_two) const
{
    // YOUR CODE GOES HERE
}

#endif


#ifdef USE_STUDENT_PRINT_IMPL
/**
 * Prints the entire list to the console.
 * Example:
Index: 0, Value: 42
Index: 1, Value: 30
Index: 2, Value: 20
Index: 3, Value: 15
Index: 4, Value: 10
 */
void PreciseSizedArrayList::printList() const
{
    // YOUR CODE GOES HERE
}

#endif
