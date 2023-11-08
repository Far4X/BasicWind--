#ifndef BWSHAPE_HPP
#define BWSHAPE_HPP

#include <d2d1.h>
#include "../../Tools/Errors/TypeError.hpp"
#include "../../Tools/Errors/Error.hpp"


class Shape{
public :
    Shape();
    Shape(Shape *parent, float pos[2]);
    Shape(Shape *parent, float pos[2], float color[3]);

    ~Shape();

    virtual void drawShape();
    float* getColor();
    float* getPos();
    void setPos(float pos[2]);
    void setColor(int color[3]);
    virtual void updateShape();
    void updateBrush();
    virtual const HWND getHandler();
    virtual ID2D1HwndRenderTarget* getRenderTarget();

protected :
    float m_pos[2];
    float m_color[3];
    Shape *m_parent;
    ID2D1SolidColorBrush *m_brush;

};

#endif