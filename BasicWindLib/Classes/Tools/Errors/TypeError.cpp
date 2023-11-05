#include "TypeError.hpp"

TypeError::TypeError(int code, std::string message) : Error(code){
    m_message = message;
}

TypeError::TypeError(int code) : Error(code){
    m_message = "";
}

TypeError::TypeError(TypeError &source) Error(source.m_code){
    m_message = source.m_message();
}

std::string getMessage(){
    return m_message;
}