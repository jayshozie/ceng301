#include <iostream>

int main()
{
    int a, b, *p;

    a = b = 7;
    p = &a;
    // 1st print statement
    std::cout << "*p = " << *p << std::endl;
    std::cout << "p (pointer to a) = " << p << std::endl;

    *p = 3; // changes the value of a to 3, because p points to a.
    // 2nd print statement
    std::cout << "a = " << a << std::endl;

    p = &b;

    *p = 2 * *p - a;
    // 3rd print statement
    std::cout << "b = " << b << std::endl;
}
