#ifndef _TestBench_H_
#define _TestBench_H_

class Complex
{
    float re, im; // by default private

public:
    Complex(float x=0, float y=0) : re(x), im(y) { }
    Complex operator*(const Complex& rhs) const;
    float modulus() const;
    void print() const;
};

#endif
