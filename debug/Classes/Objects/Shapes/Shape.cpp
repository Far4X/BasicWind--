#include "shape.hpp"
#include "../../Tools/Errors/TypeError.hpp"



Shape::Shape(Window *parent){
    m_parent = parent;
    for (int i = 0; i < 3; i++){
        m_color[i] = 0;
    }
}

Shape::Shape(Window *parent, int *color[3]){
    m_parent = parent;
    for (int i = 0; i < 3; i++){
        m_color[i] = *color[i];
    }
}

Shape::~Shape(){
    m_parent = nullptr;
}

int* Shape::getColor(){
    return m_color;
}

void Shape::drawShape(){
    throw TypeError(3, "Shape Can't draw Shape; it's a virtual class");
}


