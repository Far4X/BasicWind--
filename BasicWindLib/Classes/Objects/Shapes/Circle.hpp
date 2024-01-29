#ifndef BWCIRCLE_HPP
#define BWCIRCLE_HPP

#include "Shape.hpp"

class Circle : public Shape{
public :
    Circle(Shape *m_parent, float pos[2], float radius);
    Circle(Shape *m_parent, float pos[2], float radius, float color[3]);
    ~Circle();

    void drawShape(std::vector<TextHandler*> &list_text_handler);
    void drawShape();
    void updateShape();
    void detectClick(int pos[2]);

private :
    float m_radius;
    D2D1_ELLIPSE m_ellipse;
};

#endif