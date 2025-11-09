#include "Complex.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include "StackArray.h"
#include "StackLinked.h"
#include <iostream>

int main()
{
    // StackArray<int> intSt(5);
    StackLinked<int> intSt;
    intSt.push(1);
    intSt.push(2);
    intSt.push(3);
    intSt.push(4);
    intSt.push(5);

    std::cout << "intSt Top: " << intSt.peek() << std::endl;
    std::cout << "intSt Is Empty?: " << intSt.isEmpty() << std::endl;
    // std::cout << "Is Full?: " << intSt.isFull() << std::endl;
    // std::cout << "Size?: " << intSt.size() << std::endl;

    // StackArray<int> intCopySt;
    StackLinked<int> intCopySt;
    intCopySt = intSt;
    std::cout << "intSt Top by Peek?: " << intSt.peek() << std::endl;
    while(!intSt.isEmpty()) {
        try {
            std::cout << "intSt Pop: " << intSt.pop();
        }
        catch(StackException e) {
            break;
        }
        std::cout << std::endl;
    }
    // std::cout << "intSt Size?: " << intSt.size() << std::endl;
    std::cout << "intSt Is Empty?: " << intSt.isEmpty() << std::endl;
    // std::cout << "intCopySt Size?: " << intCopySt.size() << std::endl;
    // std::cout << "Is Full?: " << intCopySt.isFull() << std::endl;
    std::cout << "intCopySt (peek) Top: " << intCopySt.peek() << std::endl;
    std::cout << "intCopySt (pop) Top: " << intCopySt.pop() << std::endl;
    std::cout << "intCopySt Is Empty?: " << intCopySt.isEmpty() << std::endl;
    // std::cout << "Is Full?: " << intCopySt.isFull() << std::endl;
    StackLinked<int> intCopyConstSt = intCopySt;
    std::cout << "intCopyConstSt Is Empty?: " << intCopyConstSt.isEmpty()
              << std::endl;
    std::cout << "intCopyConstSt (peek) Top: " << intCopyConstSt.peek()
              << std::endl;
    std::cout << "intCopyConstSt (pop) Top: " << intCopyConstSt.pop()
              << std::endl;
    while(!intCopyConstSt.isEmpty()) {
        try {
            std::cout << "intCopyConstSt Pop: " << intCopyConstSt.pop();
        }
        catch(StackException e) {
            break;
        }
        std::cout << std::endl;
    }
    // std::cout << "intCopyConstSt Size?: " << intCopyConstSt.size() <<
    // std::endl;
}
