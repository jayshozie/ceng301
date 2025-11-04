#ifndef _Complex_H_
#define _Complex_H_

#include <iostream>
#include <math.h>
#include <sstream>
#include <stdexcept>

// TODO: TURN THIS INTO A TEMPLATE

class Complex {
private:
    float re, im; // by default private
public:
    Complex(float re = 0.0, float im = 0.0)
        : re(re), im(im) {} // default constructor
    // Complex operator=(const Complex& rhs) { // copy assignment operator
    //     this->re = rhs.re;
    //     this->im = rhs.im;
    //     return *this;
    // }
    ~Complex() {}
    Complex operator+(const Complex& rhs) const
    {
        Complex result;
        result.re = this->re + rhs.re;
        result.im = this->im + rhs.im;
        return result;
    }
    Complex operator-(const Complex& rhs) const
    {
        Complex result;
        result.re = this->re - rhs.re;
        result.im = this->im - rhs.im;
        return result;
    }
    Complex operator*(const Complex& rhs) const
    {
        Complex result;
        result.re = (this->re * rhs.re) + (this->im * rhs.im);
        result.im = (this->re * rhs.im) + (this->im * rhs.re);
        return result;
    }
    Complex operator/(const Complex& rhs) const
    {
        Complex result;
        float divider = (rhs.re * rhs.re) + (rhs.im * rhs.im);
        if(divider == 0) {
            std::stringstream errStr;
            errStr << "Division by zero -> " << divider << std::endl;
            throw std::logic_error(errStr.str());
        }
        float reDivident = (this->re * rhs.re) + (this->im * rhs.im);
        float imDivident = (this->im * rhs.re) - (this->re * rhs.im);
        result.re = reDivident / divider;
        result.im = imDivident / divider;
        return result;
    }
    float modulus() const
    {
        // distance of the point to the origin
        float sqrd_re = this->re * this->re;
        float sqrd_im = this->im * this->im;
        return std::sqrt(sqrd_re + sqrd_im);
    }
    float Re() const { return this->re; }
    float Im() const { return this->im; }
    void print() const
    {
        // char operator;
        // if (this->im < 0) {
        //     float temp_im = -1 * this->im;
        //     operator = '-';
        // }
        std::cout << '(' << this->re << ')' << " + " << 'i' << '(' << this->im
                  << ')' << std::endl;
    }
};

#endif
