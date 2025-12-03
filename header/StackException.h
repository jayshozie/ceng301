// StackException.h
#ifndef _StackException_H_
#define _StackException_H_
#include <sstream>
#include <stdexcept>

class StackException : public std::exception {
private:
    std::string errStr;
public:
    StackException(const std::stringstream& string): errStr(string.str()) {}
    const char* what() const noexcept override { return errStr.c_str(); }
    // In c++, to actually create your own exception class, you have to inherit
    // from std::exception, and after that inheritance, you should create a
    // member function called `what()` with return type `const char*`, and that
    // function should have the properties `const`, `noexcept`, `override`.
    //
    // - const: Guarantees that the function will NOT change any data members
    //          of the exception object (like `errStr`). Since `what()` is
    //          only meant to read the error message, this enforces safety.
    // - noexcept: Because this function itself is the exception reporter,
    //             it should never throw an exception itself.
    // - override: Because when you inherit std::exception, you already have a
    //             virtual function called `what()`, and you must override
    //             the default one to provide your custom message.
};

#endif // _StackException_H_
