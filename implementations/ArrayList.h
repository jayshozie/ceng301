#ifndef _Array_List_H_
#define _Array_List_H_

#include <stdexcept>
#include <sstream>
#include <iostream>

// ArrayList class implementing the List ADT using a dynamic array
class ArrayList {
private:
    int* arr;        // Pointer to the dynamic array
    int length;      // Current number of elements in the list
    int capacity;
public:
    ArrayList() : capacity(1), length(0) { // Constructor
        this->arr = new int[capacity]; // Initialize an empty dynamic array
    }
    ~ArrayList() { // Destructor
        delete[] this->arr; // Clean up the dynamic array
    }

    ArrayList(const ArrayList& rhs) : length(rhs.length), capacity(rhs.capacity){ // Copy constructor
        this->arr = new int[this->capacity]; // Create a new array
        for (int i = 0; i < this->length; i++) { // Copy elements
            this->arr[i] = rhs.arr[i];
        }
    }
    ArrayList& operator=(const ArrayList& rhs) { // Assignment operator
        if (this != &rhs) { // Self-assignment check
            if (this->capacity < rhs.length) {
                delete[] this->arr;
                this->arr = new int[rhs.capacity];
            }
            this->capacity = rhs.capacity; // Copy the capacity
            this->length = rhs.length; // Copy the length
            for (int i = 0; i < this->length; i++) { // Copy elements
                this->arr[i] = rhs.arr[i];
            }
        }
        return *this; // Return the current object
    }
    void add(int value, int index = -1) { // Add an element at a specific index
        if (index == -1) { // default value to append
            index = this->length;
        }
        if (index < 0 || index > this->length) { // Check for valid index
            std::stringstream ss;
            ss << "Error: " << index << " is out of bounds: " << "[0, " << this->length << "]" << std::endl;
            throw std::out_of_range(ss.str()); // Error handling
        }
        if (this->length >= this->capacity) { // not enough capacity
            int newCapacity = (this->capacity == 0) ? 1 : this->capacity * 2;
            int* newArr = new int[newCapacity]; // Create a new array with increased size
            for (int i = 0; i < index; i++) { // Copy elements before the index
                newArr[i] = this->arr[i];
            }
            newArr[index] = value; // Insert the new element at the specified index
            for (int i = index; i < this->length; i++) { // Copy remaining elements
                newArr[i + 1] = this->arr[i];
            }
            delete[] this->arr; // Delete the old array
            this->arr = newArr; // Point to the new array
            this->capacity = newCapacity;
        }
        else { // enough capacity
            for (int i = this->length; i > index; i--) {
                this->arr[i] = this->arr[i - 1];
            }
            this->arr[index] = value;
        }
        this->length++;
    }
    int lookup_value(int value) {
        for (int i = 0; i < this->length; i++) {
            if (this->arr[i] == value) {
                return i;
            }
        }
        std::stringstream ss;
        ss << "Error: " << value << " is not in the list." << std::endl;
        throw std::out_of_range(ss.str());
    }
    int lookup_index(int index) { // Get the element at a specific index
        if (index < 0 || index >= this->length) { // Check for valid index
            std::stringstream ss;
            ss << "Error: Lookup index " << index << " is out of bounds. Valid range: " << "[0, " << this->length - 1<< "]" << std::endl;
            throw std::out_of_range(ss.str()); // Error handling
        }
        return this->arr[index]; // Return the element at the given index
    }
    void set(int value, int index) { // Set the element at a specific index
        if (index < 0 || index >= this->length) { // Check for valid index
            std::stringstream ss;
            ss << "Error: Set index " << index << " is out of bounds. Valid range: " << "[0, " << this->length - 1<< "]" << std::endl;
            throw std::out_of_range(ss.str()); // Error handling
        }
        this->arr[index] = value; // Set the element at the given index
    }
    void remove_value(int value) {
        int index = lookup_value(value);
        remove_index(index);
    }
    void remove_index(int index) { // Remove the element at a specific index
        if (index < 0 || index >= this->length) { // Check for valid index
            std::stringstream ss;
            ss << "Error: Removal index " << index << " is out of bounds. Valid range: " << "[0, " << this->length - 1 << "]" << std::endl;
            throw std::out_of_range(ss.str()); // Error handling
        }
        for (int i = index; i < this->length - 1; i++) { // Shift elements to the left
            this->arr[i] = this->arr[i + 1];
        }
        this->length--; // Decrease the size
    }
    int size() { // Get the current size of the list
        return this->length; // Return the number of elements
    }
    void print() { // Print the contents of the list
        for (int i = 0; i < this->length; i++) { // Iterate through the elements
            std::cout << this->arr[i] << " "; // Print each element
        }
        std::cout << std::endl; // New line after printing all elements
    }
};

#endif
