#include "Button.hpp"
#include "iostream"

Button::Button(Shape *m_parent, float pos[2], float size[2], float color[3], std::function<void(void)> function) : Rect(m_parent, pos, size, color) {
    m_change_color_when_overflyed = true;
    m_function = function;
}

Button::~Button(){

}

void Button::isClickedOn(){
    float new_color[3] = {255, 0, 0};
    this->setColor(new_color);
    this->getWindow()->OnPaint();
    m_function();
}