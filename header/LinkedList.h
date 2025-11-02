#ifndef _Linked_List_H_
#define _Linked_List_H_

#include <iostream>
#include <sstream>
#include <stdexcept>

class ListNode {
public:
    int data; // Data part of the node
    ListNode* next; // Pointer to the next node
    ListNode(int value) : data(value), next(nullptr) {} // Constructor for nodes
    ListNode(int value, ListNode* ptr) : data(value), next(ptr) {} // Constructor with next pointer
};

class LinkedIntList {
private:
    ListNode* head; // Pointer to the first node in the list
    int length; // Current number of elements in the list
public:
    LinkedIntList() : head(nullptr), length(0) {} // Constructor
    ~LinkedIntList() { // Destructor
        ListNode* current = this->head;
        while (current != nullptr) { // Traverse the list and delete nodes
            ListNode* nextNode = current->next; // Store the next node
            delete current; // Delete the current node
            current = nextNode; // Move to the next node
        }
        // After this, head is automatically cleaned up as it's a pointer
    }
    LinkedIntList(const LinkedIntList& rhs) { // Copy constructor
        this->head = nullptr; // Start with an empty list
        this->length = 0; // Start with size 0
        ListNode* current = rhs.head; // Pointer to traverse the original list
        while (current != nullptr) { // Traverse the rhs list
            this->add(current->data); // Add each element to the new list
            current = current->next;
        }
    }
    LinkedIntList& operator=(const LinkedIntList& rhs) {
        if (this != &rhs) { // Self-assignment check
            // Clear the current list
            ListNode* current = this->head;
            while (current != nullptr) {
                ListNode* nextNode = current->next;
                delete current;
                current = nextNode;
            }
            this->head = nullptr;
            this->length = 0;
            // Copy elements from rhs
            current = rhs.head;
            while (current != nullptr) {
                add(current->data);
                current = current->next;
            }
        }
        return *this; // Return the current object
    }
    // void add(int value) { // Add an element to the end of the list
    //     // We will use the second constructor
    //     ListNode* newNode = new ListNode(value); // Create a new node
    //     if (head == nullptr) { // If the list is empty
    //         head = newNode; // New node becomes the head
    //     }
    //     else {
    //         ListNode* current = head;
    //         while (current->next != nullptr) { // Traverse to the end of the list
    //             current = current->next;
    //         }
    //         current->next = newNode; // Link the new node at the end
    //     }
    //     length++; // Increase the size
    // }
    void add(int value, int index = -1) { // Add an element at a specific index, we'll use the second constructor
        if (index == -1) { // default value to append
            index = this->length;
        }

        if (index < 0 || index > this->length) { // error handling
            std::stringstream ss;
            ss << "Error: " << index << " is out of bounds: " << "[0, " << this->length << "]" << std::endl;
            throw std::out_of_range(ss.str()); // Error handling
        }
        // if (this->length == 0) {
        //     this->head = new ListNode(value, this->head);
        // }

        // insertion logic
        if (index == 0) { // insert at head
            this->head = new ListNode(value, this->head);
        }
        else {
            ListNode* current = this->head;
            for (int i = 0; i < index-1; i++) {
                current = current->next;
            }
            ListNode* newNode = new ListNode(value, current->next);
            current->next = newNode;
        }
        length++;
    }
    int lookup_value(int value) {
        ListNode* current = this->head;
        int i = 0;
        while (current != nullptr) {
            if (value == current->data) {
                return i;
            }
            else {
                current = current->next;
                i++; // this case doesn't need a return val
            }
        }
        std::stringstream ss;
        ss << "Error: " << value << " is not in the list." << std::endl;
        throw std::out_of_range(ss.str());
    }
    int lookup_index(int index) { // Get the element at a specific index
        // get func via index logic
        if (index < 0 || index >= length) { // Check for valid index
            std::stringstream ss;
            ss << "Error: Lookup index " << index << " is out of bounds. Valid range: " << "[0, " << this->length - 1<< "]" << std::endl;
            throw std::out_of_range(ss.str()); // Error handling
        }
        ListNode* current = head;
        for (int i = 0; i < index; i++) { // Traverse to the index
            current = current->next;
        }
        return current->data; // Return the data at the given index
    }
    void set(int value, int index) { // Set the element at a specific index
        if (index < 0 || index >= length) { // Check for valid index
            std::stringstream ss;
            ss << "Error: Set index " << index << " is out of bounds. Valid range: " << "[0, " << this->length - 1 << "]" << std::endl;
            throw std::out_of_range(ss.str()); // Error handling
        }
        ListNode* current = head;
        for (int i = 0; i < index; i++) { // Traverse to
            current = current->next;
        }
        current->data = value; // Set the data at the given index
    }
    void remove_value(int value) {
        int index = lookup_value(value);
        remove_index(index);
    }
    void remove_index(int index) { // Remove the element at a specific index
        if (index < 0 || index >= length) { // Check for valid index
            std::stringstream ss;
            ss << "Error: Removal index " << index << " is out of bounds. Valid range: " << "[0, " << this->length - 1 << "]" << std::endl;
            throw std::out_of_range(ss.str()); // Error handling
        }
        if (index == 0) { // Remove the head
            ListNode* temp = this->head;
            this->head = head->next;
            delete temp;
        }
        else {
            ListNode* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            ListNode* temp = current->next;
            current->next = temp->next; // Bypass the node to be removed
            delete temp;
        }
        length--; // Decrease the size
    }
    int size() { // Get the current size of the list
        return length; // Return the number of elements
    }
    void print() { // Print the contents of the list
        ListNode* current = head;
        while (current != nullptr) { // Traverse through the list
            std::cout << current->data << " "; // Print each element
            current = current->next;
        }
        std::cout << std::endl; // New line after printing all elements
    }
};

// Test Cases: No errors left
// int main()
// {
//     LinkedIntList* listA = new LinkedIntList();
//     listA->add(10);
//     listA->add(11);
//     listA->add(21);
//     listA->print();
//     listA->remove_at_index(2);
// 
//     // LinkedIntList* listB = new LinkedIntList(*listA);
//     // or
//     LinkedIntList* listB = new LinkedIntList();
//     *listB = *listA;
//     listB->remove_the_value(10);
// 
//     // use copy constructor with a new list listC
//     LinkedIntList* listC = new LinkedIntList(*listA);
//     listC->print();
// 
//     delete listA;
//     listB->print();
//     delete listB;
// }

#endif
