#include "TextHandler.hpp"
#include "Errors/TypeError.hpp"

TextHandler::TextHandler(float pos[2], std::string text){
    m_position[0] = pos[0];
    m_position[1] = pos[1];
    m_text = text;
}

TextHandler::TextHandler(){
}

TextHandler::~TextHandler(){

}

void TextHandler::setText(std::string &text){
    m_text = text;
}

void TextHandler::print(HDC &target_hdc){
    TextOut(target_hdc, m_position[0], m_position[1], LPCSTR(m_text.c_str()), m_text.size());
}

float TextHandler::getX(){
    return m_position[0];
}

float TextHandler::getY(){
    return m_position[1];
}

std::string TextHandler::getText(){
    return m_text;
}

int TextHandler::getNumChar(){
    return m_text.size();
}

HFONT TextHandler::getHFont(){
    return m_font;
}