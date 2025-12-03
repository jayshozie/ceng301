// Queue.h
// linked list implementation
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "QException.h"

template<class T> class QNode {
public:
    T value;
    QNode* next;
    QNode(const T& e = T(), QNode* n = nullptr): value(e), next(n) {};
};

template<class T> class Queue {
private:
    QNode<T>* back;
    QNode<T>* front;
    int count;
public:
    Queue(); // default constructor
    ~Queue(); // destructor
    Queue(const Queue& rhs); // copy constructor
    Queue& operator=(const Queue& rhs); // copy assignment operator

    void enqueue(const T& value);
    T dequeue();
    T peek() const;
    int size() const;
    bool isEmpty() const;
};

template<class T> Queue<T>::Queue(): back(nullptr), front(nullptr), count(0) {}
template<class T> Queue<T>::~Queue()
{
    while(!isEmpty()) { dequeue(); }
}
template<class T> Queue<T>::Queue(const Queue<T>& rhs)
    : front(nullptr), back(nullptr), count(0)
{
    QNode<T>* reader = rhs.front;
    while(reader != nullptr) {
        this->enqueue(reader->value);
        reader = reader->next;
    }
}
template<class T> Queue<T>& Queue<T>::operator=(const Queue<T>& rhs)
{
    if(this != &rhs) {
        while(!isEmpty()) { this->dequeue(); }
        QNode<T>* reader = rhs.front;
        while(reader != nullptr) {
            this->enqueue(reader->value);
            reader = reader->next;
        }
    }
    return *this;
}
template<class T> void Queue<T>::enqueue(const T& value)
{
    // create new node
    QNode<T>* newItem = new QNode<T>(value);

    // insert new node
    if(this->isEmpty()) { this->front = newItem; } // empty queue
    else {
        this->back->next = newItem;
    } // nonempty queue
    this->back = newItem; // new node is at back
    this->count++; // +1 count
}
template<class T> T Queue<T>::dequeue()
{
    if(this->isEmpty()) { // queue is empty
        std::stringstream errStr;
        errStr << "Error: Empty queue, cannot dequeue." << std::endl;
        throw QException(errStr);
    }
    else { // queue is not empty
        QNode<T>* tmpPtr = this->front;
        T qFront = this->front->value;
        if(this->front == this->back) { // one node is in queue
            this->front = nullptr;
            this->back = nullptr;
        }
        else { // multiple node is in queue
            this->front = this->front->next;
        }
        tmpPtr->next = nullptr;
        delete tmpPtr;
        count--;
        return qFront;
    }
}
template<class T> T Queue<T>::peek() const
{
    if(isEmpty()) {
        std::stringstream errStr;
        errStr << "Error: Empty queue, cannot peek." << std::endl;
        throw QException(errStr);
    }
    else {
        return this->front->value;
    }
}
template<class T> int Queue<T>::size() const
{
    return this->count;
}
template<class T> bool Queue<T>::isEmpty() const
{
    return this->back == nullptr;
    // or return this->count == 0
}

#endif // _QUEUE_H_

// TEST
// Copy the rest to a different .cpp file.
// #include "Queue.h" // Assuming your Queue.h is the final, corrected version
// #include <iostream>
// #include <stdexcept>
// #include <sstream>
//
// // Helper to run a test and print the result
// #define RUN_TEST(testName, expression) \
//     std::cout << (expression ? "[PASS] " : "[FAIL] ") << testName <<
//     std::endl;
//
// // --- Test Suite ---
//
// void test_initial_state() {
//     std::cout << "\n--- Test 1: Initial State & Empty Queue ---" <<
//     std::endl; Queue<int> q;
//
//     // Test 1.1: Is empty initially?
//     RUN_TEST("1.1 isEmpty() on new queue", q.isEmpty());
//
//     // Test 1.2: Size is zero?
//     RUN_TEST("1.2 size() is 0", q.size() == 0);
//
//     // Test 1.3: Peek/Dequeue throws exception on empty queue
//     try {
//         q.peek();
//         RUN_TEST("1.3 Peek throws exception", false);
//     } catch (const QException& e) {
//         RUN_TEST("1.3 Peek throws exception", true);
//     }
// }
//
// void test_enqueue_dequeue() {
//     std::cout << "\n--- Test 2: Enqueue and Dequeue (FIFO) ---" << std::endl;
//     Queue<std::string> q;
//
//     // Enqueue 3 items
//     q.enqueue("First");
//     q.enqueue("Second");
//     q.enqueue("Third");
//
//     // Test 2.1: Size after 3 enqueues
//     RUN_TEST("2.1 Size after 3 items", q.size() == 3);
//
//     // Test 2.2: Peek returns the correct 'Front' item
//     RUN_TEST("2.2 peek() returns 'First'", q.peek() == "First");
//
//     // Test 2.3: Dequeue removes and returns the first item (FIFO)
//     RUN_TEST("2.3 dequeue() returns 'First'", q.dequeue() == "First");
//
//     // Test 2.4: Size decreases after dequeue
//     RUN_TEST("2.4 Size is 2 after dequeue", q.size() == 2);
//
//     // Test 2.5: Front updates correctly
//     RUN_TEST("2.5 New peek() returns 'Second'", q.peek() == "Second");
//
//     // Dequeue remaining items
//     q.dequeue();
//     q.dequeue();
//
//     // Test 2.6: Queue is empty after all items are removed
//     RUN_TEST("2.6 Queue is empty after all dequeues", q.isEmpty());
//
//     // Test 2.7: Dequeueing an empty queue throws exception
//     try {
//         q.dequeue();
//         RUN_TEST("2.7 Dequeue throws exception", false);
//     } catch (const QException& e) {
//         RUN_TEST("2.7 Dequeue throws exception", true);
//     }
// }
//
// void test_one_node_case() {
//     std::cout << "\n--- Test 3: One-Node Queue State (Front == Back) ---" <<
//     std::endl; Queue<char> q; q.enqueue('X');
//
//     // Test 3.1: Size is 1
//     RUN_TEST("3.1 Size is 1", q.size() == 1);
//
//     // Test 3.2: Dequeue correctly clears both front and back pointers
//     q.dequeue();
//
//     // Test 3.3: Queue is empty
//     RUN_TEST("3.3 Queue is empty after 1-node dequeue", q.isEmpty());
//
//     // Test 3.4: Re-enqueue works after clearing (check for dangling back
//     pointer) q.enqueue('Y'); RUN_TEST("3.4 Re-enqueue works", q.peek() ==
//     'Y');
// }
//
// void test_rule_of_three() {
//     std::cout << "\n--- Test 4: Rule of Three (Memory Safety/Deep Copy) ---"
//     << std::endl;
//
//     Queue<double> q1;
//     q1.enqueue(1.1);
//     q1.enqueue(2.2);
//     q1.enqueue(3.3);
//
//     // 4.1 Test Copy Assignment Operator (q2 = q1)
//     Queue<double> q2;
//     q2.enqueue(99.9); // Initial element for q2 (will be deleted)
//     q2 = q1; // Call to operator=
//
//     // Test 4.1.1: New size is correct
//     RUN_TEST("4.1.1 Assignment: Size is 3", q2.size() == 3);
//
//     // Test 4.1.2: Check if q2 has correct data
//     RUN_TEST("4.1.2 Assignment: Data is correct (1.1)", q2.peek() == 1.1);
//
//     // **CRITICAL TEST 1: Independence**
//     // Modify q1 and ensure q2 is untouched.
//     q1.dequeue(); // q1 is now [2.2, 3.3]
//     RUN_TEST("4.1.3 INDEPENDENCE: q2 front still 1.1", q2.peek() == 1.1);
//
//     // 4.2 Test Copy Constructor (q3(q2))
//     Queue<double> q3 = q2; // Call to Copy Constructor
//
//     // Test 4.2.1: New size is correct
//     RUN_TEST("4.2.1 Constructor: Size is 3", q3.size() == 3);
//
//     // **CRITICAL TEST 2: Memory Safety**
//     // q2 goes out of scope here (if this were a function), but since they
//     are in main,
//     // we use dequeue to simulate memory release, ensuring q3 still works.
//     q2.dequeue();
//     q2.dequeue();
//     q2.dequeue(); // q2 is now empty, its memory is deleted.
//
//     // Test 4.2.2: q3 must still contain its independent data (Deep Copy
//     check) RUN_TEST("4.2.2 SAFETY: q3 still has data (1.1)", q3.peek()
//     == 1.1);
//
//     // If the program reaches the end of main without a 'double free', the
//     destructor/copy ops are safe.
// }
//
// int main() {
//     test_initial_state();
//     test_enqueue_dequeue();
//     test_one_node_case();
//     test_rule_of_three();
//
//     std::cout << "\n--- Test Suite Complete ---" << std::endl;
//     return 0;
// }
