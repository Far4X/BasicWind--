#include "TextRect.hpp"
#include <iostream>

TextRect::TextRect(Shape* parent, float pos[2], float size[2], float color[3], std::string& text) : Rect(parent, pos, size, color){
    m_text = std::string(text);
    m_text_handler = TextHandler(m_pos, text);
}

TextRect::~TextRect(){
}

void TextRect::drawShape(std::vector<TextHandler*> &list_text_handler){
    Rect::drawShape(list_text_handler);
    list_text_handler.push_back(&m_text_handler);    
}

void TextRect::setText(std::string text){
    m_text = text;
}