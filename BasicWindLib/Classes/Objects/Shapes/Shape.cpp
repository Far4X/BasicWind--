#include "Shape.hpp"
#include <iostream>


Shape::Shape(){
    m_parent = nullptr;
}

Shape::Shape(Shape *parent, float pos[2]){
    m_parent = parent;
    for (int i = 0; i < 3; i++){
        m_color[i] = 0;
    }
    for (int i = 0; i < 2; i++){
        m_pos[i] = pos[i];
    }
    this->updateBrush();
}

Shape::Shape(Shape *parent, float pos[2], float color[3]){
    m_parent = parent;
    for (int i = 0; i < 3; i++){
        m_color[i] = color[i];
    }
    for (int i = 0; i < 2; i++){
        m_pos[i] = pos[i];
    }
    this->updateBrush();
}

Shape::~Shape(){
    m_brush->Release();
    m_parent = nullptr;
}

float* Shape::getColor(){
    return m_color;
}

float* Shape::getPos(){
    return m_pos;
}

void Shape::setColor(int color[3]){
    for (int i = 0; i < 3; i++){
        m_color[i] = color[i];
    }
    this->updateBrush();
}

void Shape::updateBrush(){
    const D2D1_COLOR_F colorb = D2D1::ColorF(float(m_color[0]), float(m_color[1]), float(m_color[2]));
    if (this->m_parent->getRenderTarget() != nullptr) {
        HRESULT res = this->m_parent->getRenderTarget()->CreateSolidColorBrush(colorb, &m_brush);
        if (FAILED(res)){
            throw Error(5);
        }
    }
    
}

void Shape::setPos(float pos[3]){
    for (int i = 0; i < 3; i++){
        m_pos[i] = pos[i];
    }
    this->updateShape();
}

void Shape::drawShape(){
    throw TypeError(3, "Shape can't drawShape; it's a virtual class");
}

void Shape::updateShape(){
    throw TypeError(3, "Shape can't updateShape; it's a virtual class");
}

const HWND Shape::getHandler(){
    throw TypeError(4, "Shape has no handler");
    return NULL;
}

ID2D1HwndRenderTarget* Shape::getRenderTarget(){
    throw TypeError(6, "Shape has no render target");
    return NULL;
}
