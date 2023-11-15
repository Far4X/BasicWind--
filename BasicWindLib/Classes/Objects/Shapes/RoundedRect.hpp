#ifndef BWRORECT_HPP
#define BWRORECT_HPP

#include "Rect.hpp"

class RoundedRect : public Rect{
public :
    RoundedRect(Shape *m_parent, float pos[2], float ellipse_round[2], float size[2]);
    RoundedRect(Shape *m_parent, float pos[2], float ellipse_round[2], float size[2], float color[3]);
    ~RoundedRect();

    void drawShape();
    void updateShape();

private :
    float m_size[2];
    float m_rnd_size[2];
    D2D1_ROUNDED_RECT m_rorect;
};

#endif