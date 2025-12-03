// StackLinked.h
#ifndef _StackLinked_H_
#define _StackLinked_H_
#include "StackException.h"
#include <iostream>

template<class T> class StackNode {
public:
    T value;
    StackNode* next;
    StackNode(const T& value = T(), StackNode* next = nullptr)
        : value(value), next(next)
    {} // default constructor
};

template<class T> class StackLinked {
private:
    StackNode<T>* top;
public:
    StackLinked(); // default constructor
    ~StackLinked(); // destructor
    StackLinked(const StackLinked& rhs); // copy constructor
    StackLinked& operator=(const StackLinked& rhs); // copy assignment
    void push(const T& value);
    T pop();
    T peek() const;
    void print();
    void reverse();
    int size() const;
    bool isEmpty() const;
}; // definitions

template<class T> StackLinked<T>::StackLinked()
    : top(nullptr) {} // default constructor
template<class T> StackLinked<T>::~StackLinked()
{
    while(!this->isEmpty()) { this->pop(); }
} // destructor
template<class T> StackLinked<T>::StackLinked(const StackLinked& rhs)
    : top(nullptr)
{ // copy constructor
    if(rhs.top == nullptr) { return; }
    this->top = new StackNode<T>(rhs.top->value);
    StackNode<T>* reader = rhs.top->next;
    StackNode<T>* writer = this->top;
    while(reader != nullptr) { // if not reached end of stack
        // writer's next is new node w/ value of reader
        writer->next = new StackNode<T>(reader->value);
        // writer->next->next = nullptr by def

        writer = writer->next; // order of traversal doesn't matter
        reader = reader->next;
    }
}
template<class T>
StackLinked<T>& StackLinked<T>::operator=(const StackLinked& rhs)
{
    if(this != &rhs) { // self-initialization check
        while(!this->isEmpty()) { this->pop(); } // destroy the stack

        // !rhs.top would also work, because nullptr returns false
        if(rhs.top == nullptr) { this->top = nullptr; }
        else {
            // make top new node w/ value rhs.top->value, next = nullptr
            this->top = new StackNode<T>(rhs.top->value);
            StackNode<T>* reader = rhs.top->next; // reader is top's next
            StackNode<T>* writer = this->top; // writer is this' top
            while(reader != nullptr) { // if not reached end of stack
                // writer's next is new node w/ value of reader
                writer->next = new StackNode<T>(reader->value);
                // writer->next->next = nullptr by def

                writer = writer->next; // order of traversal doesn't matter
                reader = reader->next;
            }
        } // rhs != nullptr
    } // if(this != &rhs)
    return *this;
} // copy assignment operator
template<class T> void StackLinked<T>::push(const T& value)
{
    // create new node with value value, and next this->top
    this->top = new StackNode<T>(value, this->top);
}
template<class T> T StackLinked<T>::pop()
{
    if(isEmpty()) {
        std::stringstream errStr;
        errStr << "StackException: Stack Empty on Pop" << std::endl;
        throw StackException(errStr);
    }
    else { // if not empty
        T retTop = this->top->value; // retTop is top's value
        StackNode<T>* tmp = this->top; // tmp points top
        this->top = this->top->next; // top changed to prev
        delete tmp; // top deleted
        return retTop; // retTop returned
    }
}
template<class T> T StackLinked<T>::peek() const
{
    if(isEmpty()) {
        std::stringstream errStr;
        errStr << "StackException: Stack Empty on Peek" << std::endl;
        throw StackException(errStr);
    }
    else { // if not empty
        return this->top->value; // return top value
    }
}
template<class T> void StackLinked<T>::print()
{
    StackLinked<T> backup;
    int index = 0;
    std::cout << "---v--- Top ---v---" << std::endl;
    while(!this->isEmpty()) {
        try {
            backup.push(this->peek());
            std::cout << this->pop();
            index++;
        }
        catch(StackException e) {
            break;
        }
        std::cout << std::endl;
    }
    std::cout << "--^-- Bottom --^--" << std::endl;
    backup.reverse();
    *this = backup;
}
template<class T> void StackLinked<T>::reverse()
{
    StackLinked<T> backup;
    while(!this->isEmpty()) {
        try {
            backup.push(this->pop());
        }
        catch(StackException e) {
            break;
        }
    }
    *this = backup;
}
template<class T> int StackLinked<T>::size() const
{
    StackNode<T>* tmp = this->top;
    if(tmp == nullptr) { return 0; }
    else {
        int retSize = 1;
        while(tmp->next != nullptr) {
            retSize++;
            tmp = tmp->next;
        }
        return retSize;
    }
}
template<class T> bool StackLinked<T>::isEmpty() const
{
    return this->top == nullptr;
}

#endif // _StackLinked_H_
// For Test Uses Only!
// Copy the rest to a different .cpp file!
// #include "StackLinked.h"
// #include <iostream>
//
// int main()
// {
//     // StackArray<int> intSt(5);
//     StackLinked<int> intSt;
//     intSt.push(1);
//     intSt.push(2);
//     intSt.push(3);
//     intSt.push(4);
//     intSt.push(5);
//
//     std::cout << "intSt Top: " << intSt.peek() << std::endl;
//     std::cout << "intSt Is Empty?: " << intSt.isEmpty() << std::endl;
//     // std::cout << "Is Full?: " << intSt.isFull() << std::endl;
//     // std::cout << "Size?: " << intSt.size() << std::endl;
//
//     // StackArray<int> intCopySt;
//     StackLinked<int> intCopySt;
//     intCopySt = intSt;
//     std::cout << "intSt Top by Peek?: " << intSt.peek() << std::endl;
//     while(!intSt.isEmpty()) {
//         try {
//             std::cout << "intSt Pop: " << intSt.pop();
//         }
//         catch(StackException e) {
//             break;
//         }
//         std::cout << std::endl;
//     }
//     // std::cout << "intSt Size?: " << intSt.size() << std::endl;
//     std::cout << "intSt Is Empty?: " << intSt.isEmpty() << std::endl;
//     // std::cout << "intCopySt Size?: " << intCopySt.size() << std::endl;
//     // std::cout << "Is Full?: " << intCopySt.isFull() << std::endl;
//     std::cout << "intCopySt (peek) Top: " << intCopySt.peek() << std::endl;
//     std::cout << "intCopySt (pop) Top: " << intCopySt.pop() << std::endl;
//     std::cout << "intCopySt Is Empty?: " << intCopySt.isEmpty() << std::endl;
//     // std::cout << "Is Full?: " << intCopySt.isFull() << std::endl;
//     StackLinked<int> intCopyConstSt = intCopySt;
//     std::cout << "intCopyConstSt Is Empty?: " << intCopyConstSt.isEmpty()
//               << std::endl;
//     std::cout << "intCopyConstSt (peek) Top: " << intCopyConstSt.peek()
//               << std::endl;
//     std::cout << "intCopyConstSt (pop) Top: " << intCopyConstSt.pop()
//               << std::endl;
//     std::cout << std::endl << "intCopyConstSt.print(): " << std::endl;
//     intCopyConstSt.print();
//     StackLinked<int> revTest = intCopySt;
//     std::cout << std::endl << "intCopySt.print(): " << std::endl;
//     intCopySt.print();
//     std::cout << std::endl << "revTest.print(): " << std::endl;
//     revTest.print();
//     revTest.reverse();
//     std::cout << std::endl
//               << "revTest.reverse();revTest.print();: " << std::endl;
//     revTest.print();
//     std::cout << "revTest (peek) Top: " << revTest.peek() << std::endl;
//     // std::cout << "intCopyConstSt Size?: " << intCopyConstSt.size() <<
//     // std::endl;
// }
