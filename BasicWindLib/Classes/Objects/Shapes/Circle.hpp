#ifndef BWCIRCLE_HPP
#define BWCIRCLE_HPP

#include "../Window.hpp"
#include "Shape.hpp"

class Circle : public Shape{
public :
    Circle();
    ~Circle();

    void drawShape()

private :
    float m_radius;
};

#endif