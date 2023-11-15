#ifndef BWRECT_HPP
#define BWRECT_HPP

#include "Shape.hpp"

class Rect : public Shape{
public :
    Rect(Shape *m_parent, float pos[2], float size[2]);
    Rect(Shape *m_parent, float pos[2], float size[2], float color[3]);
    ~Rect();

    void drawShape();
    void updateShape();
    void dectectClick(float pos[2]);

protected :
    float m_size[2];
    D2D1_RECT_F m_rect;
};

#endif