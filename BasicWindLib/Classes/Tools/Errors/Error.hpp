#ifndef BWERROR_HPP
#define BWERROR_HPP

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