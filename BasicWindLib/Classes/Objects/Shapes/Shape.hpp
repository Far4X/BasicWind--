#ifndef BWSHAPE_HPP
#define BWSHAPE_HPP

#include "../Window.hpp"

class Shape{
public :
    Shape(Window* m_parent);
    Shape(Window* m_parent, int *color[3]);

    ~Shape();

    virtual void drawShape();
    int* getColor();

private :
    float m_pos[2];
    int m_color[3];
    Window* m_parent;

};

#endif