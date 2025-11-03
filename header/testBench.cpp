#include "Complex.h"

int main()
{
    Complex a(3.14, 7.24);
    Complex b(2.71, 1.41);

    a.print();
    b.print();
    std::cout << a.modulus() << std::endl;
    Complex d;
    d = a + b;
    d.print();
    d = a - b;
    d.print();
    d = a * b;
    d.print();
    d = a / b;
    d.print();
}
