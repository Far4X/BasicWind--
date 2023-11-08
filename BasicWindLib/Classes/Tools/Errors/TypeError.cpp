#include "TypeError.hpp"
#include <iostream>

TypeError::TypeError(int code, std::string message) : Error(code){
    std::cout << "TypeError : " << message << std::endl;
    m_message = message;
}

TypeError::TypeError(int code) : Error(code){
    m_message = "";
}

TypeError::TypeError(TypeError &source) : Error(source.getCode()){
    m_message = source.getMessage();
}

std::string TypeError::getMessage(){
    return m_message;
}