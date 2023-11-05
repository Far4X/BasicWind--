#include "Error.hpp"

Error::Error(int code){
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