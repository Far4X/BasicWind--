#ifndef BWTYPEERROR_HPP
#define BWTYPEERROR_HPP

class Error{
public :
    Error(int code);
    Error(const Error &source);
    ~Error();
    int getCode();

private :
    int m_code;
};

#endif