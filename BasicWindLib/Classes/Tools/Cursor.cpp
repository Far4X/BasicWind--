#include "Cursor.hpp"

Cursor::Cursor(int pos[2]){
    m_pos[0] = pos[0];
    m_pos[1] = pos[1];
}

Cursor::Cursor(){
    m_pos[0] = 0;
    m_pos[1] = 0;
}

Cursor::~Cursor(){

}

int* Cursor::getPosition(){
    return m_pos;
}

int Cursor::getX(){
    return m_pos[0];
}

int Cursor::getY(){
    return m_pos[1];
}

void Cursor::updatePosition(const int pos[2]){
    m_pos[0] = pos[0];
    m_pos[1] = pos[1];
}