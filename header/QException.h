/* MIT License
 * Copyright (c) 2025 Emir Baha Yıldırım
 * Please see the LICENSE file for more details.
 *
 * ======== QException.h ========
 * This is the header QException.h defining a new exception for the Queue
 * implementation.
 */
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
