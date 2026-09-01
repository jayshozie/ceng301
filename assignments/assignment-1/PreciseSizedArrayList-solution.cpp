#include "PreciseSizedArrayList.h"
#include <iostream>

#ifdef USE_STUDENT_CONSTRUCTOR_IMPL
/**
* Constructor: Initializes an empty list.
*/
PreciseSizedArrayList::PreciseSizedArrayList()
{
    this->data = nullptr;
    this->size = 0;
}
#endif
#ifdef USE_STUDENT_DESTRUCTOR_IMPL
/**
* Destructor: Frees (deletes) all dynamically allocated memory.
*/
PreciseSizedArrayList::~PreciseSizedArrayList()
{
    // regular destructor, nothing fancy
    if (this->data != nullptr) {
        delete[] this->data;
        this->data = nullptr;
    };
}
#endif
#ifdef USE_STUDENT_ADD_IMPL
/**
* Don’t forget to dynamically reallocate a new array of size (size + 1) and finally
update the size variable.
*/
void PreciseSizedArrayList::add(int index, int value)
{
    int actualIndex;
    
    // if the index is positive, the problem is already resolved
    if (index >= 0) { actualIndex = index; }

    // if the index is negative, we need to calculate the actual index
    // else if is redundant, because there isn't any other option, but i think
    // it makes the code easier to read
    else if (index < 0) { actualIndex = this->size + index + 1; }
    // resolved

    // check bounds, if one or both of the conditions are true, then' we're out of bounds
    if (actualIndex < 0 || actualIndex > this->size) {
        return;
    }

    // if not out of bounds, allocate a new array with the correct size value (size + 1)
    else {
        int newSize = this->size + 1;
        int* newData = new int[newSize];

        // copy elements and insert the value
        for (int i = 0; i < newSize; i++) {
            if (i < actualIndex) {
                newData[i] = data[i];
            }
            else if (i == actualIndex) {
                newData[i] = value;
            }
            else {
                newData[i] = data[i - 1];
            }
        }
        // deallocate the old array and update pointers
        if (this->data != nullptr) {
            delete[] this->data;
        }
        // update list' members
        this->data = newData;
        this->size = newSize;
    }
}
#endif
#ifdef USE_STUDENT_REMOVE_IMPL
/**
* Don’t forget to dynamically reallocate a new array of size (size - 1), copy/shift
the remaining elements, and finally update the size variable.
*/
void PreciseSizedArrayList::remove(int index)
{
    // empty list handler
    if (this->size == 0) {
        return;
    }

    // resolving index
    int actualIndex;
    if (index >= 0) {
        actualIndex = index;
    }
    // again, redundant check, but looks better
    else if (index < 0) {
        actualIndex = this->size + index;
    }

    if (actualIndex < 0 || actualIndex >= this->size) {
        return;
    }

    // handler for list becoming empty after removal
    if (this->size == 1) {
        // the list is not empty, but will be empty after execution.
        // delete the whole list
        if (this->data != nullptr) {
            delete[] this->data;
        }
        this->data = nullptr;
        this->size = 0;
        return;
    }

    // allocate new array
    int newSize = this->size - 1;
    int* newData = new int[newSize];

    for (int i = 0; i < newSize; i++) {
        if (i < actualIndex) {
            // copy elements before the removal point
            newData[i] = this->data[i];
        }
        else {
            newData[i] = this->data[i + 1];
        }
    }

    // deallocate the old array
    if (this->data != nullptr) {
        delete[] this->data;
    }

    // update the list's members
    this->data = newData;
    this->size = newSize;
}
#endif
#ifdef USE_STUDENT_CHANGE_IMPL
/**
* Changes the value at a specific index.
*/
void PreciseSizedArrayList::changeValue(int index, int new_value)
{
    // again, resolve the index issue
    int actualIndex;
    if (index >= 0) {
        actualIndex = index;
    }
    else if (index < 0) {
        actualIndex = this->size + index;
    }

    // out of bounds check
    if (actualIndex < 0 || actualIndex >= this->size) {
        return;
    }

    this->data[actualIndex] = new_value;
}
#endif
#ifdef USE_STUDENT_REVERSE_IMPL
/**
* Reverses the elements of the list.
*/
void PreciseSizedArrayList::reverse()
{
    // if size <= 1, no reverse can be done
    if (this->size <= 1) {
        return;
    }
    else {
        int lower = 0;
        int upper = this->size - 1;

        while (lower < upper) {
            // tmp var to not lose data
            int tmp = this->data[lower];
            this->data[lower] = this->data[upper];
            this->data[upper] = tmp;

            // closing the gap at each iter
            lower++;
            upper--;
        }
    }
}
#endif
#ifdef USE_STUDENT_AVERAGE_IMPL
/**
* Calculates the average of all values in the list.
* Returns the average as a double, or 0.0 if the list is empty.
*/
double PreciseSizedArrayList::getAverageValue() const
{
    if (this->size == 0) {
        return 0.0;
    }
    else {
        long long int sum = 0;
        for (int i = 0; i < this->size; i++) {
            sum += this->data[i];
            // calculating the total to divide
        }
        // nvm found a way to do it other than static_cast
        return (double)sum / (double)this->size;
        // i need to study old c++ standards more
    }
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
    if (this->size == 0) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    int k = 0;
    int idx1 = 0;
    int idx2 = 0;

    // Format:
    // Step {k}: A1 at {idx1}, A2 at {idx2}
    // initial step, step 0
    std::cout << "Step " << k << ": A1 at " << idx1 << ", A2 at " << idx2 << std::endl;
    while (true) {
        // start with step 1
        k++;
        
        // not sure if this works, but it should, i think
        idx1 = (idx1 + step_one) % this->size;
        idx2 = (idx2 + step_two) % this->size;

        // cout the step
        std::cout << "Step " << k << ": A1 at " << idx1 << ", A2 at " << idx2 << std::endl;

        // check if they're at the same index
        if (idx1 == idx2) {
            // if yes, break
            break;
        }
    }
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
    // Format:
    // Index: {i}, Value: {data}
    
    // iterate over all element
    for (int i = 0; i < this->size; i++) {
        // cout every element
        std::cout << "Index: " << i << ", Value: " << this->data[i] << std::endl;
    }
}
#endif
