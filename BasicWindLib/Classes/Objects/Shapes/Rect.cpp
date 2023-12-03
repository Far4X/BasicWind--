#include "Rect.hpp"
#include <iostream>

Rect::Rect(Shape *parent, float pos[2], float size[2], float color[3]) : Shape(parent, pos, color){
    m_size[0] = size[0];
    m_size[1] = size[1];
    this->updateShape();
}

Rect::Rect(Shape *parent, float pos[2], float size[2]) : Shape(parent, pos){
    m_size[0] = size[0];
    m_size[1] = size[1];
    this->updateShape();
}

Rect::~Rect(){
    
}

void Rect::drawShape(){
    m_parent->getRenderTarget()->FillRectangle(&m_rect, m_brush);
}

void Rect::updateShape(){
    m_rect = D2D1::RectF(m_pos[0], m_pos[1], m_pos[0] + m_size[0], m_pos[1] + m_size[1]);
}

void Rect::detectClick(int pos[2]){
    if (pos[0] >= m_pos[0] && pos[1] >= m_pos[1] && pos[0] <= m_pos[0] + m_size[0] && pos[1] <= m_pos[1] + m_size[1]){
        this->isClickedOn();
    }
    for (int i = 0; i < m_list_shapes.size(); i++){
        m_list_shapes[i]->detectClick(pos);
    }
}

void Rect::isOverflyed(int pos[2]){
    for (int i = 0; i < m_list_shapes.size(); i++){
        m_list_shapes[i]->isOverflyed(pos);
    }
}