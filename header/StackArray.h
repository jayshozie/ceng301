// StackArray.h
#ifndef _StackArray_H_
#define _StackArray_H_
#include "StackException.h"

template<class T> class StackArray {
private:
    int top;
    int capacity;
    T* items;
public:
    StackArray(int cap = 0); // default constructor
    ~StackArray(); // destructor
    StackArray(const StackArray& rhs); // copy constructor
    StackArray& operator=(const StackArray& rhs); // copy assignment operator
    void push(const T& item);
    T pop();
    T peek() const;
    int size() const;
    bool isEmpty() const;
    bool isFull() const;
}; // definitions

template<class T> StackArray<T>::StackArray(int cap)
    : capacity(cap), items(new T[this->capacity]), top(-1)
{}
template<class T> StackArray<T>::~StackArray()
{
    delete[] this->items;
    this->capacity = 0;
    this->top = -1;
}
template<class T> StackArray<T>::StackArray(const StackArray<T>& rhs)
    : capacity(rhs.capacity), items(new T[rhs.capacity]), top(rhs.top)
{
    for(int i = 0; i <= this->top; i++) { this->items[i] = rhs.items[i]; }
}
template<class T> StackArray<T>& StackArray<T>::operator=(const StackArray<T>& rhs)
{
    if (this != &rhs) {
        if (this->capacity != rhs.capacity) {
            delete[] this->items;
            this->capacity = rhs.capacity;
            this->items = new T[this->capacity];
        }
        this->top = rhs.top;
        for (int i = 0; i <= this->top; i++) {
            this->items[i] = rhs.items[i];
        }
    }
    return *this;
}

template<class T> void StackArray<T>::push(const T& item)
{
    if(this->top == this->capacity - 1) {
        std::stringstream errStr;
        errStr << "Stack overflow." << std::endl;
        throw StackException(errStr);
    }
    // increase the value of top by 1, add the item to items[]
    this->items[++this->top] = item;
}

template<class T> T StackArray<T>::pop()
{
    if(this->top == -1) {
        std::stringstream errStr;
        errStr << "Stack underflow." << std::endl;
        throw StackException(errStr);
    }
    return this->items[this->top--];
}

template<class T> T StackArray<T>::peek() const
{
    if(this->top == -1) {
        std::stringstream errStr;
        errStr << "Stack is Empty." << std::endl;
        throw StackException(errStr);
    }
    return this->items[this->top];
}

template<class T> int StackArray<T>::size() const
{
    return this->top + 1;
}

template<class T> bool StackArray<T>::isEmpty() const
{
    return this->top == -1;
}

template<class T> bool StackArray<T>::isFull() const
{
    return this->top == this->capacity - 1;
}

#endif
