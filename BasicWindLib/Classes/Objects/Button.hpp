#ifndef BW_BUTTON_HPP
#define BW_BUTTON_HPP

#include "Shapes/Rect.hpp"
#include <functional>


class Button : public Rect {
public :
    Button(Shape *m_parent, float pos[2], float size[2], float color[3], std::function<void(void)> function);
    ~Button();
    void isOverflyed();
    void isClickedOn();

private :
    std::function<void(void)> m_function;
    bool m_change_color_when_overflyed;
};

#endif