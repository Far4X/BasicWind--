#include "RoundedRect.hpp"

RoundedRect::RoundedRect(Shape *parent, float pos[2], float size[2], float ellipse_round[2], float color[3]) : Rect(parent, pos, size, color){
    m_rnd_size[0] = ellipse_round[0];
    m_rnd_size[1] = ellipse_round[1];
    this->updateShape();
}

RoundedRect::RoundedRect(Shape *parent, float pos[2], float ellipse_round[2], float size[2]) : Rect(parent, pos, size){
    m_rnd_size[0] = ellipse_round[0];
    m_rnd_size[1] = ellipse_round[1];
    this->updateShape();
}

RoundedRect::~RoundedRect(){
    
}

void RoundedRect::drawShape(TextHandler &text_handler){
    m_parent->getRenderTarget()->FillRoundedRectangle(&m_rorect, m_brush);
}

void RoundedRect::drawShape(){
    m_parent->getRenderTarget()->FillRoundedRectangle(&m_rorect, m_brush);
}

void RoundedRect::updateShape(){
    m_rorect = D2D1::RoundedRect(m_rect, m_rnd_size[0], m_rnd_size[1]);
}
