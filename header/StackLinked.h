// StackLinked.h
#ifndef _StackLinked_H_
#define _StackLinked_H_
#include "StackException.h"
#include <iostream>

template<class T> class StackNode { // backwards because stack
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
    int size() const;
    bool isEmpty() const;
    // definitions
};

template<class T> StackLinked<T>::StackLinked()
    : top(nullptr) {} // default constructor
template<class T> StackLinked<T>::~StackLinked()
{
    while(!this->isEmpty()) { this->pop(); }
}
template<class T> StackLinked<T>::StackLinked(const StackLinked& rhs)
    : top(nullptr)
{ // copy constructor
    if(rhs.top == nullptr) { return; }
    this->top = new StackNode<T>(rhs.top->value);
    StackNode<T>* reader = rhs.top->next;
    StackNode<T>* writer = this->top;
    while(reader) {
        writer->next = new StackNode<T>(reader->value);
        writer = writer->next;
        reader = reader->next;
    }
}
template<class T>
StackLinked<T>& StackLinked<T>::operator=(const StackLinked& rhs)
{
    if(this != &rhs) {
        while(!this->isEmpty()) { this->pop(); }

        // !rhs.top would also work, because nullptr returns false
        if(rhs.top == nullptr) { this->top = nullptr; }
        else {
            // make top new node w/ value rhs.top->value, next = nullptr
            this->top = new StackNode<T>(rhs.top->value);
            StackNode<T>* reader = rhs.top->next; // reader is top's next
            StackNode<T>* writer = this->top; // writer is this' top
            while(reader) { // nullptr returns false
                // writer's next is new node w/ value reader, next nullptr
                writer->next = new StackNode<T>(reader->value);

                writer = writer->next; // traverse
                reader = reader->next; // traverse
            }
        } // rhs != nullptr
    } // if(this != &rhs)
    return *this;
}
template<class T> void StackLinked<T>::push(const T& value)
{
    // create new node
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

#endif
