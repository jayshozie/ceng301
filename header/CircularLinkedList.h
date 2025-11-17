// CircularLinkedList.h
#ifndef _Circular_Doubly_Linked_List_H_
#define _Circular_Doubly_Linked_List_H_
#include <iostream>
#include <sstream>
#include <stdexcept>

// TODO: IMPLEMENT, THIS TEMPLATE IS STILL A SINGLY LINKED LIST, AND NOT
// CIRCULAR

template<class T> class ListNode {
public:
    T data; // Data part of the node
    ListNode<T>* next; // Pointer to the next node
    ListNode<T>(T value): data(value), next(nullptr) {} // Constructor for nodes
    ListNode<T>(T value, ListNode<T>* ptr)
        : data(value), next(ptr) {} // Constructor with next pointer
};

template<class T> class CircularDoublyLinkedList {
private:
    ListNode<T>* head; // Pointer to the first node in the list
    int length; // Current number of elements in the list
public:
    CircularDoublyLinkedList(): head(nullptr), length(0) {} // Constructor
    ~CircularDoublyLinkedList(); // Destructor
    CircularDoublyLinkedList(
        const CircularDoublyLinkedList& rhs); // Copy Constructor
    CircularDoublyLinkedList&
    operator=(const CircularDoublyLinkedList& rhs); // Copy Assignment Operator
    void add(T value, int index = -1);
    int lookup_value(T value) const;
    T lookup_index(int index) const;
    void set(T value, int index);
    void remove_value(T value);
    void remove_index(int index);
    int size() const;
    void print() const;
    bool isEmpty() const;
    // T getHead() const; can be used for StackListADT.h
};

template<class T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() // Destructor
{
    ListNode<T>* current = this->head;
    while(current != nullptr) { // Traverse the list and delete nodes
        ListNode<T>* nextNode = current->next; // Store the next node
        delete current; // Delete the current node
        current = nextNode; // Move to the next node
    }
    // After this, head is automatically cleaned up as it's a pointer
}
template<class T> CircularDoublyLinkedList<T>::CircularDoublyLinkedList(
    const CircularDoublyLinkedList<T>& rhs)
    : head(nullptr), length(0)
{
    ListNode<T>* current = rhs.head; // Pointer to traverse the original list
    while(current != nullptr) { // Traverse the rhs list
        this->add(current->data); // Add each element to the new list
        current = current->next;
    }
} // copy constructor
template<class T> CircularDoublyLinkedList<T>&
CircularDoublyLinkedList<T>::operator=(const CircularDoublyLinkedList<T>& rhs)
{
    if(this != &rhs) { // Self-assignment check
        // Clear the current list
        ListNode<T>* current = this->head;
        while(current != nullptr) {
            ListNode<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        this->head = nullptr;
        this->length = 0;
        // Copy elements from rhs
        current = rhs.head;
        while(current != nullptr) {
            this->add(current->data);
            current = current->next;
        }
    }
    return *this; // Return the current object
}
template<class T> void CircularDoublyLinkedList<T>::add(T value, int index)
{ // Add an element at a specific index, we'll use the second constructor
    if(index == -1) { // default value to append
        index = this->length;
    } // fixes index = -1
    if(index < 0 || index > this->length) { // -1 index is not included
        std::stringstream errStr;
        errStr << "Error: " << index << " is out of bounds: " << "[0, "
               << this->length << "]" << std::endl;
        throw std::out_of_range(errStr.str()); // Error handling
    }
    // if (this->length == 0) {
    //     this->head = new ListNode<T>(value, this->head);
    // }

    // insertion logic
    if(index == 0) { // insert at head
        // head is new node with value value, next this->head
        this->head = new ListNode<T>(value, this->head);
    }
    else {
        ListNode<T>* current = this->head;
        for(int i = 0; i < index - 1; i++) { current = current->next; }
        ListNode<T>* newNode = new ListNode<T>(value, current->next);
        current->next = newNode;
    }
    this->length++;
}
template<class T> int CircularDoublyLinkedList<T>::lookup_value(T value) const
{
    ListNode<T>* current = this->head;
    int i = 0;
    while(current != nullptr) {
        if(value == current->data) { return i; }
        else {
            current = current->next;
            i++; // this case doesn't need a return val
        }
    }
    std::stringstream errStr;
    errStr << "Error: " << value << " is not in the list." << std::endl;
    throw std::invalid_argument(errStr.str());
}
template<class T> T CircularDoublyLinkedList<T>::lookup_index(int index) const
{ // Get the element at a specific index
    // get func via index logic
    if(index == -1) { index = this->length - 1; }
    if(index < 0 || index >= this->length) { // Check for valid index
        std::stringstream errStr;
        errStr << "Error: Lookup index " << index
               << " is out of bounds. Valid range: " << "[0, "
               << this->length - 1 << "]" << std::endl;
        throw std::out_of_range(errStr.str()); // Error handling
    }
    ListNode<T>* current = this->head;
    for(int i = 0; i < index; i++) { // Traverse to the index
        current = current->next;
    }
    return current->data; // Return the data at the given index
}
template<class T> void CircularDoublyLinkedList<T>::set(T value, int index)
{ // Set the element at a specific index
    if(index == -1) { index = this->length - 1; }
    if(index < 0 || index >= this->length) { // Check for valid index
        std::stringstream errStr;
        errStr << "Error: Set index " << index
               << " is out of bounds. Valid range: " << "[0, "
               << this->length - 1 << "]" << std::endl;
        throw std::out_of_range(errStr.str()); // Error handling
    }
    ListNode<T>* current = this->head;
    for(int i = 0; i < index; i++) { // Traverse to
        current = current->next;
    }
    current->data = value; // Set the data at the given index
}
template<class T> void CircularDoublyLinkedList<T>::remove_value(T value)
{ // tbf, i'd prefer to implement this member function without using others
    int index = this->lookup_value(value);
    this->remove_index(index);
}
template<class T> void CircularDoublyLinkedList<T>::remove_index(int index)
{ // Remove the element at a specific index
    if(index == -1) { index = this->length - 1; }
    if(index < 0 || index >= this->length) { // Check for valid index
        std::stringstream errStr;
        errStr << "Error: Removal index " << index
               << " is out of bounds. Valid range: " << "[0, "
               << this->length - 1 << "]" << std::endl;
        throw std::out_of_range(errStr.str()); // Error handling
    }
    if(index == 0) { // Remove the head
        ListNode<T>* temp = this->head;
        this->head = head->next;
        delete temp;
    }
    else {
        ListNode<T>* current = this->head;
        for(int i = 0; i < index - 1; i++) { current = current->next; }
        ListNode<T>* temp = current->next;
        current->next = temp->next; // Bypass the node to be removed
        delete temp;
    }
    this->length--; // Decrease the size
}
template<class T> int CircularDoublyLinkedList<T>::size() const
{ // Get the current size of the list
    return this->length; // Return the number of elements
}
template<class T> void CircularDoublyLinkedList<T>::print() const
{ // Print the contents of the list
    ListNode<T>* current = this->head;
    while(current != nullptr) { // Traverse through the list
        std::cout << current->data << " "; // Print each element
        current = current->next;
    }
    std::cout << std::endl; // New line after printing all elements
}
template<class T> bool CircularDoublyLinkedList<T>::isEmpty() const
{
    return this->length == 0;
}

// Test Cases: No errors left
// int main()
// {
//     CircularDoublyLinkedList* listA = new CircularDoublyLinkedList();
//     listA->add(10);
//     listA->add(11);
//     listA->add(21);
//     listA->print();
//     listA->remove_at_index(2);
//
//     // CircularDoublyLinkedList* listB = new
//     CircularDoublyLinkedList(*listA);
//     // or
//     CircularDoublyLinkedList* listB = new CircularDoublyLinkedList();
//     *listB = *listA;
//     listB->remove_the_value(10);
//
//     // use copy constructor with a new list listC
//     CircularDoublyLinkedList* listC = new CircularDoublyLinkedList(*listA);
//     listC->print();
//
//     delete listA;
//     listB->print();
//     delete listB;
// }

#endif
