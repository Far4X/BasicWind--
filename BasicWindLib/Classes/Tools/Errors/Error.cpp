#include "Error.hpp"
#include <iostream>


Error::Error(int code){
    std::cout << "Error" << std::endl;    
    m_code = code;
}

Error::Error(const Error &source){
    m_code = source.m_code;
}

Error::~Error(){

}

int Error::getCode(){
    return m_code;
}