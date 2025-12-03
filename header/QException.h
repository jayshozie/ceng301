#ifndef _QEXCEPTION_H_
#define _QEXCEPTION_H_
#include <sstream>
#include <stdexcept>

class QException : public std::exception {
private:
    std::string errStr;
public:
    QException(const std::stringstream& string): errStr(string.str()) {}
    const char* what() const noexcept override { return errStr.c_str(); }
};

#endif // _QEXCEPTION_H_
