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
    // const, because you don't want the function to be able to change the
    // string provided in the argument, noexcept because this function itself
    // is the exception, it shouldn't cause any exception itself, and override
    // because the when you inherit std::exception, you already have a function
    // called `what()` and you need to override the default one.
};

#endif
