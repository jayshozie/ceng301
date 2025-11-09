#ifndef _StackListADT_H_
#define _StackListADT_H_
#include "LinkedList.h"
#include "StackException.h"

template<class T> class StackListADT {
private:
    LinkedList<T> list;
public:
    void push(const T& item);
    T& pop();
    T& peek() const;
    bool isEmpty() const;
};

template<class T> void StackListADT<T>::push(const T& item)
{
    this->list.add(item);
}
template<class T> T& StackListADT<T>::pop()
{
    this->list.lookup_index(-1);
    this->list.remove_index(-1);
}
template<class T> T& StackListADT<T>::peek() const
{
    this->list.lookup_index(-1);
}
template<class T> bool StackListADT<T>::isEmpty() const
{
    return this->list.isEmpty();
}

#endif
