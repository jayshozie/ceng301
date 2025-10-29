#include <iostream>
#include <cmath>
#include "testBench.h"

Complex Complex::operator*(const Complex& rhs) const {
    Complex prod;
    prod.re = (re*rhs.re - im*rhs.im);
    prod.im = (re*rhs.im - im*rhs.re);
    return prod;
}
float Complex::modulus() const {
    return sqrt(re*re + im*im);
}
void Complex::print() const {
    std::cout << '(' << re << ',' << im << ')' << std::endl;
}

int main()
{
    Complex c1, c2(2,3), c3(1,2);

    c1 = c2 * c3;
    c1.print();
}
