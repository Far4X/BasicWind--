#ifndef TEXTRECTWPP_HPP
#define TEXTRECTWPP_HPP

#include "shapes/Rect.hpp"
#include <string>
#include "../Tools/TextHandler.hpp"

class TextRect : public Rect {
private:
    std::string m_text;
    TextHandler m_text_handler;
public:
    TextRect(Shape *parent, float pos[2], float size[2], float color[3], std::string& text);
    ~TextRect();
    void setText(std::string new_text);
    void drawShape(std::vector<TextHandler*> &list_text_handler);
};


#endif