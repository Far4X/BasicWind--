#include "Circle.hpp"
#include "math.h"
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

void Circle::drawShape(std::vector<TextHandler*> &list_text_handler){
    m_parent->getRenderTarget()->FillEllipse(m_ellipse, m_brush);
}

void Circle::drawShape(){
    m_parent->getRenderTarget()->FillEllipse(m_ellipse, m_brush);
}

void Circle::updateShape(){
    m_ellipse = D2D1::Ellipse(D2D1::Point2F(m_pos[0], m_pos[1]), m_radius, m_radius);
}

void Circle::detectClick(int pos[2]){
    if ((std::pow((pos[0] - m_pos[0]), 2) + (std::pow((pos[1] - m_pos[1]), 2))) <= m_radius^2){
        this->isClickedOn();
        std::cout << "Here DC" << std::endl;
    }
    for (int i = 0; i < m_list_shapes.size(); i++){
        std::cout << "In circle" << std::endl;
        m_list_shapes[i]->detectClick(pos);
    }
}