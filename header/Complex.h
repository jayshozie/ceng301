// Complex.h
#ifndef _Complex_H_
#define _Complex_H_
#include <iostream>
#include <math.h>
#include <sstream>
#include <stdexcept>

template<class T> class Complex {
private:
    T re, im;
public:
    Complex(T re, T im): re(re), im(im) {}
    ~Complex();
    Complex operator+(const Complex& rhs) const;
    Complex operator-(const Complex& rhs) const;
    Complex operator*(const Complex& rhs) const;
    Complex operator/(const Complex& rhs) const;
    T modulus() const;
    T Re() const;
    T Im() const;
    void print() const;
};

template<class T> Complex<T> Complex<T>::operator+(const Complex<T>& rhs) const
{
    Complex<T> result;
    result.re = this->re + rhs.re;
    result.im = this->im + rhs.im;
    return result;
}
template<class T> Complex<T> Complex<T>::operator-(const Complex<T>& rhs) const
{
    Complex<T> result;
    result.re = this->re - rhs.re;
    result.im = this->im - rhs.im;
    return result;
}
template<class T> Complex<T> Complex<T>::operator*(const Complex& rhs) const
{
    Complex<T> result;
    result.re = (this->re * rhs.re) + (this->im * rhs.im);
    result.im = (this->re * rhs.im) + (this->im * rhs.re);
    return result;
}
template<class T> Complex<T> Complex<T>::operator/(const Complex& rhs) const
{
    Complex<T> result;
    T divider = (rhs.re * rhs.re) + (rhs.im * rhs.im);
    if(divider == 0) {
        std::stringstream errStr;
        errStr << "Division by zero -> " << divider << std::endl;
        throw std::logic_error(errStr.str());
    }
    T reDividend = (this->re * rhs.re) + (this->im * rhs.im);
    T imDividend = (this->im * rhs.re) - (this->re * rhs.im);
    result.re = reDividend / divider;
    result.im = imDividend / divider;
    return result;
}
template<class T> T Complex<T>::modulus() const
{
    T sqrd_re = this->re * this->re;
    T sqrd_im = this->im * this->im;
    return std::sqrt(sqrd_re + sqrd_im);
}
template<class T> T Complex<T>::Re() const
{
    return this->re;
}
template<class T> T Complex<T>::Im() const
{
    return this->im;
}
template<class T> void Complex<T>::print() const
{
    std::cout << '(' << this->re << ')' << " + " << 'i' << '(' << this->im
              << ')' << std::endl;
}

#endif // _Complex_H_
