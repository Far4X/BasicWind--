#ifndef BWSHAPE_HPP
#define BWSHAPE_HPP

#include <d2d1.h>
#include <vector>
#include "../../Tools/Errors/TypeError.hpp"
#include "../../Tools/Errors/Error.hpp"
#include "../../Tools/TextHandler.hpp"


// Virtual Root of all graphic component. handle every generic parameter such as position, color...


class Shape{
public :
    Shape();
    Shape(Shape *parent, float pos[2]);
    Shape(Shape *parent, float pos[2], float color[3]);

    ~Shape();

    virtual void drawShape(std::vector<TextHandler*> &list_text_handler);
    virtual void drawShape();
    float* getColor();
    float* getPos();
    void setPos(float pos[2]);
    void setColor(float color[3]);
    virtual void updateShape();
    void updateBrush();
    virtual const HWND getHandler();
    virtual ID2D1HwndRenderTarget* getRenderTarget();
    void addShapeToDraw(Shape *new_shape);
    virtual void detectClick(int pos[2]);
    virtual void isClickedOn();
    virtual void isOverflyed(int pos[2]);
    Shape* getWindow();
    Shape* getParent();
    HDC* getHDC();

    ID2D1SolidColorBrush *m_brush;
    std::vector<Shape*> m_list_shapes;

protected :
    float m_pos[2];
    float m_color[3];
    Shape *m_parent;
    HDC *m_hdc;
    

};

#endif