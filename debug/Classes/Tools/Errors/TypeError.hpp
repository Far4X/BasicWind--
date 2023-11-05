#ifndef BWTYPEERROR_HPP
#define BWTYPEERROR_HPP

#include "Error.cpp"
#include <string>

class TypeError : public Error{
public :
    TypeError(int code);
    TypeError(int code, std::string message);
    TypeError(TypeError &source)
    std::string getMessage();

private :
    std::string m_message;
}

#endif