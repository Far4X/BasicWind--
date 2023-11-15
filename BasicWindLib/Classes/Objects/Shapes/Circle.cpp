#include "Circle.hpp"
#include <iostream>

Circle::Circle(Shape *parent, float pos[2], float radius, float color[3]) : Shape(parent, pos, color){
    m_radius = radius;
    this->updateShape();
}

Circle::Circle(Shape *parent, float pos[2], float radius) : Shape(parent, pos){
    m_radius = radius;
    this->updateShape();
}

Circle::~Circle(){

}

void Circle::drawShape(){
    m_parent->getRenderTarget()->FillEllipse(m_ellipse, m_brush);
}

void Circle::updateShape(){
    m_ellipse = D2D1::Ellipse(D2D1::Point2F(m_pos[0], m_pos[1]), m_radius, m_radius);
}