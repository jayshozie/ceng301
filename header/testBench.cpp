#include "LinkedList.h"
#include "QException.h"

// TODO: IMPLEMENT AFTER MT

template<class T> class Queue {
private:
    LinkedList<T>* q;
public:
    Queue();
    ~Queue();
    Queue(const Queue& rhs);
    Queue& operator=(const Queue& rhs);

    void enqueue(const T& value);
    T dequeue(); // seconds as pop()
    T peek();
    int size() const;
    bool isEmpty() const;
};

template<class T> Queue<T>::Queue() {}
template<class T> Queue<T>::~Queue() {}
template<class T> Queue<T>::Queue(const Queue<T>& rhs) {}
template<class T> Queue<T>& Queue<T>::operator=(const Queue<T>& rhs) {}

template<class T> void Queue<T>::enqueue(const T& value) {}
template<class T> T Queue<T>::dequeue() {}
template<class T> T Queue<T>::peek() {}
template<class T> int Queue<T>::size() const {}
template<class T> bool Queue<T>::isEmpty() const {}
