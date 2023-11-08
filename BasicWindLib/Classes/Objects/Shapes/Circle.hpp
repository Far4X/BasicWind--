#ifndef BWCIRCLE_HPP
#define BWCIRCLE_HPP

#include "Shape.hpp"

class Circle : public Shape{
public :
    Circle(Shape *m_parent, float pos[2], float radius);
    Circle(Shape *m_parent, float pos[2], float radius, float color[3]);
    ~Circle();

    void drawShape();
    void updateShape();

private :
    float m_radius;
    D2D1_ELLIPSE m_ellipse;
};

#endif